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

//obtain intermediate value
double const intermed(unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>> &umap, const string &curr_from, const string &inter, const string &curr_to,const double &amount, const string& curr_base){
    
    unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>>::const_iterator got = umap.find(curr_from);
    //(*got)->first;
    if((curr_base=="Y")||(curr_base=="y")){
        if (umap[inter][curr_to]){
            double from_inter=umap[curr_from][inter]-> getBid();
            double inter_to=umap[inter][curr_to]->getBid();
            return(amount*from_inter*inter_to);                
        }
        else if(umap[curr_to][inter]){
            double from_inter=umap[curr_from][inter]-> getBid();
            double inter_to=umap[curr_to][inter]->getAsk();
            return(amount*from_inter*inter_to);
        }

    }else if((curr_base=="N")||(curr_base=="n")){
        if (umap[inter][curr_to]){
            double from_inter=umap[curr_from][inter]->getAsk();
            double inter_to=umap[inter][curr_to]->getBid();
            return(amount*from_inter*inter_to);
        }                
        else if(umap[curr_to][inter]){
            double from_inter=umap[curr_from][inter]->getAsk();
            double inter_to=umap[curr_to][inter]->getAsk();
            return(amount*from_inter*inter_to);
        }
    }
    return 0;
};


//Conversion calculator
double const corr_mon(unordered_map<string, unordered_map<string,shared_ptr<ExchangeRate>>> &umap,const string &curr_from, const string &curr_to, const double &amount){
    unordered_map<string, double> curr_to_amount;
    double convers;
    vector<string> base_curr;

    //Create a vector for base currencies
    for(const auto& elem:umap){
        base_curr.push_back(elem.first);
    }
    
    //Validation
    if(curr_from==curr_to){
        std::cout<<"Cannot exchange currency pair with same currency code";
        return 0;
    }else if(amount<=0){
        std::cout<<"Cannot exchange amount less than or equal to 0";
        return 0;
    }


    /*if((ubid.find(curr_from))OR(ubid.find(curr_to))||(uask.find(curr_from))||(uask.find(curr_to))){
    
    }else{
        cout<<"Invalid input. Please input a valid currency code"<<endl;
        return false;
    }*/

    //Check if invalid input and conversion to be done
    for(const auto& base:umap){
        for(const auto& quote:base.second){
            //Check if currency from is a base currency
            if(curr_from==base.first){
                if (quote.first==curr_to){
                    convers=amount*quote.second -> getBid();
                    curr_to_amount[curr_to]=convers;
                    std::cout<<amount<<" "<<quote.first<<endl;
                }
                else if (quote.first!=curr_to){
                    if (find(base_curr.begin(),base_curr.end(),quote.first)!=base_curr.end()){
                        convers=intermed(umap,curr_from,quote.first,curr_to, amount,"y");
                        curr_to_amount[quote.first]=convers;
                        std::cout<<amount<<"fdfd "<<quote.second<<endl;
                        std::cout<<convers<<endl;
                        std::cout<<curr_to_amount[quote.first]<<endl;
                    }

                }
            }

            //Check if currency from is a quote currency
            if(curr_from==quote.first){
                if(base.first==curr_to){
                    convers=amount*umap[base.first][quote.first]->getBid();
                    curr_to_amount[base.first]=convers;
                    std::cout<<amount<<"aaaa "<<umap[base.first][quote.first]<<endl;
                    std::cout<<convers<<endl;
                    std::cout<<curr_to_amount[base.first]<<endl;
                }
                else if(quote.first!=curr_to){
                    if (find(base_curr.begin(),base_curr.end(),quote.first)!=base_curr.end()){
                        convers=intermed(umap,curr_from,quote.first,curr_to, amount,"n");
                        curr_to_amount[quote.first]=convers;
                        std::cout<<amount<<" ppppp"<<umap[quote.first][base.first]<<endl;
                        std::cout<<convers<<endl;
                        std::cout<<curr_to_amount[quote.first]<<endl;
                    }
                }
            }
            
        }
    }
    double conversion=maxCurrency(curr_to_amount);
    std::cout<<amount<<" "<<curr_from<<" successfully changed to "<<conversion<<" "<<curr_to;
    return conversion;
};
