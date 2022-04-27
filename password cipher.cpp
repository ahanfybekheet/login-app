#include <iostream>

#include <iostream>

#include <cmath>

#include <stdio.h>

#include <stdlib.h>

#include<bits/stdc++.h>

using namespace std;

int shifts ,len;

void cipher(){


    string message ;

    cout<<"please enter your message to cipher :" ;

    cin>>message;

    transform(message.begin(),message.end(),message.begin(),::toupper);

    len=message.length();


    for(int i=0;i<len;i++){

        if(int(message[i])==32){


            cout<<" ";

            continue;

        }


        if(isalpha(message[i])==0&&isdigit(message[i])==0){


            cout<<message[i];

            continue;

        }



        else{


        message[i]=int(message[i])+6 ;

        if(int(message[i])>90){

            message[i]=int(message[i])-26 ;

        }

        cout<<message[i];


        }

    }



    }



void decipher(){

    string message ;


    cout<<"please enter a message to decipher : ";

    cin>>message;

    len=message.length();

    for(int i=0;i<len;i++){

        if(int(message[i])==32){


            cout<<" ";

            continue;

        }

         if(isalpha(message[i])==0&&isdigit(message[i])==0){

            cout<<message[i];

            continue;

        }
        else{

        message[i]=int(message[i])-6;

        if(int(message[i])<65){

            message[i]=int(message[i])+26;

        }

        cout<<message[i];

        }

    }


}





int main()
{
   while(true){

        int user =0 ;

        cout<<endl<<endl;

        cout<<"Ahlan ya user ya habibi"<<endl ;

        cout<<"What do you like to do today?"<<endl;

        cout<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl<<">>";

        if (!cin) {
        // unset failbit
        cin.clear();
        // clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin>>user ;

        if (user ==1){

            system("cls");

            cipher();
        }
        else if (user ==2){

            system("cls");

            decipher();
        }

        else if (user ==3){

            exit(0);
        }

        else{
            system("cls");
            cout<<"Dose not exist please choose another num "<<endl<<endl ;
            continue;
        }
        }








    return 0;
}
