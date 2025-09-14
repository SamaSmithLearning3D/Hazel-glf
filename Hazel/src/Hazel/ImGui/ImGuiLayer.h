#pragma once
//#include "Hazel.h"
#include "Core/Layer.h"
//#include "Application.h"//不能包含Application.h，因为Application要包含本文件
#include "Events/ApplicationEvent.h"
#include "Events\KeyEvent.h"
#include "Events\MouseEvent.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() ;

		virtual void OnAttach()override;
		virtual void OnDetach()override;
	//	virtual void OnImGuiRender()override;
		virtual void OnEvent(Event& event)override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
	
}