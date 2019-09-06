#include "prog2_1.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
using namespace std;
 

int main(int argc, char *argv[]){
Tokenizer *tokens = new Tokenizer();
cout<< "Assignment #2-2, Vanessa Chammas, vvanessachammas@gmail.com" <<endl;

string line;
int lineNumber = 1;
vector<string> vOut;
int counter = 0;
int i;

//extra check 
std::ifstream file(argv[1]);
if (argc != 2){
cout << "this program expects a single line" << endl;
}


try {

    while(getline(file,line)) 
    {
       tokens->Tokenize(line);
       lineNumber++;
    }
}
catch (const std::runtime_error& e) 
{
    cout << "Error on line " << lineNumber << ":" << e.what() << endl;
    return 0;
}
 

file.close();
file.open(argv[1]);
// deleting tokens from heap
delete tokens;
tokens = new Tokenizer();

if(file.is_open())
{
while (file.good())
{
    getline(file,line);
    tokens->Tokenize(line);
    vOut = tokens->GetTokens();
    for (i = 0; i< vOut.size()-1; i++)
    {
        cout << vOut[i] << ",";
    } 
    cout << vOut[i]<<endl;
    counter++;
}
}

}






