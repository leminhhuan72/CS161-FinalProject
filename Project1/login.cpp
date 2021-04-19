#include "login.h"

void login()
{
     for(int i =0 ; i < 6 ;++ i)
       cout<< '\t';
   cout<<"THIS IS HCMUS PORTAL "<<"\n";
   for(int i =0 ; i < 3 ;++ i)
       cout<< '\t';
    cout<< "ARE YOU STUDENT OR STAFF ( Enter 1 if you are student , 2 if you are staff "<<endl;
    int n ; 
    cin>> n ; 
    while(n!=1 &&n!=2)
    {
        cout<<"Please input 1 if you are student or 2 if you are staff";
        cin>>n;
    }
     
    if(n==1)
    {
      studentLogin();
    }
    else if(n==2)
    {
      staffLogin();
    }
    
  

}