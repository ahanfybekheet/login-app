#include<iostream>
#include "User.h"
#include "User.cpp"
using namespace std;

int8_t userChoise;


void enterValidChoise(string promptMsg,int min,int max);

int main(){
    
    enterValidChoise("1- Register \n2- Login \n3- Change Password \n4- Exit",1,4);
    switch (userChoise)
        {
        case 1:
        {
            User user;
            user.registration();
            break;
        }
        case 2:
        {
            User user;
            user.login();
            break;
        }
        default:
            break;
        }
}


void enterValidChoise(string promptMsg,int min,int max){
    while (true){
        cout<<promptMsg<<endl;
        cout<<"--> ";
        cin>>userChoise;
        if (userChoise<= max && userChoise >= min){
            break;
        }
        else
            cout<<"Please, Enter num between "<<min<<" and "<<max<<"!!..\n";
    }
    
}