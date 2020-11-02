#include <fstream>
#include "Currency.hpp"
#include "CurrencyContainers.hpp"
#include "ExchangeBoard.hpp"
#include "ExchangeRate.hpp"

#include <sstream>
#include <string>
using namespace std;
/*
double curr_calc(mon&){
    p=mon&;
};*/

/*//Validation money in list
//Currency,Code,NumericCode
string corr_mon(mon){
    for(){
    
        if(mon currencies.){
        
        }   
    
    }
};
*/


bool getFileContent(string fileName, vector <vector<string>> & vec)
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
    // Read the next line from File untill it reaches the end.
    
    string line;
    const char delim = ',';
    while(getline(file,line))
    {
        istringstream ss(line);
        Currency currency;
        for (int i = 0; i < 4; i++){
            getline(ss, line, ',');
            if (i=0){
                cout << "Name:" << currency.getName();
                currency.setName(line);
            }
            else if(i=1){
                cout << " Code: " << currency.getCode();
                currency.setCode(line);
            }
            else if(i=2){ 
                currency.setNumericCode(stoi(line));
        }
        //if (ss)
            //vec.push_back(currency);
    }
    
    }  
    //Close The File
    file.close();
    return true;
    
}

int main(){
    
    double mon;
    string curr_in;
    string curr_out;
    vector <vector<string>> currencies; 
    vector <string> ex_rates;

//- loads currencies information from a CSV file
//- loads exchange rates from a CSV file 
   
    getFileContent("back-to-cpp/fx_converter/datasets/currencies.csv",currencies);

    cout<<currencies.size();

    return 0;
}