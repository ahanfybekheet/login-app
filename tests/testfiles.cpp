#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream test;
    test.open("test.txt",ios::out|ios::app);
    test<<"hello world";
    test.close();
    ifstream test2;
    test2.open("test.txt",ios::out|ios::app);
    string text;
    while(getline(test2,text)){
        cout<<text;
    }
}