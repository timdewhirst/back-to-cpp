#include <fstream>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <atomic>
#include "exchange_board.hpp"
#include "exchange_rate.hpp"
#include "random_walk.hpp"
#include "board_updater.hpp"
#include "globals.hpp"

using namespace std;

int main()
{
    g_last_quote = 140.00;

    atomic<bool> run_threads(true);
    thread th1(quote_change, std::ref(run_threads));
    thread th2(update_board, std::ref(run_threads));
    string ccy1, ccy2;

    // g_random_walk_mutex.lock();
    // cout << "What currency?: ";
    // cin >> ccy1;
    // g_random_walk_mutex.unlock();

    this_thread::sleep_for(chrono::seconds(15));

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

    run_threads = false;

    th1.join();
    th2.join();
}
