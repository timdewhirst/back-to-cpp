#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include "random_walk.hpp"

using namespace std;

bool g_run_random_walk = true;
mutex g_random_walk_mutex;

void gen_price_change()
{
    cout << "RandomWalk thread: Starting" << endl;

    srand(time(NULL));

    g_random_walk_mutex.lock();

    while (g_run_random_walk)
    {
        g_random_walk_mutex.unlock();
        cout << "RandomWalk thread: generated new random value " << double(rand()) / RAND_MAX << endl;

        this_thread::sleep_for(chrono::milliseconds(500));

        g_random_walk_mutex.lock();
    }

    cout << "RandomWalk thread: Stopping" << endl;
    
    g_random_walk_mutex.unlock();
}
