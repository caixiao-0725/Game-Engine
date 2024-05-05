#pragma once
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cngine{
class CG_API Log
{
public:
	static void Init();
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

};
}

#define CG_CORE_TRACE(...) ::Cngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CG_CORE_INFO(...) ::Cngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CG_CORE_WARN(...) ::Cngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CG_CORE_ERROR(...) ::Cngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CG_CORE_FATAL(...) ::Cngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CG_TRACE(...) ::Cngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CG_INFO(...) ::Cngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CG_WARN(...) ::Cngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CG_ERROR(...) ::Cngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CG_FATAL(...) ::Cngine::Log::GetClientLogger()->fatal(__VA_ARGS__)