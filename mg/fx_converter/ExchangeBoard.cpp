#include "ExchangeRate.hpp"
#include <vector>


//Conversion calculator
bool corr_mon(vector <ExchangeRate> &vec,string &curr_from, string &curr_to,double &mon){
    bool corr_base=false;
    bool corr_quote=false;
    double base_rate;
    double quote_rate;
    double conversion;

    for(int i=0; i<vec.size();i++){
        cout<<vec[i].getBase()<<endl;
        if ((vec[i].getBase()==curr_from)){
            corr_base= true;
            base_rate= vec[i].getBid();
        }
        if(vec[i].getQuote()==curr_to){
            corr_quote=true;
            quote_rate= vec[i].getAsk();
        }
    }

    if((corr_base=true)&&(corr_quote=true)){
        conversion=mon * base_rate * quote_rate;
        cout<<"Converting "<<mon<<" "<<curr_from<<" into "<<curr_to;
        cout<<"You now have "<<conversion<<" "<<curr_to;
        return true;
    }else{
        return false;
    }
};