#pragma once
#include "core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/event.h"
#include "Events/ApplicationEvent.h"

#include "Core/Timestep.h"
#include "ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Hazel
{
	class  Application
	{
	public:
		Application(const std::string& name = "Hazel App");
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};
	Application* CreateApplication() ;
}