#include "hzpch.h"
#include "Core/Core.h"
#include "OpenGLContext.h"
#include "Glad/glad.h"
#include "glfw3.h"

Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
{
}

void Hazel::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	HZ_CORE_ASSERT(status, "Failed Initialize Glad!!");
	HZ_CORE_INFO("OpenGL Render: {0}£¬{1}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)), reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
}

void Hazel::OpenGLContext::SwapBuffers()
{
	//glBegin(GL_TRIANGLES);
	glEnd();
	glfwSwapBuffers(m_WindowHandle);
}
