//2025-6-11,���찴�̳̣�Cherno��SandBox���˴����޸ģ��Ѵ������ݷ�������
//2025-6-18,����������ļ��Ĵ��ڷŽṹ����GenaretPrpjects.bat������scrpts�ļ����£�
// ��ԭ��Haze�µ��ļ��Ƶ�Hazel/Core���棬��Hzpch.cpp�� Hzpch.h��Hazel.h�Ƶ�src�ļ�����
//2025-8-4,��������ϵͳ
//2025-8-10,��������ϵͳ���������������ʼ��˳���У�Renderer2D.cpp�н�DrawQuad������ͼ�ģ���λ�á���ɫ�����ø�Ϊforѭ��
//2025-8-24,����ͣ����֧��
//2025-8-25~26,����֡���壬����ʵ����Imagui�Ĵ�������ʾ���Ƶ�ͼ��
//2025-9-1�� ��ImGui�Ĳ�ͬ��δ����У��������ĸ����ڣ��ĸ����ڲŶ����ͼ��̷�Ӧ�������ҵĳ���ֻ�Լ�����Ч���������Ч��û�ҵ�ԭ��
//2025-9-5 ,�ӽ��쿪ʼ����ʵ�������
//2025-9-7�����˵�һ�������entt.hpp��û��registry.has()����������������һ��entt.hpp����û��emplace()������
     // ģ�庯����Getcomponent()�н�<T>д����(T),���˰�����ҳ�����
//2025-9-8,�ִ�https://github.com/TheCherno/Hazel/tree/master/Hazel/vendor/entt/include/entt.hpp������һ��entt.hpp,�Ϳ���
     //���������ˣ��ɼ���ͬ�汾��entt.hpp���ܲ�һ����Ϊ�˱���ԭ��entt,�Ұѿ��õ�����Ϊentt3.hpp
//2025-9-11,���������¶���ThoCheron����Ƶ����˳�����Ȼû���ֵ�������ͼ���С����ı�����⵽���Ǵ������
//2025-9-13,��������EditorLayer��������class CameraController�������ű�����ģ��������Scene��������--�߼�������


/*******************************************************************************************************************/
//2025-9-14   ��Scene.cpp��   ���´�����auto& cameraCompoent = view.get<CameraComponent>(entity);��������ǰ�õ���
// auto cameraCompoent = view.get<CameraComponent>(entity); û�������õ���ͼ����Ȼ���洰�ڴ�С�ͱ����仯����Ϊ���ú�Ͳ����ˡ�
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