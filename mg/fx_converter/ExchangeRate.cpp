#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

#include "ExchangeRate.hpp"
#include "ExchangeBoard.hpp"

//Function to create unordered map containing the base, quote and bid
unordered_map<string, unordered_map<string,double>> bid_insert(unordered_map<string,double> &inmap, ExchangeRate &ex_rate, unordered_map<string, unordered_map<string,double>>umap){
    inmap[ex_rate.getQuote()]=ex_rate.getBid();
    umap[ex_rate.getBase()]=inmap;
    return umap;
}
//Function to create unordered map containing the base, quote and ask
unordered_map<string, unordered_map<string,double>> ask_insert(unordered_map<string,double> &inmap, ExchangeRate &ex_rate, unordered_map<string, unordered_map<string,double>>&umap){
    inmap[ex_rate.getQuote()]=ex_rate.getAsk();
    umap[ex_rate.getBase()]=inmap;
    return umap;
}

//Function to input the exchange_rate.csv file and output 2 unordered maps separating the ask and bids for different currencies
bool const getExchange(const string fileName,  unordered_map<string, unordered_map<string,double>> &um_bid, unordered_map<string, unordered_map<string,double>> &um_ask)
{
    // Open the File
    ifstream file(fileName.c_str());

    // Check if object is valid
    if(!file)
    {
        std::cout << "Cannot open the File : "<<fileName<<endl;
        return false;
    }
    
    
    string line;
    unordered_map<string,double> aud_bid;
    unordered_map<string,double> eur_bid;
    unordered_map<string,double> gbp_bid;
    unordered_map<string,double> usd_bid;
    unordered_map<string,double> nzd_bid;

    unordered_map<string,double> aud_ask;
    unordered_map<string,double> eur_ask;
    unordered_map<string,double> gbp_ask;
    unordered_map<string,double> usd_ask;
    unordered_map<string,double> nzd_ask;
    
    
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
                //cout << "Base" << ex_rate.getBase();
            }
            else if(i==1){
                ex_rate.setQuote(line);
                
                //cout << " Quote: " << ex_rate.getQuote();
            }
            else if(i==2){
                ex_rate.setBid(stod(line));
                //Check base and insert value
                if (ex_rate.getBase()=="AUD"){
                    um_bid=bid_insert(aud_bid,ex_rate,um_bid);    
                }
                else if (ex_rate.getBase()=="EUR"){
                    um_bid=bid_insert(eur_bid,ex_rate,um_bid);
                }
                else if (ex_rate.getBase()=="GBP"){
                    um_bid=bid_insert(gbp_bid,ex_rate,um_bid);
                }
                else if (ex_rate.getBase()=="NZD"){
                    um_bid=bid_insert(nzd_bid,ex_rate,um_bid);
                }
                else if (ex_rate.getBase()=="USD"){
                    um_bid=bid_insert(usd_bid,ex_rate,um_bid);
                }
                else if((ex_rate.getBase()!="AUD")||(ex_rate.getBase()!="EUR")||(ex_rate.getBase()!="GBP")||(ex_rate.getBase()!="NZD")||(ex_rate.getBase()!="USD")){
                    cout<<"new currency: "<<ex_rate.getBase();
                }

            }
            else if(i==3){ 
                ex_rate.setAsk(stod(line));
                //Check base and insert value
                if (ex_rate.getBase()=="AUD"){
                    um_ask=ask_insert(aud_ask,ex_rate,um_ask);    
                }
                else if (ex_rate.getBase()=="EUR"){
                    um_ask=ask_insert(eur_ask,ex_rate,um_ask);
                }
                else if (ex_rate.getBase()=="GBP"){
                    um_ask=ask_insert(gbp_ask,ex_rate,um_ask);
                }
                else if (ex_rate.getBase()=="NZD"){
                    um_ask=ask_insert(nzd_ask,ex_rate,um_ask);
                }
                else if (ex_rate.getBase()=="USD"){
                    um_ask=ask_insert(usd_ask,ex_rate,um_ask);
                }
                else if((ex_rate.getBase()!="AUD")||(ex_rate.getBase()!="EUR")||(ex_rate.getBase()!="GBP")||(ex_rate.getBase()!="NZD")||(ex_rate.getBase()!="USD")){
                    cout<<"currency not saved: "<<ex_rate.getBase();
                }              
            }
            else if(i==4){ 
                ex_rate.setLast(stod(line));
               // cout << " Last: " << ex_rate.getLast();
            }

        }      
    };
    cout<<um_bid.size()<<endl;
    //ExchangeBoard currency_bid = um_bid;
    
    //Close The File
    file.close();
    return true;
    
}
