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
    char userChoice;
    string userCurrency;
    string convertedCurrency;
    double userAmount;
    double convertedAmount;
    vector<ExchangeRate> exchangeRates;
    vector<Currency> currencies;
    
    readExchangeRatesFromFile("/home/stephen/projects/back-to-cpp/datasets/exchange_rates.csv", exchangeRates);
    readCurrenciesFromFile("/home/stephen/projects/back-to-cpp/datasets/currencies.csv", currencies);

    cout << "Do you wish to view the exchange rates? Y/N" << endl;
    cin >> userChoice;
    userChoice = toupper(userChoice);
    if (userChoice == 'Y')
    {
        displayRates(exchangeRates);
    }
    cout << "Enter the currency code (e.g. USD) you wish to trade: " << endl;
    cin >> userCurrency;
    cout << "Please enter the amount you wish to trade: " << endl;
    cin >> userAmount;
    cout << "Please enter the currency code (e.g. USD) you wish to convert to: " << endl;
    cin >> convertedCurrency;

    return 0;
}