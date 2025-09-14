#pragma once
#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();
int main(int argc,char**argv) 
{
	Hazel::Log::Init();
	HZ_TRACE("glfla");
	Hazel::Log::GetCoreLogger()->trace("test,getcorlgffer");
	HZ_ERROR("THIS IS A TEST!");
	auto app = Hazel::CreateApplication();
	app->Run();

	delete app;
}
#endif
