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
    for(int i=0; i<rates.size(); i++) 
    {
        if(rates[i].getBase()==quote && rates[i].getQuote()==base) 
        {   
            amount = amount * (1/rates[i].getAsk());
        }
        else if (rates[i].getBase()==base && rates[i].getQuote()==quote)
        {
            amount = amount * (rates[i].getAsk());
        }
    }
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
            amount = usdAmount;
        }
        else {
            return convertFromUSD(rates, base, quote, usdAmount);
        }
    }
    else if (base == "USD") {
        return convertFromUSD(rates, base, quote, amount);
    }
    return amount;
}