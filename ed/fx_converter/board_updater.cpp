#include <thread>
#include <chrono>
#include <iostream>
#include "board_updater.hpp"
#include "globals.hpp"

using namespace std;

mutex g_mutex_boardupdater;
condition_variable g_cv_newquote;

void update_board(atomic<bool> &keep_running)
{
    g_mutex_cout.lock();
    cout << "BoardUpdater thread: Starting" << endl;
    g_mutex_cout.unlock();

    while (keep_running)
    {
        unique_lock<mutex> ul(g_mutex_boardupdater);

        g_cv_newquote.wait_for(ul, chrono::seconds(1));

        g_mutex_cout.lock();
        cout << "BoardUpdater thread: Last quote " << g_last_quote << endl;
        g_mutex_cout.unlock();
    }

    g_mutex_cout.lock();
    cout << "BoardUpdater thread: Stopping" << endl;
    g_mutex_cout.unlock();
}
