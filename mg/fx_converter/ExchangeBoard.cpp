#include <vector>
#include <unordered_map>
#include <algorithm>

#include "ExchangeRate.hpp"

//Conversion calculator
bool const corr_mon(unordered_map<string, unordered_map<string,double>> &umap,const string &curr_from, const string &curr_to, const double &mon){
    bool corr_base=false;
    bool corr_quote=false;
    double base_rate;
    double quote_rate;
    double conversion;

    //Check if conversion can be done


/*
    //find(vec.begin(),vec.end(),curr_from);
   for(int i=0; i<umap.size();i++){
     

        //cout<<vec[i].getBase()<<endl;
        cout<<umap.size()<<endl;
        if ((umap[i].getBase()==curr_from)){
            //cout<<curr_from<<endl;
            corr_base= true;
            base_rate= umap[i].getBid();
        }
        if(umap[i].getQuote()==curr_to){
            //cout<<curr_to<<endl;
            corr_quote=true;
            quote_rate= umap[i].getAsk();
        }
    }
*/
    if((corr_base=true)&&(corr_quote=true)){
        conversion=mon * base_rate * quote_rate;
        cout<<"Converting "<<mon<<" "<<curr_from<<" into "<<curr_to;
        cout<<"You now have "<<conversion<<" "<<curr_to;
        return true;
    }else{
        return false;
    }
};
