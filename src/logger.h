#include "spdlog/spdlog.h"

namespace NGine
{
#define NGINE_INFO(...) spdlog::info(__VA_ARGS__)
#define NGINE_WARN(...) spdlog::warn(__VA_ARGS__)
#define NGINE_ERROR(...) spdlog::error(__VA_ARGS__)
}