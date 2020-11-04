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
bool corr_mon(vector <ExchangeRate> &vec,string &curr_from, string &curr_to,double &mon);