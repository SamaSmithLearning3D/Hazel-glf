workspace "Hazel"
     architecture "x64"
     buildoptions "/utf-8"
     startproject "HazelNut"
     configurations
     {
         "Debug",
         "Release",
         "Dist"
     }

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--Include directories to root folder(solution directory)
IncludeDir={}

IncludeDir["GLFW"]="vendor/GLFW/include"
IncludeDir["Glad"]="vendor/Glad/include"
IncludeDir["ImGui"]="vendor/imgui" --/backends
IncludeDir["glm"]="vendor/glm"
IncludeDir["stb_image"]="vendor/stb_image"
IncludeDir["entt"]="vendor/entt/include"

group "Dependencies"
     include "vendor/GLFW"
     include "vendor/Glad"
     include "vendor/imgui"
--include"D:/dev/Hazel/vendor/GLFW"
group ""

project "Hazel"
    location "Hazel"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    cppdialect "C++17"

    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Hazel/src/hzpch.cpp"
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vender/stb_image/**.h",
        "%{prj.name}/vender/stb_image/**.cpp",
        "%{prj.name}/vender/glm/**.cpp",
        "%{prj.name}/vender/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/src/Hazel",
        "%{prj.name}/src/Platform",
        "vendor/spdlog",
        "vendor",
        "src/Platform",
        "src/Hazel",
        "vendor/GLFW",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}"
    }
 
     dependson { "ImGui" } 
    links{
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    

    filter "system:windows"
        systemversion "latest"--10.0.22621.0

        defines
        {
           "HZ_PLATFORM_WINDOWS",
           "HZ_BUILD_DLL",
           --"FMT_HEADER_ONLY"
           "GLFW_INCLUDE_NONE"
        }
     
        filter "configurations:Debug"
            defines "HZ_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HZ_DIST"
            runtime "Release"
            optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp" 
    language "C++"
    cppdialect "C++17"  
    staticruntime "on"

    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "vendor",
        "vendor/spdlog",
        "Hazel/src",
        "Hazel/src/Hazel",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}"
 
    }

    links
    {
        "Hazel"
    }
    filter "system:windows"     
        systemversion "latest"

        

        defines
        {
           "HZ_PLATFORM_WINDOWS",
           "FMT_HEADER_ONLY"
        }

         

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HZ_DIST"
            runtime "Release"
            optimize "on"

            
project "HazelNut"
    location "HazelNut"
    kind "ConsoleApp" 
    language "C++"
    cppdialect "C++17"  
    staticruntime "on"

    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "vendor",
        "vendor/spdlog",
        "Hazel/src",
        "Hazel/src/Hazel",
        "vendor/glm",
        "%{IncludeDir.entt}"
 
    }

    links
    {
        "Hazel"
    }
    filter "system:windows"     
        systemversion "latest"

        

        defines
        {
           "HZ_PLATFORM_WINDOWS",
           "FMT_HEADER_ONLY"
        }

         

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HZ_DIST"
            runtime "Release"
            optimize "on"