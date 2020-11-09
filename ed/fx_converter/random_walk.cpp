#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>
#include <cassert>
#include "random_walk.hpp"
#include "board_updater.hpp"
#include "globals.hpp"

using namespace std;

double rand_between(double a, double b)
{
    assert(a < b);
    return a + (b - a) * double(rand()) / RAND_MAX;
}

int rand_between(int a, int b)
{
    assert(a < b);
    return int(a + (b - a) * double(rand()) / RAND_MAX);
}

void quote_change(atomic<bool> &keep_running)
{
    g_mutex_cout.lock();
    cout << "RandomWalk thread: Starting" << endl;
    g_mutex_cout.unlock();

    srand(time(NULL));

    while (keep_running)
    {
        g_last_quote = g_last_quote * exp(0.10 / sqrt(24.0 * 60.0 * 60.0) * rand_between(-1.0, 1.0) * 4);

        g_cv_newquote.notify_one();

        this_thread::sleep_for(chrono::milliseconds(rand_between(2000, 5000)));
    }

    g_mutex_cout.lock();
    cout << "RandomWalk thread: Stopping" << endl;
    g_mutex_cout.unlock();
}
