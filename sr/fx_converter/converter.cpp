/* Converter.cpp is where the main application is run, delcaring variables and accepting
user input for which currency they want converted, as well as managing threads*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>

#include "currency.hpp"
#include "exchangeRate.hpp"
#include "exchangeBoard.hpp"
#include "randomWalk.hpp"

using namespace std;

int main()
{   
    string userCurrency;
    string convertedCurrency;
    string intermediary;
    double userAmount;
    double convertedAmount;
    vector<Currency> currencies;
    ExchangeBoard exchangeBoard;
    atomic<bool> run_threads(true);
    
    //thread thread1(change_rate, ref(run_threads));
    
    exchangeBoard.readExchangeRatesFromFile("/home/stephen/projects/back-to-cpp/datasets/exchange_rates.csv");
    readCurrenciesFromFile("/home/stephen/projects/back-to-cpp/datasets/currencies.csv", currencies);
    
    cout << "Enter the currency code (e.g. USD) you wish to trade: " << endl;
    cin >> userCurrency; 
    cout << "Please enter the amount you wish to trade: " << endl;
    cin >> userAmount;
    cout << "Please enter the currency code (e.g. USD) you wish to convert to: " << endl;
    cin >> convertedCurrency;

    //intermediary = findIntermediary(exchangeRates, userCurrency, convertedCurrency);

    //convertedAmount = exchange(exchangeRates, userCurrency, convertedCurrency, userAmount, intermediary);

    cout << "You have exchanged " << userAmount << " " << userCurrency << " for " << convertedAmount << " " << convertedCurrency << "." << endl;
    
    //thread1.join();
    
    return 0;
}