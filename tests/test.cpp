#include <iostream>

#include <iostream>

#include <cmath>

#include <stdio.h>

#include <stdlib.h>

#include<bits/stdc++.h>

#include<conio.h>


using namespace std;

int shifts ,len;

struct user_information{

 int id;

 string password;


};


int main()
{
    user_information e1 ;

    int i;

    i=0;

    cout<<"please enter your id : ";

    cin>>e1.id;

    e1.password="";

    cout<<"please enter your password : ";

    char ch;

    for(i=0;(ch=getch())!='\r';){

        if(ch!=8){

            e1.password+=ch;

            cout<<"*";

            i++;
        }
        else{
             i--;
             e1.password = e1.password.substr(0,i);
             if(i<0){
                i++;
             }
             else{
                cout<<"\b \b";
             }


        }

    }

    e1.password[i]='\0';

    cout<<endl<<"pass is: "<<e1.password;




    return 0;
}