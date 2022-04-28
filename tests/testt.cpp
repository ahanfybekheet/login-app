#include<regex>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;

int main(){

string p;
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
    cout<<p;
    
    }
}