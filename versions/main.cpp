#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<regex>

using namespace std;


int userChoise;
void enterValidChoise(string promptMsg,int min,int max);
void registering();

class User{
    private:
        //declare attrs and private methods
        string username;
        string email;
        string password;
        string phoneNumber;
        bool isValidEmail(string e){
            if (regex_match(e,regex(("^(([^<>()[\\]\\.,;:\\s@\"]+(\\.[^<>()[\\]\\.,;:\\s@\"]+)*)|(\".+\"))@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$"))))
                return true;
            else
                return false;
        }
        bool isValidUsername(string u){
            if (regex_match(u,regex(("^([a-zA-Z]|-)+$"))))
                return true;
            else
                return false;
        }
        bool isValidPhoneNumber(string p){
            if (regex_match(p,regex(("^01[0-9]{9}$"))))
                return true;
            else
                return false;
        }
        bool isValidPassword(string p){
            if (true)
                return true;
            else
                return false;
        }
        // void encryptPassword(string p);
        // void decryptPassword(string p);
        void saveChanges(string changes){
            ofstream dataFile;
            dataFile.open("data.txt",ios::out|ios::app);
            dataFile<<changes<<endl;
            dataFile.close();
        }
    public:
        //declare getter
        string getUsername(){
            return username;
            
        } 
        string getEmail(){
            return email;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }
        //declare setter
        void setUsername(){
            string u;
            while (true){
                cout<<"Please, Enter your username: ";
                cin>>u;
                if (User::isValidUsername(u)){
                    username = u;
                    break;
                }
                else{
                    cout<<"Please, Enter valid username and Try Again!!..\n";
                }

            }
        }
        void setEmail(){
            string e;
            while (true){
                cout<<"Please, Enter your email: ";
                cin>>e;
                if (User::isValidEmail(e)){
                    email = e;
                    break;
                }
                else{
                    cout<<"Please, Enter valid email address and Try Again!!..\n";
                }

            }
        }
        void setPhoneNumber(){
            string p;
            while (true){
                cout<<"Please, Enter your Phonenumber: ";
                cin>>p;
                if (User::isValidPhoneNumber(p)){
                    phoneNumber = p;
                    break;
                }
                else{
                    cout<<"Please, Enter valid Phone Number and Try Again!!..\n";
                }

            }   
        }
        void setPassword(){
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
                    break;
                }
                else{
                    cout<<"Please, Enter valid password and Try Again!!..\n";
                }

            }
        }
        ~User(){
            saveChanges(username);
            saveChanges(email);
            saveChanges(phoneNumber);
            saveChanges(password);
        }


};

int main(){
    
    enterValidChoise("1- Register \n2- Login \n3- Change Password \n4- Exit",1,4);
    switch (userChoise)
        {
        case 1:
            registering();
            break;
        
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

void registering(){
    User user;
    user.setUsername();
    user.setEmail();
    user.setPhoneNumber();
    user.setPassword();
}