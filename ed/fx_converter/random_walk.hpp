#ifndef RANDOM_WALK_HPP
#define RANDOM_WALK_HPP

#include <mutex>

extern std::mutex g_random_walk_mutex;
extern bool g_run_random_walk;

void gen_price_change();

#endif