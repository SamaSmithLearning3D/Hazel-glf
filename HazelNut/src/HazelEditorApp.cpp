//2025-6-11,���찴�̳̣�Cherno��SandBox���˴����޸ģ��Ѵ������ݷ�������
//2025-6-18,����������ļ��Ĵ��ڷŽṹ����GenaretPrpjects.bat������scrpts�ļ����£�
// ��ԭ��Haze�µ��ļ��Ƶ�Hazel/Core���棬��Hzpch.cpp�� Hzpch.h��Hazel.h�Ƶ�src�ļ�����
//2025-8-4,��������ϵͳ
//2025-8-10,��������ϵͳ���������������ʼ��˳���У�Renderer2D.cpp�н�DrawQuad������ͼ�ģ���λ�á���ɫ�����ø�Ϊforѭ��
//2025-8-24,����ͣ����֧��
//2025-8-25~26,����֡���壬����ʵ����Imagui�Ĵ�������ʾ���Ƶ�ͼ��
#include <Hazel.h>
#include <Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hazel {

	class HazelNut :public Application
	{
	public:

		HazelNut()
			:Application("HazelNut")
		{
			
			PushLayer(new EditorLayer());
		}

		~HazelNut()
		{

		}

	};

	Application* CreateApplication()
	{
		return new HazelNut();
	}
}