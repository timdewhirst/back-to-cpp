#include "currency.cpp"
#include "exchangeRate.cpp"
#include "exchangeBoard.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string userCurrency;
    string convertedCurrency;
    double userAmount;
    double convertedAmount;
    vector<ExchangeRate> exchangeRates;
    vector<Currency> currencies;
    
    readExchangeRatesFromFile("/home/stephen/projects/back-to-cpp/fx_converter/datasets/exchange_rates.csv", exchangeRates);
    readCurrenciesFromFile("/home/stephen/projects/back-to-cpp/fx_converter/datasets/currencies.csv", currencies);

    displayRates(exchangeRates);
    
    cout << "Enter the currency code (e.g. USD) you wish to trade: " << endl;
    cin >> userCurrency;
    cout << "Please enter the amount you wish to trade: " << endl;
    cin >> userAmount;
    cout << "Please enter the currency code (e.g. USD) you wish to convert to: " << endl;
    cin >> convertedCurrency;

    return 0;
}