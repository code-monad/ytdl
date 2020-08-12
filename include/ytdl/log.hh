#ifndef __YTDL_LOG_HH__
#define __YTDL_LOG_HH__

#include <spdlog/logger.h>

#include <memory>

namespace ytdl {
    spdlog::logger init_logger(const std::string& log_path = "log");
}
#endif
