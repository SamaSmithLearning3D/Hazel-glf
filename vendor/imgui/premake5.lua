project "ImGui"
   kind "StaticLib"
   language "C++"
   cppdialect"C++17"
   staticruntime "on" 

   targetdir ("bin/"..outputdir.."/%{prj.name}")
   objdir ("bin-int/"..outputdir.."/%{prj.name}")
 
   files
   {
      "imconfig.h",
      "imgui.h",
      "imgui.cpp",
      "imgui_draw.cpp",
      "imgui_internal.h",
      "imgui_widgets.cpp",
      "imstb_rectpack.h",
      "imstb_textedit.h",
      "imstb_truetype.h",
      "imgui_demo.cpp",
      "imgui_tables.cpp",
      "backends/imgui_impl_opengl3.h",
      "backends/imgui_impl_opengl3.cpp",-- 
      "backends/imgui_impl_glfw.h",     -- GLFW
      "backends/imgui_impl_glfw.cpp"     -- GLFW
   }
   includedirs
   {
         "backends"
   }
   
   filter "system:windows"
      systemversion "10.0.22621.0"
        
   filter "configurations:Debug"
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      runtime "Release"
      optimize "on"