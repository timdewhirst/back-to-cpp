#include <iostream>
using namespace std;

#include "Currency.hpp"
#include "CurrencyContainers.hpp"
#include "ExchangeBoard.hpp"
#include "ExchangeRate.hpp"


int main(){
    
    double mon;
    string  curr_from;
    string curr_to;
    vector <Currency> currencies; 
    vector <ExchangeRate> vec;

//- loads currencies information from a CSV file
//- loads exchange rates from a CSV file 
   
    getFileContent("back-to-cpp/datasets/currencies.csv",currencies);
    getExchange("back-to-cpp/datasets/exchange_rates.csv", vec);


//- asks for amount and currency to exchange from
    cout<<"How much money out?\n";
    cin>> mon;
    //mon=50;
    
    cout<<"Which currency to exchange from?\n";
    cin>> curr_from;
    //curr_from="BRL";
//- asks for currency to exchange to
    
    cout<<"Which currency to exchange to?\n";
    //curr_to="GBP";
    cin>> curr_to;
    
    corr_mon(vec,curr_from,curr_to,mon);


    return 0;
}