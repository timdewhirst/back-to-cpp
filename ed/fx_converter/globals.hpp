#pragma once

#include <mutex>
#include <atomic>

extern std::mutex g_mutex_cout;
extern std::atomic<double> g_last_quote;
