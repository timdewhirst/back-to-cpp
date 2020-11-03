#include <string>
#include <vector>
#include <iostream>

#include "exchangeBoard.hpp"

void displayRates(vector<ExchangeRate> & exchangeRates)
{
    for ( size_t i = 0; i < exchangeRates.size(); ++i ) 
    {
        cout << "Currency: " << exchangeRates[i].getBase() << "/" << exchangeRates[i].getQuote() << " Bid: " << exchangeRates[i].getBid() << " Ask: " << exchangeRates[i].getAsk() << endl;
    }
}

double convertToUSD(vector<ExchangeRate> &rates, string &base, string &quote, double amount){
    //If userQuote does not have Base USD(Convert Amount*Ask)
    //If userQuote does have Base USD (Convert Amount*1/Ask)
    //If Quote USD Return Amount
    return amount;
}
//ELSE && quote !USD
double convertFromUSD(vector<ExchangeRate> &rates, string &base, string &quote, double amount){
    //If userQuote(USD) quote does have Base USD (Convert Amount*Ask)
    //If userQuote(USD) does not have Base USD (Convert Amount *1/Ask)
    return amount;
}

double exchange(vector<ExchangeRate> &rates, string &base, string &quote, double amount)
{
    if(base != "USD") {
        double usdAmount;
        usdAmount = convertToUSD(rates, base, quote, amount);
        if(quote == "USD") {
            return usdAmount;
        }
        else {
            return convertFromUSD(rates, base, quote, usdAmount);
        }
    }
    else if (base == "USD") {
        return convertFromUSD(rates, base, quote, amount);
    }
}