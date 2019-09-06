#include <string>
#include <vector>
#include <stdlib.h>
#include <exception>
#include <queue>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "prog2_1.hpp"
using namespace std;

Tokenizer::Tokenizer(){
this->data = new queue < vector <string> > ();
//queue< vector<string> > *data;
//this->data = new vector<string>();
}

Tokenizer::~Tokenizer(){
delete this->data;
} // this is deconstruct

void Tokenizer::Tokenize(string Tokenize)
{
    // declaring my varibles and the vector string ill use for proper tokens
    vector<string> validTokens=     {"push","pop","add","sub","mul","div","mod","skip","save","get"};
    vector<string> line;
    int i;
    bool bDigit = true;
    bool bFound = false;
    string singleToken;
    stringstream check1(Tokenize); //check1 is my stringstream name 
    while(!check1.eof())
    {  //end of file check
    bDigit = true;
    check1 >> singleToken;
    //checking if any token is in the vector string
    bFound = std::find(validTokens.begin(), validTokens.end(), singleToken) != validTokens.end();


// checking for if the token could be a digit
for(i=0; i<singleToken.size() && bDigit; i++)
{
    
    if(!isdigit(singleToken.at(i)))
    {
       
        bDigit = false;
    }
}

//if its neither we dont want it
if  (!bDigit && !bFound)
{
       throw std::runtime_error(" Unexpected token: " + singleToken);
}
    

line.push_back(singleToken);
}
this->data->push(line);
}


vector<string> Tokenizer::GetTokens(){
vector<string>value = this->data->front();
this->data->pop();

    return value;

}



