//WindowsWindow.h
#pragma once
#include "Core/Window.h"
#include "Renderer/GraphicsContext.h"
//#include "GLFW\glfw3.h"
#include "hzpch.h"
struct GLFWwindow;

namespace Hazel {
	class HAZEL_API WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync()const override;
		GLFWwindow* GetGLFWWindow() const { return m_Window; }

		/**********************************************/
		inline virtual void* GetNativeWindow() const { return m_Window; }
		/***********************************************/
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		struct  WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		} m_Data;

		/****************上面两行代码我改了一下，把结构体直接定义了实例，不知可否运行正确***********************/
	};

}
