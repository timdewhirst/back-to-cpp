#include <atomic>
#include <thread>
#include <mutex>
#include <iostream>

#include "randomWalk.hpp"

using namespace std;

mutex g_mutex_cout;

void change_rate(atomic<bool> &keep_running)
{
    g_mutex_cout.lock();
    cout << "Rate Change Thread: Starting" << endl;
    g_mutex_cout.unlock();

    g_mutex_cout.lock();
    cout << "Rate Change Thread: Ending" << endl;
    g_mutex_cout.unlock();
}
