#include "ExchangeRate.hpp"
#include "ExchangeBoard.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;



bool getExchange(string fileName, vector<ExchangeRate> &vec)
{
    // Open the File
    ifstream file(fileName.c_str());
    // Check if object is valid
    if(!file)
    {
        std::cout << "Cannot open the File : "<<fileName<<endl;
        return false;
    }
    string str;
    string element;
    
    ExchangeBoard ex_board;
    // Read the next line from File untill it reaches the end.
    
    string line;
    getline(file,line);
    while(getline(file,line))
    {
        istringstream ss(line);
        ExchangeRate ex_rate;
        //vector<ExchangeRate> vec;
        for (int i = 0; i < 6; i++){
            getline(ss, line, ',');
            cout<<line<<endl;
            cout<<i<<endl;
            if(i==0){
                ex_rate.setCurrency(line);
               //cout << "Currency" << ex_rate.getCurrency();
            }
            else if (i==1){
                ex_rate.setBase(line);
                //cout << "Base" << ex_rate.getBase();
            }
            else if(i==2){
                ex_rate.setQuote(line);
                //cout << " Quote: " << ex_rate.getQuote();
            }
            else if(i==3){ 
                ex_rate.setBid(stod(line));
               // cout << " Bid: " << ex_rate.getBid();
            }
            else if(i==4){ 
                ex_rate.setAsk(stod(line));
               // cout << " Ask: " << ex_rate.getAsk();                
            }
            else if(i==5){ 
                ex_rate.setLast(stod(line));
               // cout << " Last: " << ex_rate.getLast();
            }

            if (ss)

                vec.push_back(ex_rate);
                //ex_board(vec)
        }        
    } 
    ;
    //Close The File
    file.close();
    return true;
    
}

