/* Calculating the Exchange
Methods:
CONVERT TO USD:
If Base !USD & !GBP {Convert to USD Inverse}
ELSE If Base GBP {Convert to USD}
ELSE IF USD return value

CONVERT FROM USD:
If quote GBP {Convert inverse}
Else {Convert Normal}

If quote USD {run method 1}
ELSE If if quote !USD {run method 1 & 2}
*/
#include "exchangeBoard.hpp"
#include <string>
#include <vector>
#include <iostream>

void displayRates(vector<ExchangeRate> & exchangeRates)
{
    for ( size_t i = 0; i < exchangeRates.size(); ++i ) 
    {
        cout << "Currency: " << exchangeRates[i].getBase() << "/" << exchangeRates[i].getQuote() << " Bid: " << exchangeRates[i].getBid() << " Ask: " << exchangeRates[i].getAsk() << endl;
    }
}

double convertToUSD(string &base, string &quote, double amount);

