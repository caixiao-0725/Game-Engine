#pragma once

#ifdef CG_PLATFORM_WINDOWS

extern Cngine::Application* Cngine::CreateApplication();

void main(int argc, char** argv) {
	Cngine::Log::Init();
	CG_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = Cngine::CreateApplication();
	CG_PROFILE_END_SESSION();
	CG_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	CG_PROFILE_END_SESSION();
	CG_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Shutdown.json");
	delete app;
	CG_PROFILE_END_SESSION();
}
#endif