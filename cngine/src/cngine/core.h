#pragma once

#ifdef CG_PLATFORM_WINDOWS
	#ifdef CG_BUILD_DLL
		#define CG_API _declspec(dllexport)
	#else
		#define CG_API _declspec(dllimport)
	#endif
#else
	#error CG only supports Windows!
#endif