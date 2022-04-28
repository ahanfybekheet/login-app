#include<regex>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>


using namespace std;

class User{
    private:
        //declare attrs and private methods
        string username;
        string email;
        string password;
        string phoneNumber;
        bool isValidEmail(string e);
        bool isValidUsername(string u);
        bool isValidPhoneNumber(string p);
        bool isValidPassword(string p);
        void encryptPassword(string p);
        void decryptPassword(string p);
        void saveChanges(string changes);
    public:
        //declare getter
        string getUsername();
        string getEmail();
        string getPhoneNumber();
        //declare setter
        void setUsername();
        void setEmail();
        void setPhoneNumber();
        void setPassword();


};
