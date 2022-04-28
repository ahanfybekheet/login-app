#include<iostream>
#include "User.h"

using namespace std;

int8_t userChoise;


void enterValidChoise(string promptMsg,int min,int max);
void registering();

int main(){
    
    enterValidChoise("1- Register \n2- Login \n3- Change Password \n4- Exit",1,4);

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

void registering(){
    User user;
    user.setUsername();
    user.setEmail();
    user.setPhoneNumber();
    user.setPassword();

}
