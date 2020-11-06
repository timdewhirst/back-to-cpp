#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ExchangeRate.hpp"

//## Class __ExchangeBoard__

//- list of ExchangeRates
//- does the exchange


class ExchangeBoard{
    private:
        vector<ExchangeRate> exchangeRates;   
    public:
        bool didExchange=false;
        ExchangeBoard() {}

//Constructor
/*ExchangeBoard(vector<ExchangeRate> new_exchageRates){
            exchangeRates= new_exchageRates;
}
*/
/*
//getexchageRates to get code attribute
   string getExchageRates (){
        return exchageRates;
    }
//setexchageRates to set real part
    void setExchageRates(string new_exchageRates){
        exchageRates=new_exchageRates;
    }*/

};
bool const corr_mon(unordered_map<string, unordered_map<string,double>> &bid,unordered_map<string, unordered_map<string,double>> &ask,const string &curr_from, const string &curr_to, const double &mon);
