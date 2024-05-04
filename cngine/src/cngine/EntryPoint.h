#pragma once

#ifdef CG_PLATFORM_WINDOWS

extern Cngine::Application* Cngine::CreateApplication();

void main(int argc, char** argv) {
	auto app = Cngine::CreateApplication();
	app->Run();
	delete app;
}
#endif