#include <fstream>
#include "Currency.hpp"
#include "CurrencyContainers.hpp"
#include "ExchangeBoard.hpp"
#include "ExchangeRate.hpp"

#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
/*
double curr_calc(mon&){
    p=mon&;
};*/

//Validation money in list
//Currency,Code,NumericCode

string corr_mon(string curr_from, string curr_to,double mon){
    find(currencies &,mon);
    curr_from.getBid()
    if(mon currencies.){
        ;
        }   
    
};



bool insertCurrency(string fileName, vector <string> & vec)
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
    vector<string> outside;
    int it=0;
    // Read the next line from File untill it reaches the end.
    string line;
    while(getline(file,line))
    {
        /*vector<string> headers;
        if(it=0){
            istringstream ss(line);
            while (getline(ss, line, ',')){
                headers.push_back(line);
            }        
        };*/

        istringstream ss(line);
        Currency currency;
        for (int i = 0; i < 4; i++){
            getline(ss, line, ',');
            
            if (i=0){
                cout << "Name" << currency.getName();
                currency.setName(line);
            }
            else if(i=1){
                cout << " Code: " << currency.getCode();
                currency.setCode(line);
            }
            else if(i=2){ 
                currency.setNumericCode(stoi(line));
            }
        if (ss)
            vec.push_back(line);
        
        CurrencyContainer(currency);
        it++;
        }
    
    } 

bool insertExchange(string fileName, vector <string> & vec)
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
    vector<string> outside;
    int it=0;
    // Read the next line from File untill it reaches the end.
    string line;
    while(getline(file,line))
    {
        /*vector<string> headers;
        if(it=0){
            istringstream ss(line);
            while (getline(ss, line, ',')){
                headers.push_back(line);
            }        
        };*/

        istringstream ss(line);
        Currency currency;
        for (int i = 0; i < 5; i++){
            getline(ss, line, ',');
            
            if (i=0){
                cout << "Name" << currency.getName();
                currency.setName(line);
            }
            else if(i=1){
                cout << " Code: " << currency.getCode();
                currency.setCode(line);
            }
            else if(i=2){ 
                currency.setNumericCode(stoi(line));
            }
        if (ss)
            vec.push_back(line);
        
        CurrencyContainer(currency);
        it++;
        }
    
    } 
/*    
    string line;
    
    while (getline(file, str))
    {   
        stringstream sts(str);
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            //getline(ss,element,',');
             while (getline(sts, element, ','))
            {
                //getline(sts, element, ',');
                if ( !sts.good() )
                    break;

            outside.push_back(element);

        }   
        vec.push_back(outside);

    }
        /*for (int i=0;i<10;i++)
        {   
            for(int j=0; j<50; j++){
                cout << vec[i][j] << "\n";
            }
        }*/
        
    //Close The File
    file.close();
    return true;
    
}

int main(){
    
    double mon;
    string curr_from;
    string curr_to;
    vector<string> currencies; 
    vector <string> ex_rates;

//- loads currencies information from a CSV file
//- loads exchange rates from a CSV file 
   
    insertCurrency("back-to-cpp/fx_converter/datasets/currencies.csv",currencies);
    insertExchange("back-to-cpp/fx_converter/datasets/xchange_rates.csv",ex_rates);
    cout<<currencies.size();

    //getFileContent("back-to-cpp/fx_converter/datasets/exchange_rates.csv",ex_rates);
    /*vector< vector<int> >::iterator i;
    vector<int>::iterator j;
    for (i= currencies.begin(); i!= currencies.end();i++)
        {   
            for(j=i->begin(); j!= i->end(); j++){
                cout << currencies[i][j] << "\n";
            }
        }
     
    */

  /*  
    for(string & v: currencies){
        Currency(v[0],v[1],stoi(v[2]));
    }
*/

    /*ofstream ex_rate("back-to-cpp/fx_converter/datasets/exchange_rates.csv");


    //cout<<currencies;
    vector <double> new_curr;


    if(!CurrencyContainers){
        for(int i = 0; i < currencies.length(); ++i){
            new_curr.begin();
            new_curr.insert(currency{0},curr{1},curr{2});
            //vector<>new_curr=Currency(curr{0},curr{1},curr{2});
            CurrencyContainers(new_curr);
        }
    };*/


    //cout<<"\n vector size;"<<currencies.size()<<endl;
    //cout << typeid(currencies).name() << endl;
    
//- asks for amount and currency to exchange from
    cout<<"How much money out?\n";
    //cin>> mon;
    mon=50;
    
    cout<<"Which currency to exchange from?\n\n";
    //cin>> curr_in;
    curr_from="BRL";
//- asks for currency to exchange to
    
    cout<<"Which currency to exchange to?\n\n";
    curr_to="GBP";
    //cin>> curr_out;
    corr_mon(curr_from,curr_to,mon);
//- outputs exchanged amount

    return 0;
}