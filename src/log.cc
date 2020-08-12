#include <filesystem>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <ytdl/log.hh>

spdlog::logger ytdl::init_logger(const std::string& log_path)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info);
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(std::filesystem::path(log_path) / "ytdl.log", 0, 0, true);
    file_sink->set_level(spdlog::level::trace);
    auto logger = spdlog::logger("ytdl", { console_sink, file_sink });
    logger.set_level(spdlog::level::debug);
    logger.info("test");
    return std::move(logger);
}
