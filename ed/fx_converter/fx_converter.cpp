#include <memory>
#include <iostream>
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
    ExchangeBoard board;
    //shared_ptr<ExchangeRate> p_rate;

    board.load_rates("./../../datasets/exchange_rates.csv");

    board.convert("EUR", "JPY", 100);
    cout << endl;
    
    board.convert("EUR", "KZH", 100);
    cout << endl;

    board.convert("CAD", "JPY", 100);

    // g_last_quote = 140.00;

    // atomic<bool> run_threads(true);
    // thread th1(quote_change, std::ref(run_threads));
    // thread th2(update_board, std::ref(run_threads));
    // string ccy1, ccy2;

    // // g_random_walk_mutex.lock();
    // // cout << "What currency?: ";
    // // cin >> ccy1;
    // // g_random_walk_mutex.unlock();

    // this_thread::sleep_for(chrono::seconds(15));

    // run_threads = false;

    // th1.join();
    // th2.join();
}
