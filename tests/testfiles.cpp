#include<iostream>
#include<fstream>
#include<limits>


using namespace std;
std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
int main(){
    fstream test;
    string line;
    test.open("test.txt",ios::out|ios::app);
    GotoLine(test,3);
    test>>line;
    cout<<line;
    cin.get();
    string text;
    while(getline(test,text)){
        cout<<text;
    }
}