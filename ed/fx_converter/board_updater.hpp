#ifndef _BOARD_UPDATER_HPP_
#define _BOARD_UPDATER_HPP_

#include <mutex>
#include <condition_variable>
#include <atomic>

extern std::mutex g_mutex_boardupdater;
extern std::condition_variable g_cv_newquote;

void update_board(std::atomic<bool> &keep_running);

#endif
