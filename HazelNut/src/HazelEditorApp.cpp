//2025-6-11,今天按教程，Cherno对SandBox作了大量修改，把大量内容放在类中
//2025-6-18,今天调整了文件的存在放结构，将GenaretPrpjects.bat放在了scrpts文件夹下，
// 将原在Haze下的文件移到Hazel/Core下面，将Hzpch.cpp和 Hzpch.h、Hazel.h移到src文件夹下
//2025-8-4,增加粒子系统
//2025-8-10,调整粒子系统中相机和相机力界初始化顺序列；Renderer2D.cpp中将DrawQuad（带贴图的）中位置、颜色等设置改为for循环
//2025-8-24,增加停靠分支，
//2025-8-25~26,增加帧缓冲，可以实现在Imagui的窗口上显示绘制的图像
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