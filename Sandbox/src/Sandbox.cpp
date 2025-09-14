//2025-6-11,今天按教程，Cherno对SandBox作了大量修改，把大量内容放在类中
//2025-6-18,今天调整了文件的存在放结构，将GenaretPrpjects.bat放在了scrpts文件夹下，
// 将原在Haze下的文件移到Hazel/Core下面，将Hzpch.cpp和 Hzpch.h、Hazel.h移到src文件夹下
//2025-8-4,增加粒子系统
//2025-8-10,调整粒子系统中相机和相机力界初始化顺序列；Renderer2D.cpp中将DrawQuad（带贴图的）中位置、颜色等设置改为for循环
//2025-8-24,增加停靠分支，
//2025-8-25~26,增加帧缓冲，可以实现在Imagui的窗口上显示绘制的图像
//2025-9-1， 在ImGui的不同层次窗口中，鼠标点在哪个窗口，哪个窗口才对鼠标和键盘反应。但是我的程序只对键盘有效，对鼠标无效，没找到原因
//2025-9-5 ,从今天开始来做实体组件。
//2025-9-7，做了第一个组件，entt.hpp中没有registry.has()函数，重新下载了一个entt.hpp，又没有emplace()函数。
     // 模板函数中Getcomponent()中将<T>写成了(T),查了半天才找出来。
//2025-9-8,又从https://github.com/TheCherno/Hazel/tree/master/Hazel/vendor/entt/include/entt.hpp下载了一个entt.hpp,就可以
     //正常运行了，可见不同版本的entt.hpp功能不一样。为了保持原有entt,我把可用的命名为entt3.hpp
//2025-9-11,今天又重新对照ThoCheron的视频检查了程序，仍然没发现调整窗口图像大小跟随改变的问题到底是错在哪里。
//2025-9-13,增加了在EditorLayer中增加了class CameraController，用作脚本，以模板引用在Scene中添加物件--高级做法。


/*******************************************************************************************************************/
//2025-9-14   在Scene.cpp中   以下代码中auto& cameraCompoent = view.get<CameraComponent>(entity);，由于以前用的是
// auto cameraCompoent = view.get<CameraComponent>(entity); 没有用引用导致图像仍然跟随窗口大小和比例变化，改为引用后就不变了。
//                void Scene::OnViewportResize(uint32_t width, uint32_t height)
//                {
//                	m_ViewportWidth = width;
//                	m_ViewportHeight = height;
//                	//Resize our non-FixedAspcetRatio camera
//                	auto view = m_Registry.view< CameraComponent>();
//                	for (auto entity : view)
//                	{
//                		auto& cameraCompoent = view.get<CameraComponent>(entity);
//                		if (!cameraCompoent.FixedAspectRatio)
//                			cameraCompoent.Camera.SetViewportSize(width, height);
//                	}
//                }
//                }
/*******************************************************************************************************************/
#include <Hazel.h>
#include <Core/EntryPoint.h>
#include "Platform/OpenGL/OpenGLShader.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Sandbox2D.h"

class ExampleLayer :public Hazel::Layer {

public:

	void OnUpdate(Hazel::Timestep ts) override
	{
		//HZ_TRACE("Delta time: {0} ({1}ms)", ts.GetSeconds(), ts.GetMillSeconds());

		m_CameraController.OnUpdata(ts);

		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();


		Hazel::Renderer::BeginScene(m_CameraController.GetCamera());

		static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->UpLoadUniformFloat3("u_Color",m_Squarecolor);

		Hazel::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		Hazel::Renderer::EndScene();

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square color",glm::value_ptr(m_Squarecolor));
		ImGui::End();
	}

	virtual void OnEvent(Hazel::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}
private:
	Hazel::ShaderLibrary m_ShaderLibrary;
	Hazel::Ref<Hazel::Shader> m_Shader;
	Hazel::Ref<Hazel::VertexArray> m_VertexArray;

	Hazel::Ref<Hazel::Shader> m_FlatColorShader;
	Hazel::Ref<Hazel::VertexArray> m_SquareVA;

	Hazel::Ref<Hazel::Texture2D> m_Texture,m_ChernoLogoTexture;

	Hazel::OrthographicCameraController m_CameraController;
	glm::vec3 m_Squarecolor = { 0.2f,0.3f,0.8f };

};

class Sandbox :public Hazel::Application
{
public:

	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}