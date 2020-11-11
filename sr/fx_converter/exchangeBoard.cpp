#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "exchangeBoard.hpp"

vector<string> split(const string &stream, char delim);

void ExchangeBoard::readExchangeRatesFromFile(const string &fileName)
{
    ifstream file(fileName.c_str());
    string line;
    string key;
    vector<string> values;

    if (!file)
    {
        cout << "Cannot read from this file: " << fileName << endl;
    }

    //Skip first line 
    getline(file, line);

    while(getline(file, line))
    {
        values = split(line, ',');
        //Create a new ExchangeRate object wrapped in a shared_ptr
        auto pointerRate = make_shared<ExchangeRate>(values[0], values[1],
        stod(values[2]), stod(values[3]), stod(values[4]));

        key = pointerRate->getBase().append(pointerRate->getQuote()); //Map key is concatination of the rate base+quote
        //Add each exchange rate to an exchangeRates unordered_map
        exchangeRates[key] = pointerRate;
    }
}

vector<string> split(const string &stream, char delim)
{
    vector<string> result;
    stringstream ss(stream);
    string item;

    while (getline(ss, item, delim))
        result.push_back(item);
    return result;
}

string findIntermediary(const unordered_map<string, const shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote){
    auto i1 = rates.find(base+quote); 
    auto i2 = rates.find(quote+base); 
    string intermediary;
    //intermediary is the first value to be exchanged to
    if (i1 == rates.end())
    {
        intermediary= i2->second.get()->getQuote();
    } 
    else if(i2 == rates.end()) 
    { 
        intermediary= i1->second.get()->getQuote();
    } 
    else if(i1==rates.end() && i2==rates.end())
    {
        //Else search for intermediary between two currencies
        cout << "Cannot find currency pair";
    }
    //Code needs expanded to include a calculation to discover a true intermediary between two currency pairs
    
return intermediary;
    
}
double convertToIntermediary(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    auto i1 = rates.find(base+intermediary);
    auto i2 = rates.find(intermediary+base);  

    if(i1==rates.end()) 
    {
        //convert inverse if intermediary is base of pair
        amount = amount * (1/(i2->second.get()->getAsk()));
    }
    else if (i2==rates.end())
    {
        amount = amount * (i1->second.get()->getAsk());
    }
    return amount;
}

double convertFromIntermediary(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote, double amount, const string &intermediary){
    auto i1 = rates.find(quote+intermediary);
    auto i2 = rates.find(intermediary+quote);

    if(i1==rates.end())
    {
        amount = amount * (i2->second.get()->getAsk());
        
    }
    else if (i2==rates.end())
    {
        //convert inverse if intermediary is quote of pair
        amount = amount * (1/i1->second.get()->getAsk());
    
    }
    return amount;
}

double exchange(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote, double amount, const string &intermediary)
{
    if(base != intermediary) {
        double intermediaryAmount;
        intermediaryAmount = convertToIntermediary(rates, base, quote, amount, intermediary);
        if(quote == intermediary) {
            //if no seconded exchange is needed, return the first exchanged amount
            amount = intermediaryAmount;
        }
        else {
            amount = convertFromIntermediary(rates, base, quote, intermediaryAmount, intermediary);
        }
    }
    else if (base == intermediary) {
        //if the calculated intermediary is already being exchanged from, only do 1 exchange and return
        amount = convertFromIntermediary(rates, base, quote, amount, intermediary);
    }
    return amount;
}
