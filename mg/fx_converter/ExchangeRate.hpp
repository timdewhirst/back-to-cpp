#include <iostream>
using namespace std;
//## Class __ExchangeRate__

//Attributes:

//- from currency
//- to currency
//- rate

class ExchangeRate{
    private:
        string from_currency;
        string to_currency;
        double rate;

//Constructor
    ExchangeRate(string new_from_currency, string new_to_currency, int new_rate){
            from_currency=new_from_currency;
            to_currency=new_to_currency;
            rate=new_rate;
    }

//getCode to get code attribute
   string getFromCurrency (){
        return from_currency;
    }
//setCode to set real part
    void setFromCurrency(string new_from_currency){
        from_currency=new_from_currency;
    }

//getCode to get code attribute
    string getToCurrency (){
        return to_currency;
    }
//setCode to set real part
    void setToCurrency(string new_to_currency){
        to_currency=new_to_currency;
    }

//getCode to get code attribute
    double getRate (){
        return rate;
    }
//setCode to set real part
    void setRate(int new_rate){
        rate=new_rate;
    }
};
