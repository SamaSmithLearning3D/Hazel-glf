#pragma once
#include "Hazel/Renderer/Framebuffer.h"
namespace Hazel {


	class OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const Framebufferspecification& spec);
		virtual ~OpenGLFramebuffer() ;
		void Invalidata();

		virtual void Resize(uint32_t width, uint32_t height) override;

		virtual void Bind() override;
		virtual void Unbind()override;

		virtual const uint32_t GetColorAttchmentRendererID() const override { return m_ColorAttachment; };

		virtual const Framebufferspecification& GetSepcification() const override {	return m_Specification;	}



	private:
		uint32_t m_RendererID = 0 ;
		uint32_t m_ColorAttachment= 0 , m_DepthAttachment =0 ;
		Framebufferspecification m_Specification;
	};
}