#include <fstream>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <chrono>
#include "exchange_board.hpp"
#include "exchange_rate.hpp"
#include "random_walk.hpp"

using namespace std;

int main()
{
    thread th1(gen_price_change);

    cout << "Main thread will sleep for 5 seconds" << endl;
    
    this_thread::sleep_for(chrono::seconds(5));

    // ExchangeBoard board;
    // unordered_map<string, ExchangeRate> rates;

    // rates["EUR/USD"] = ExchangeRate("EUR", "USD", 1.20, 1.30);
    // rates["USD/JPY"] = ExchangeRate("USD", "JPY", 104, 105);

    // cout << rates["EUR/USD"].get_bid() << endl;

    // board.add_rates(rates);
    // board.convert("EUR", "USD", 1000);
    // rates["EUR/USD"].update(0.10);
    // board.convert("EUR", "USD", 1000);

    //rates = load_rates("exchange_rates.csv");

    g_random_walk_mutex.lock();
    g_run_random_walk = false;
    g_random_walk_mutex.unlock();
    
    th1.join();
}
