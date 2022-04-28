#include "User.h"
#include<regex>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;

bool User::isValidEmail(string e){
    if (regex_match(e,regex(("^(([^<>()[\\]\\.,;:\\s@\"]+(\\.[^<>()[\\]\\.,;:\\s@\"]+)*)|(\".+\"))@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$"))))
        return true;
    else
        return false;
}

bool User::isValidPhoneNumber(string p){
        if (regex_match(p,regex(("^01[0-9]........$"))))
        return true;
    else
        return false;
}

bool User::isValidUsername(string u){
    if (regex_match(u,regex(("^([a-zA-Z]|-)+$"))))
        return true;
    else
        return false;
}

bool User::isValidPassword(string p){
    if (regex_match(p,regex(("?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[^A-Za-z0-9])(?=.{8,}"))))
        return true;
    else
        return false;
}

string User::getEmail(){
    return email;
}

string User::getPhoneNumber(){
    return phoneNumber;
}

string User::getUsername(){
    return username;
    
} 

void User::setEmail(){
    string e;
    while (true){
        cout<<"Please, Enter your email: ";
        cin>>e;
        if (User::isValidEmail(e)){
            email = e;
            User::saveChanges(email);
            break;
        }
        else{
            cout<<"Please, Enter valid email address and Try Again!!..\n";
        }

    }
}

void User::setUsername(){
    string u;
    while (true){
        cout<<"Please, Enter your username: ";
        cin>>u;
        if (User::isValidUsername(u)){
            username = u;
            User::saveChanges(username);
            break;
        }
        else{
            cout<<"Please, Enter valid username and Try Again!!..\n";
        }

    }
}

void User::setPassword(){
    string p = "";
    int i;
    char ch;
    while (true){
        cout<<"Please, Enter your Password: ";
        for(i=0;(ch=getch())!='\r';){

        if(ch!=8){

            p+=ch;

            cout<<"*";

            i++;
        }
        else{
            i--;
            p = p.substr(0,i);
            if(i<0){
                i++;
            }
            else{
                cout<<"\b \b";
            }


        }

    }

    p[i]='\0';

        if (User::isValidPassword(p)){
            password = p;
            User::saveChanges(password);
            break;
        }
        else{
            cout<<"Please, Enter valid password and Try Again!!..\n";
        }

    }
}

void User::saveChanges(string changes){
    ofstream dataFile;
    dataFile.open("data.txt",ios::out|ios::app);
    dataFile<<changes<<endl;
    dataFile.close();
}

void User::setPhoneNumber(){
    string p;
    while (true){
        cout<<"Please, Enter your username: ";
        cin>>p;
        if (User::isValidUsername(p)){
            phoneNumber = p;
            User::saveChanges(phoneNumber);
            break;
        }
        else{
            cout<<"Please, Enter valid Phone Number and Try Again!!..\n";
        }

    }   
}