//2025-5-7：重新下载imgui，找到了 dear imgui, v1.91.1 WIP，并有docking解决了没法子窗口停靠的问题

#include "hzpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"//可能需要imgui的1.76版本
//不是需要1.76版本，而是需要docking分支上下载才有停靠功能

//#define IMGUI_IMPL_API
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Core/Application.h"

//TEMPORARY
#include "GLAD\glad.h"
#include "glfw3.h"

namespace Hazel {
Hazel::ImGuiLayer::ImGuiLayer()
	:Layer("ImGuiLayer")
{
}
Hazel::ImGuiLayer::~ImGuiLayer()  
{
}

void ImGuiLayer::OnAttach()
{
    //SetUp Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
     
	// 2. 初始化平台后端（例如 GLFW）
   

  //  GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
  //ImGui_ImplGlfw_InitForOpenGL(window, true);
     	
	

    ImGuiIO& io = ImGui::GetIO();(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   //enable keyboard Contral
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    //enable gamepad Contral
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;       //Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;     //Enable Multi_Viewport / Platform Windows
	//io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	//io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    //Set Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGUI::styleColorClassic();

    //When viewports are enable we tweak windowRounding/WindowBG so platform windows can look identcial to regular ones
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    Application& app = Application::Get();
    GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

    //Set Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window,true);
    
    // 3. 初始化渲染后端（OpenGL3）
    ImGui_ImplOpenGL3_Init("#version 410"); // 指定 GLSL 版本（如 330）
}


void ImGuiLayer::OnDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::OnEvent(Event& e)
{
    if(m_BlockEvents)
    {
        ImGuiIO& io = ImGui::GetIO();
        e.Handled |= e.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;
        e.Handled |= e.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;
    }
}

//void ImGuiLayer::OnImGuiRender()
//{
//    static bool show = true;
//    ImGui::ShowDemoWindow(&show);
//}

void ImGuiLayer::Begin()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::End() 
{
    ImGuiIO& io = ImGui::GetIO();
    Application& app = Application::Get();
    io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

    //Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) 
    {     
        GLFWwindow* back_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();       
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(back_current_context);
    }    
 }
}