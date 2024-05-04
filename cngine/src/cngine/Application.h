#pragma once
#include "core.h"
namespace Cngine {


	class CG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
