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
double convertToIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    auto i1 = rates.find(base+intermediary);
    auto i2 = rates.find(intermediary+base);  

    if(i1==rates.end()) 
    {   
        amount = amount * (1/i2->second.getAsk());
    }
    else if (i2==rates.end())
    {
        amount = amount * (i1->second.getAsk());
    }
    return amount;
}

double convertFromIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    auto i1 = rates.find(quote+intermediary);
    auto i2 = rates.find(intermediary+quote);

    {
        if(i1==rates.end())
        {   
            amount = amount * (1/i2->second.getAsk());
        }
        else if (i2==rates.end())
        {
            amount = amount * (i1->second.getAsk());
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
            amount = convertFromIntermediary(rates, base, quote, intermediaryAmount, intermediary);
        }
    }
    else if (base == intermediary) {
        amount = convertFromIntermediary(rates, base, quote, amount, intermediary);
    }
    return amount;
}

