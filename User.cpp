#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<regex>
#include<vector>

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
        int trail;
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
            if (regex_match(p,regex(("^(010|011|012|015)[0-9]{8}$"))))
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

        string getUsernamePassword(string username){
            ifstream dataFile;
            string tempUsername,pass;
            dataFile.open("data.txt",ios::out|ios::app);
            for(int i =1;!dataFile.eof();i++){
                if (i%4==1){
                    getline(dataFile,tempUsername);
                    if (username.compare(tempUsername)==0){
                        getline(dataFile,pass);
                        getline(dataFile,pass);
                        getline(dataFile,pass);
                        return pass;
                    }
                }
            }
            return "";
        }

        string encryptPassword(string p){
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

        void saveChanges(string changes){
            ofstream dataFile;
            dataFile.open("data.txt",ios::out|ios::app);
            dataFile<<changes<<endl;
            dataFile.close();
        }

        bool isFoundedUsername(string username){
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

        bool isFoundedEmail(string email){
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

        void setEmail(){
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

        void setPhoneNumber(){
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

        void setPassword(){
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

        void registration(){
            setUsername();
            setEmail();
            setPhoneNumber();
            setPassword();
            saveChanges(username);
            saveChanges(email);
            saveChanges(phoneNumber);
            saveChanges(password);
        }

        void login(){
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
                    if (password.compare(getUsernamePassword(username))==0){
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

        User(): trail(0)
        {

        }


};

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