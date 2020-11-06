#include <string>
#include <vector>
#include <iostream>

#include "exchangeBoard.hpp"

string findIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote){
    auto i1 = rates.find(base+quote); 
    auto i2 = rates.find(quote+base); 
    string intermediary;
    if (i1 == rates.end())
    {
        intermediary= i2->second.getQuote();
    } 
    else if(i2 == rates.end()) 
    { 
        intermediary= i1->second.getQuote();
    } 
    else if(i1==rates.end() && i2==rates.end())
    {
        cout << "Cannot find currency pair";
    }
    
return intermediary;
    
}
/*
double convertToIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
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

double convertFromIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
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

double exchange(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary)
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
*/
