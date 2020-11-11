#include <iostream>
#include <unordered_map>
using namespace std;

#include "Currency.hpp"
#include "CurrencyContainers.hpp"
#include "ExchangeBoard.hpp"
#include "ExchangeRate.hpp"


int main(){
    
    double amount;
    string  curr_from;
    string curr_to;
    vector <Currency> currencies; 
    unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>> umap;

//- loads currencies information from a CSV file
//- loads exchange rates from a CSV file 
 
    getFileContent("  /home/margon/projects/back-to-cpp/datasets/currencies.csv",currencies);
    getExchange("/home/margon/projects/back-to-cpp/datasets/exchange_rates.csv", umap);


//- asks for amount and currency to exchange from
    cout<<"How much money out?\n";
    //cin>> mon;
    amount=50;
    
    cout<<"Which currency to exchange from?\n";
    //cin>> curr_from;
    curr_from="USD";
//- asks for currency to exchange to
    
    cout<<"Which currency to exchange to?\n";
    curr_to="GBP";
    //cin>> curr_to;
    
    double conversion=corr_mon(umap,curr_from,curr_to,amount);
    
    cout<<conversion;
    return 0;
};