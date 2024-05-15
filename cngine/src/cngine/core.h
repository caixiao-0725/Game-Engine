#pragma once


#ifdef CG_PLATFORM_WINDOWS
	#if CG_DYNAMIC_LINK
		#ifdef CG_BUILD_DLL
			#define CG_API _declspec(dllexport)
		#else
			#define CG_API _declspec(dllimport)
		#endif
	#else
		#define CG_API 
	#endif

#else
	#error CG only supports Windows!
#endif

#ifdef CG_ENABLE_ASSERTS
	#define CG_ASSERT(x, ...) { if(!(x)) { CG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CG_CORE_ASSERT(x, ...) { if(!(x)) { CG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CG_ASSERT(x, ...)
	#define CG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CG_BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)