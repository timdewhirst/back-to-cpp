#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "currency.hpp"
#include "exchangeRate.hpp"
#include "exchangeBoard.hpp"

using namespace std;

int main()
{   
    string userCurrency;
    string convertedCurrency;
    string intermediary;
    double userAmount;
    double convertedAmount;
    unordered_map<string, ExchangeRate> exchangeRates;
    vector<Currency> currencies;
    
    readExchangeRatesFromFile("/home/stephen/projects/back-to-cpp/datasets/exchange_rates.csv", exchangeRates);
    readCurrenciesFromFile("/home/stephen/projects/back-to-cpp/datasets/currencies.csv", currencies);

    cout << "Enter the currency code (e.g. USD) you wish to trade: " << endl;
    cin >> userCurrency; 
    cout << "Please enter the amount you wish to trade: " << endl;
    cin >> userAmount;
    cout << "Please enter the currency code (e.g. USD) you wish to convert to: " << endl;
    cin >> convertedCurrency;

    intermediary = findIntermediary(exchangeRates, userCurrency, convertedCurrency);

    convertedAmount = exchange(exchangeRates, userCurrency, convertedCurrency, userAmount, intermediary);

    cout << "You have exchanged " << userAmount << " " << userCurrency << " for " << convertedAmount << " " << convertedCurrency << "." << endl;
    return 0;
}