#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//## Class __ExchangeRate__

//Attributes:

//- from currency
//- to currency
//- rate

class ExchangeRate{
    private:
        string currency;
        string base;
        string quote;
        double bid;
        double ask;
        double last;

    public:
        ExchangeRate() {}

//Constructor
    ExchangeRate(string new_currency,string new_base, string new_quote, double new_bid, double new_ask, double new_last){
            currency=new_currency;
            base= new_base;
            quote= new_quote;
            bid= new_bid;
            ask= new_ask;
            last= new_last;
    }
//getCurrency to get code attribute
   string getCurrency (){
        return currency;
    }
//setCurency to set real part
    void setCurrency(string new_currency){
        currency=new_currency;
    }

//getBase to get code attribute
   string getBase (){
        return base;
    }
//setBase to set real part
    void setBase(string new_base){
        base=new_base;
    }

//getQuote to get code attribute
    string getQuote (){
        return quote;
    }
//setQuote to set real part
    void setQuote(string new_quote){
        quote=new_quote;
    }

//getBid to get code attribute
    double getBid (){
        return bid;
    }
//setBid to set real part
    void setBid(int new_bid){
        bid=new_bid;
    }

//getAsk to get code attribute
    double getAsk (){
        return ask;
    }
//setAsk to set real part
    void setAsk(int new_ask){
       ask=new_ask;
    }

//getLast to get code attribute
    double getLast (){
        return last;
    }
//setLast to set real part
    void setLast(int new_last){
       last=new_last;
    }
};

bool getExchange(string fileName, vector<ExchangeRate> &vec);