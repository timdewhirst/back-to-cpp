#include <string>
#include <vector>
#include <iostream>

#include "exchangeBoard.hpp"

void displayRates(const vector<ExchangeRate> &exchangeRates)
{
    for ( int i = 0; i < exchangeRates.size(); ++i ) 
    {
        cout << "Currency: " << exchangeRates[i].getBase() << "/" << exchangeRates[i].getQuote() << " Bid: " << exchangeRates[i].getBid() << " Ask: " << exchangeRates[i].getAsk() << endl;
    }
}

double convertToIntermediary(const vector<ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    for(int i=0; i<rates.size(); i++) 
    {
        if(rates[i].getBase()==intermediary && rates[i].getQuote()==base) 
        {   
            amount = amount * (1/rates[i].getAsk());
        }
        else if (rates[i].getBase()==base && rates[i].getQuote()==intermediary)
        {
            amount = amount * (rates[i].getAsk());
        }
    }
    return amount;
}

double convertFromIntermediary(const vector<ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    for(int i=0; i<rates.size(); i++) 
    {
        if(rates[i].getBase()==quote && rates[i].getQuote()==intermediary) 
        {   
            amount = amount * (1/rates[i].getAsk());
        }
        else if (rates[i].getBase()==intermediary && rates[i].getQuote()==quote)
        {
            amount = amount * (rates[i].getAsk());
        }
    }
    return amount;
}

double exchange(const vector<ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary)
{
    if(base != intermediary) {
        double intermediaryAmount;
        intermediaryAmount = convertToIntermediary(rates, base, quote, amount, intermediary);
        if(quote == intermediary) {
            amount = intermediaryAmount;
        }
        else {
            return convertFromIntermediary(rates, base, quote, intermediaryAmount, intermediary);
        }
    }
    else if (base == intermediary) {
        return convertFromIntermediary(rates, base, quote, amount, intermediary);
    }
    return amount;
}