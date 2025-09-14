#pragma once
#include "Hazel/Core/Core.h"
namespace Hazel
{
	struct Framebufferspecification
	{
		uint32_t Width , Height;
		//FramebufferFormat Format=
		uint32_t Samples = 1;
		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		//virtual ~Framebuffer() = default;
		virtual void Bind() =0;
		virtual void Unbind()=0;

		virtual void Resize(uint32_t width, uint32_t height) = 0;

		virtual const uint32_t GetColorAttchmentRendererID() const = 0;
		static Ref<Framebuffer> Create(const Framebufferspecification& spec);
		virtual const Framebufferspecification& GetSepcification() const =0;
	};

}