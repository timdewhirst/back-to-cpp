#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include <unordered_map>
using namespace std;

#include "ExchangeRate.hpp"
#include "ExchangeBoard.hpp"

typedef unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>> nested_uno_map;
typedef unordered_map<string,shared_ptr<ExchangeRate>> uno_map ;


//Function to create unordered map containing the base, quote and bid
nested_uno_map bid_insert(uno_map &inmap, ExchangeRate &ex_rate, nested_uno_map &umap){
    shared_ptr<ExchangeRate> er_pointer=make_shared<ExchangeRate>(ex_rate);
    inmap[ex_rate.getQuote()]=er_pointer;
    umap[ex_rate.getBase()]=inmap;
    return umap;
}

//Function to input the exchange_rate.csv file and output 2 unordered maps separating the ask and bids for different currencies
bool const getExchange(const string fileName,  unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>> &umap)
{
    // Open the File
    ifstream file(fileName.c_str());

    if(!file)
    {
        std::cout << "Cannot open the File : "<<fileName<<endl;
        return false;
    }
    
    
    string line;
    unordered_map<string,shared_ptr<ExchangeRate>> aud_bid;
    unordered_map<string,shared_ptr<ExchangeRate>> eur_bid;
    unordered_map<string,shared_ptr<ExchangeRate>> gbp_bid;
    unordered_map<string,shared_ptr<ExchangeRate>> usd_bid;
    unordered_map<string,shared_ptr<ExchangeRate>> nzd_bid;
/*
    unordered_map<string,double> aud_ask;
    unordered_map<string,double> eur_ask;
    unordered_map<string,double> gbp_ask;
    unordered_map<string,double> usd_ask;
    unordered_map<string,double> nzd_ask;*/
    
    
    // Skip 1st line and read the next line from File untill it reaches the end.
    getline(file,line);
    while(getline(file,line))
    {   
        //unordered_map<string, unordered_map<string,double>> umap;
        istringstream ss(line);
        ExchangeRate ex_rate;
        //vector<ExchangeRate> vec;
        for (int i = 0; i < 5; i++){
            getline(ss, line, ',');
            if (i==0){
                ex_rate.setBase(line);
            }
            else if(i==1){
                ex_rate.setQuote(line);
            }

            else if(i==2){
                ex_rate.setBid(stod(line));                

            }
            else if(i==3){ 
                ex_rate.setAsk(stod(line));

            }
            else if(i==4){ 
                ex_rate.setLast(stod(line));
            }
            
        }

        if (ex_rate.getBase()=="AUD"){
            //aud_bid[ex_rate.getQuote()]=ex_rate;
            umap=bid_insert(aud_bid,ex_rate,umap);    
        }
        else if (ex_rate.getBase()=="EUR"){
            umap=bid_insert(eur_bid,ex_rate,umap);
        }
        else if (ex_rate.getBase()=="GBP"){
            umap=bid_insert(gbp_bid,ex_rate,umap);
        }
        else if (ex_rate.getBase()=="NZD"){
            umap=bid_insert(nzd_bid,ex_rate,umap);
        }
        else if (ex_rate.getBase()=="USD"){
            umap=bid_insert(usd_bid,ex_rate,umap);
        }
        else if((ex_rate.getBase()!="AUD")||(ex_rate.getBase()!="EUR")||(ex_rate.getBase()!="GBP")||(ex_rate.getBase()!="NZD")||(ex_rate.getBase()!="USD")){
            cout<<"new currency: "<<ex_rate.getBase();
            return false;
        }      
    };
    /*for(const auto& base:umap){
        for(const auto& quote:base.second){
            cout<<"Base: "<<base.first<<endl;
            cout<<quote.first<<endl;
            //cout<<"Ask: "<<quote.second-> getAsk()<<endl;
        }
    }
    cout<<umap.size()<<endl;*/
    //ExchangeBoard currency_bid = um_bid;
    

    //Close The File
    file.close();
    return true;
    
}


