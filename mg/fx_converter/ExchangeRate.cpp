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
    while(getline(file,line))
    {
        istringstream ss(line);
        ExchangeRate ex_rate;
        //vector<ExchangeRate> vec;
        for (int i = 0; i < 6; i++){
            getline(ss, line, ',');
            if (i=1){
                cout << "Base" << ex_rate.getBase();
                ex_rate.setBase(line);
            }
            else if(i=2){
                cout << " Quote: " << ex_rate.getQuote();
                ex_rate.setQuote(line);
            }
            else if(i=3){ 
                cout << " Bid: " << ex_rate.getBid();
                ex_rate.setBid(stod(line));
            }
            else if(i=4){ 
                cout << " Ask: " << ex_rate.getAsk();
                ex_rate.setAsk(stod(line));
            }
            else if(i=5){ 
                cout << " Last: " << ex_rate.getLast();
                ex_rate.setLast(stod(line));
            }

            if (ss)

                vec.push_back(ex_rate);
                //ex_board(vec)
        }
        cout<<ex_rate.getBase()<<"------------------------------"<<endl;
        
    } 
    ;
    //Close The File
    file.close();
    return true;
    
}
