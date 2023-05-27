// dollar + quarter + dime + nickel + penny = amount(in cents)
// Evaluating the changes

#include <iostream>
using namespace std;

#define dollar 100
#define quarter 25
#define dime 10
#define nickel 5
#define penny 1

int main()
{
   int amount;
   cout<<"Enter an amount in cents :  ";
   cin>>amount;
   
   int dollar_change=0,quarter_change=0,dime_change=0,nickel_change=0,penny_change=0;
   
   if (amount!=0){
       if (amount>=100){
           dollar_change=amount/100;
           amount=amount%100;
       }
       
       if (amount>=25){
           quarter_change=amount/25;
           amount=amount%25;
       }
       
       if (amount>=10){
           dime_change=amount/10;
           amount=amount%10;
       }
       
       if (amount>=5){
           nickel_change=amount/5;
           amount=amount%5;
       }
       
       if(amount!=0){
           penny_change=amount;
       }
    }
    
    cout<<"dollar: "<<dollar_change<<endl;
    cout<<"quarter: "<<quarter_change<<endl;
    cout<<"dime: "<<dime_change<<endl;
    cout<<"nickel: "<<nickel_change<<endl;
    cout<<"penny: "<<penny_change<<endl;
   return 0;
}
