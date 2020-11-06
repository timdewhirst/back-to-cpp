#include "ExchangeRate.hpp"
#include <vector>
#include <algorithm>


double const if_ask(unordered_map<string, unordered_map<string,double>> &ask,  const string &curr_from, const string &curr_to,const double &amount){
    for(const auto& elem:ask){
        for(const auto& quote:elem.second){
            if((elem.first==curr_from)&&(quote.first==curr_to)){
                return(amount*quote.second);
            }else{
                return 0;
            }
        }
    }
}


double conv from intermediary(){
    
};

//Conversion calculator
bool const corr_mon(unordered_map<string, unordered_map<string,double>> &bid,unordered_map<string, unordered_map<string,double>> &ask,const string &curr_from, const string &curr_to, const double &amount){
    bool corr_base=false;
    bool corr_quote=false;
    double base_rate;
    double quote_rate;
    double conversion;

    //Check if conversion can be done
    for(const auto& elem:bid){
                if (){
                conversion=amount*quote.second;}
            }
            if(elem.first==curr_to)
            else if((elem.first==curr_from)&&(quote.first!=curr_to)){
                
            }
            else if((elem.first==curr_to)&&(quote.first==curr_from)){
                 conversion=if_ask(ask,curr_from,curr_to,amount);
            }
        }
    }

/*
    //find(vec.begin(),vec.end(),curr_from);
    

        cout<<vec[i].getBase()<<endl;
        
        if ((vec[i].getBase()==curr_from)){
            cout<<curr_from<<endl;
            corr_base= true;
            base_rate= vec[i].getBid();
        }
        if(vec[i].getQuote()==curr_to){
            cout<<curr_to<<endl;
            corr_quote=true;
            quote_rate= vec[i].getAsk();
        }
    }

    if((corr_base=true)&&(corr_quote=true)){
        conversion=amount * base_rate * quote_rate;
        cout<<"Converting "<<amount<<" "<<curr_from<<" into "<<curr_to;
        cout<<"You now have "<<conversion<<" "<<curr_to;
        return true;
    }else{
        return false;
    }
};