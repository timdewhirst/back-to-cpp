#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>
#include <cassert>
#include "random_walk.hpp"

using namespace std;

bool g_run_random_walk = true;
mutex g_random_walk_mutex;

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

void gen_price_change()
{
    unique_lock<mutex> ul(g_random_walk_mutex);
    double x;

    cout << "RandomWalk thread: Starting" << endl;

    srand(time(NULL));

    while (g_run_random_walk)
    {
        x = 0.10 / sqrt(24.0 * 60.0 * 60.0) * rand_between(-1.0, 1.0) * 4;

        cout << "RandomWalk thread: generated new price change " << setprecision(8) << exp(x) << endl;
        g_random_walk_mutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));

        g_random_walk_mutex.lock();
    }

    g_random_walk_mutex.unlock();
    cout << "RandomWalk thread: Stopping" << endl;
    g_random_walk_mutex.lock();
}
