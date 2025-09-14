#include "hzpch.h"
#include "Hazel/Core/Input.h"
#include "Core/Application.h"
#include "glfw3.h"
namespace Hazel {
	bool Input::IsKeyPressed(int keycode)
	{
		/**************************************************************************************/
		/*下面代码：Get()返加一个Application对象，里面有一个自定义window的指针(用Getwindow()获得)，*/
		/*用该指针取得当前window的所有权（不一定是GLFWwindow)，再用该所有权（也是指针）调用**********/
		/***GetNativeWindow()函数，取得真实window的指针，本例是GLFWwindow,以后也可改为其他的window**/
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window,keycode);
			return state == GLFW_PRESS || state==GLFW_REPEAT;
	}
	bool Input::IsMouseButtonPressed(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
		return state;
	}
	std::pair<float, float> Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		//return std::pair((float)x, (float)y);
		return {(float)x, (float)y};
	}
	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return  x;
	}
	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return  y;
	}
}