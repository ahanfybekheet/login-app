#pragma once
#include<iostream>
#include<fstream>
#include<sstream> 
#include<string>
#include<conio.h>
#include<regex>
#include<vector>

using namespace std;

class User{

    public:
        //declare attrs
        string username;
        string email;
        string password;
        string phoneNumber;
        int trail;

        //declare validation
        bool isValidEmail(string e);
        bool isValidUsername(string u);
        bool isValidPhoneNumber(string p);
        bool isValidPassword(string p);
        bool isFoundedUsername(string username);
        bool isFoundedEmail(string email);

        //declare getters
        string getUsername();
        string getUsernamePasswords(string username);
        string getLastPassword(string passes);
        string getEmail();
        string getPhoneNumber();
        string encryptPassword(string p);

        //declare setters
        void saveChanges(string changes);
        void setUsername();
        void setEmail();
        void setPhoneNumber();
        void setPassword();

        //declare operations
        void registration();
        void login();
        void changePassword();

        User();


};