#include <vector>
#include <unordered_map>
#include <algorithm>

#include "ExchangeRate.hpp"
#include "ExchangeBoard.hpp"
//Function to find value
/*double const get_ba(unordered_map<string, unordered_map<string,double>> &uask,  const string &curr_from, const string &curr_to,const double &amount){

    for(const auto& elem:uask){
        for(const auto& quote:elem.second){
            if((elem.first==curr_from)&&(quote.first==curr_to)){
                return (amount*quote.second)

            }else if(elem.first){

            }
            else{
                return 0;
            }
        }
    }
}
*/

//Select conversion yielding maximum num
double maxCurrency(unordered_map<string, double> curr_to_amount){
    double current_max = 0;
    string curr_conv;
    
    for(const auto& it:curr_to_amount){
        if (it.second>current_max){
            curr_conv=it.first;
            current_max=it.second;
        }
    }
    return current_max;
}

double const intermed(unordered_map<string, unordered_map<string,double>> &ubid,unordered_map<string, unordered_map<string,double>> &uask, const string &curr_from, const string &inter, const string &curr_to,const double &amount, const string& curr_base){
    if((curr_base=="Y")||(curr_base=="y")){
        if (ubid[inter][curr_to]){
            double from_inter=ubid[curr_from][inter];
            double inter_to=ubid[inter][curr_to];
            return(amount*from_inter*inter_to);                
        }
        else if(uask[curr_to][inter]){
            double from_inter=ubid[curr_from][inter];
            double inter_to=uask[curr_to][inter];
            return(amount*from_inter*inter_to);
        }

    }else if((curr_base=="N")||(curr_base=="n")){
        if (ubid[inter][curr_to]){
            double from_inter=uask[curr_from][inter];
            double inter_to=ubid[inter][curr_to];
            return(amount*from_inter*inter_to);
        }                
        else if(uask[curr_to][inter]){
            double from_inter=uask[curr_from][inter];
            double inter_to=uask[curr_to][inter];
            return(amount*from_inter*inter_to);
        }
    }
    return 0;
};


//Conversion calculator
double const corr_mon(unordered_map<string, unordered_map<string,double>> &ubid,unordered_map<string, unordered_map<string,double>> &uask,const string &curr_from, const string &curr_to, const double &amount){
    unordered_map<string, double> curr_to_amount;
    double convers;
    vector<string> base_curr;

    //Create a vector for base currencies
    for(const auto& elem:ubid){
        base_curr.push_back(elem.first);
    }
    
    /*if((ubid.find(curr_from))OR(ubid.find(curr_to))||(uask.find(curr_from))||(uask.find(curr_to))){
    
    }else{
        cout<<"Invalid input. Please input a valid currency code"<<endl;
        return false;
    }*/

    //Check if invalid input and conversion to be done
    int j=0;
    for(const auto& base:ubid){
        j++;
        int k=0;
        for(const auto& quote:base.second){
            k++;
            //Check if currency from is a base currency
            if(curr_from==base.first){
                if (quote.first==curr_to){
                    convers=amount*quote.second;
                    curr_to_amount[curr_to]=convers;
                    cout<<amount<<" "<<quote.first<<endl;
                }
                else if (quote.first!=curr_to){
                    if (find(base_curr.begin(),base_curr.end(),quote.first)!=base_curr.end()){
                        convers=intermed(ubid,uask,curr_from,quote.first,curr_to, amount,"y");
                        curr_to_amount[quote.first]=convers;
                        cout<<amount<<"fdfd "<<quote.second<<endl;
                        cout<<convers<<endl;
                        cout<<curr_to_amount[quote.first]<<endl;
                    }

                    
                }
            }
            //Check if currency from is a quote currency
            if(curr_from==quote.first){
                if(base.first==curr_to){
                    convers=amount*uask[base.first][quote.first];
                    curr_to_amount[base.first]=convers;
                    cout<<amount<<"aaaa "<<uask[base.first][quote.first]<<endl;
                    cout<<convers<<endl;
                    cout<<curr_to_amount[base.first]<<endl;
                }
                else if(quote.first!=curr_to){
                    if (find(base_curr.begin(),base_curr.end(),quote.first)!=base_curr.end()){
                        convers=intermed(ubid,uask,curr_from,quote.first,curr_to, amount,"n");
                        curr_to_amount[quote.first]=convers;
                        cout<<amount<<" ppppp"<<uask[0][1]<<endl;
                        cout<<convers<<endl;
                        cout<<curr_to_amount[quote.first]<<endl;
                    }
                }
            }
            
        }
    }
    double conversion=maxCurrency(curr_to_amount);
    cout<<amount<<" "<<curr_from<<" successfully changed to "<<conversion<<" "<<curr_to;
    return conversion;
};

