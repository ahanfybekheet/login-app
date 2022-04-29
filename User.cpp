#include<iostream>
#include<fstream>
#include<sstream> 
#include<string>
#include<conio.h>
#include<regex>
#include<vector>
#include "User.h"

using namespace std;


bool User::isValidEmail(string e){
    if (regex_match(e,regex(("^(([^<>()[\\]\\.,;:\\s@\"]+(\\.[^<>()[\\]\\.,;:\\s@\"]+)*)|(\".+\"))@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$"))))
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

bool User::isValidPhoneNumber(string p){
    if (regex_match(p,regex(("^(010|011|012|015)[0-9]{8}$"))))
        return true;
    else
        return false;
}

bool User::isValidPassword(string p){
    if (true)
        return true;
    else
        return false;
}

bool User::isFoundedUsername(string username){
    ifstream dataFile;
    string tempUsername;
    dataFile.open("data.txt",ios::out|ios::app);
    for(int i =1;!dataFile.eof();i++){
        if (i%4==1){
            getline(dataFile,tempUsername);
            if (username.compare(tempUsername)==0){
                return true;
            }
        }
    }
    return false;
}

bool User::isFoundedEmail(string email){
    ifstream dataFile;
    string tempEmail;
    dataFile.open("data.txt",ios::out|ios::app);
    for(int i =2;!dataFile.eof();i++){
        if (i%4==2){
            getline(dataFile,tempEmail);
            if (email.compare(tempEmail)==0){
                return true;
            }
        }
    }
    return false;
}

string User::getUsernamePasswords(string username){
    ifstream dataFile;
    string tempUsername,passes;
    dataFile.open("data.txt",ios::out|ios::app);
    for(int i =1;!dataFile.eof();i++){
        if (i%4==1){
            getline(dataFile,tempUsername);
            if (username.compare(tempUsername)==0){
                getline(dataFile,passes);
                getline(dataFile,passes);
                getline(dataFile,passes);
                return passes;
            }
        }
    }
    return "";
}

string User::getLastPassword(string passes){
    vector<string> passwords;
    string tempPass;
    stringstream passesAsStream(passes);
    while(getline(passesAsStream,tempPass,',')){
        passwords.push_back(tempPass);
    }
    if (passwords.size() == 0){
        passwords.push_back(passes);
    }
    return passwords.at(passwords.size()-1);
}

string User::encryptPassword(string p){
    string keyWord ="aby";
    string result = "";
    //Block 1 // Make Length keyword equal to length password  
    while (keyWord.length() < p.length()){
        keyWord += keyWord;
    }
    keyWord = keyWord.substr(0,p.length()-1);
    // End Of Block 1
    for (int i = 0; i < p.length();i++){
        p[i] = toupper(p[i]);
        keyWord[i] = toupper(keyWord[i]);
        if (p[i] >= 65 && p[i] <= 90){
            result += char(65 + ((p[i]+keyWord[i])%26));
        }else{
            result += p[i];
        }
    }
    return result;
}

//declare getter
string User::getUsername(){
    return username;
    
} 

string User::getEmail(){
    return email;
}

string User::getPhoneNumber(){
    return phoneNumber;
}

void User::saveChanges(string changes){
    ofstream dataFile;
    dataFile.open("data.txt",ios::out|ios::app);
    dataFile<<changes<<endl;
    dataFile.close();
}

void User::setUsername(){
    string u;
    while (true){
        cout<<"Please, Enter your username: ";
        cin>>u;
        if (isValidUsername(u) && !isFoundedUsername(u)){
            username = u;
            break;
        }
        else if (isFoundedUsername(u)){
            cout<<"Sorry, Username already taken, Try Again!!..\n";
        }
        else{
            cout<<"Please, Enter valid username and Try Again!!..\n";
        }

    }
}

void User::setEmail(){
    string e;
    while (true){
        cout<<"Please, Enter your email: ";
        cin>>e;
        if (isValidEmail(e) && !isFoundedEmail(e)){
            email = e;
            break;
        }
        else if (isFoundedEmail(e)){
            cout<<"Sorry, Email already taken, Try Again!!..\n";
        }
        else{
            cout<<"Please, Enter valid email address and Try Again!!..\n";
        }
    }
}

void User::setPhoneNumber(){
    string p;
    while (true){
        cout<<"Please, Enter your Phonenumber: ";
        cin>>p;
        if (isValidPhoneNumber(p)){
            phoneNumber = p;
            break;
        }
        else{
            cout<<"Please, Enter valid Phone Number and Try Again!!..\n";
        }

    }   
}

void User::setPassword(){
    string p = "", pconf = "";
    int i;
    char ch;
    cout<<"Please, Enter your Password: ";
    for(i=0;(ch=getch())!='\r';){
        if(ch!=8){
            p+=ch;
            cout<<"*";
            i++;
        }else{
            i--;
            p = p.substr(0,i);
            if(i<0){
                i++;
            }else{
                cout<<"\b \b";
            }
        }
    }
    if (isValidPassword(p)){
        cout<<"\nPlease, Confirm  your password: ";
        for(i=0;(ch=getch())!='\r';){
            if(ch!=8){
                pconf+=ch;
                cout<<"*";
                i++;
            }else{
                i--;
                pconf = pconf.substr(0,i);
                if(i<0){
                    i++;
                }else{
                    cout<<"\b \b";
                }
            }
        }
        if (p.compare(pconf)==0){
            password = encryptPassword(p);
        }else{
            cout<<"\nYou Entered two different passwords, Try Again!!..\n";
            setPassword();
        }
    }else{
        cout<<"\nYou Entered Weak Password\n";
        setPassword();
    }
}

void User::registration(){
    setUsername();
    setEmail();
    setPhoneNumber();
    setPassword();
    saveChanges(username);
    saveChanges(email);
    saveChanges(phoneNumber);
    saveChanges(password);
}

void User::login(){
    string name,pass="";
    int i;
    char ch;
    
        cout<<"username: ";
        cin>>name;
        if (isFoundedUsername(name)){
            username = name;
            cout<<"password: ";
            for(i=0;(ch=getch())!='\r';){
                if(ch!=8){
                    pass+=ch;
                    cout<<"*";
                    i++;
                }else{
                    i--;
                    pass = pass.substr(0,i);
                    if(i<0){
                        i++;
                    }else{
                        cout<<"\b \b";
                    }
                }
            }
            password = encryptPassword(pass);
            if (password.compare(getUsernamePasswords(username))==0){
                cout<<"\nSuccessful login, welcome "<<username<<endl;
            }
            else{
                cout<<"\nFailed login. Try again.\n";
                trail +=1;
                if (trail ==3){
                    cout<<"You is denied access to the system\n";
                    exit(0);
                }
                login();
            }
        }else{
            cout<<"username is not exit\n";
            login();
        }
}

User::User(): trail(0){}



