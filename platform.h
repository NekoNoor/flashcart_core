#pragma once

#include <cstdint>
#include <cstddef>

namespace flashcart_core {
extern bool spoofFlashchip;
extern const uint16_t flashchip_ids[];
extern size_t flashchip_count;
extern uint16_t spoofedFlashchip;

enum log_priority {
    LOG_DEBUG = 0, // Will probably spam logs, only use when debugging.
    LOG_INFO, // Reccomended default logfile level
    LOG_NOTICE, // Reccomended default display level, if implemented.
    LOG_WARN,
    LOG_ERR,
    LOG_PRIORITY_MAX
};

enum class BlowfishKey {
    NTR, B9Retail, B9Dev
};

// override these in platform.cpp
namespace platform {
void showProgress(std::uint32_t current, std::uint32_t total, const char* status_string);
int logMessage(log_priority priority, const char *fmt, ...);
auto getBlowfishKey(BlowfishKey key) -> const std::uint8_t(&)[0x1048];
}
}
