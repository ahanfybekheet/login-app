#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

using namespace std;
int shifts ,len;

struct user_information{
 int id;
 char password[20];
};

int main()
{
    user_information e1 ;
    int i;
    i=0;
    cout<<"please enter your id : ";
    cin>>e1.id;
    cout<<"please enter your password : ";
    char ch;
    for(i=0;(ch = _getch())!='\r';){
        if(ch != '\b'){
            e1.password[i]=ch;
            cout<<"*";
            i++;
        }
        else{
             i--;
             if(i<0){
                i++;
             }
             else{
                cout<<"\b \b";
             }
        }
    }
    e1.password[i]='\0';
    cout<<endl<<e1.password;
}
