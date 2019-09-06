#include "prog2_3.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

Parser::Parser(){
this->data = new vector<string>();
}
Parser::~Parser(){
delete this->data;
}


bool Parser::Parse(vector <string> tokens){

vector<string> validTokenone= {"pop","add","sub","mul","div","mod","skip"};
vector<string> validTokentwo= {"push","save","get"};
bool bFound;
bool bDigit = true;
string token1;
string token2;

// first for individual token, only be valid if in the first vector string
if( tokens.size()==1)
token1 =tokens[0];
bFound = std::find(validTokenone.begin(), validTokenone.end(), token1) != validTokenone.end();
if(bFound){
return true;
}
//if two tokens and in the second vector string
else if(tokens.size() == 2)
{
token1 = tokens[0];
token2 = tokens[1];
bFound = std::find(validTokentwo.begin(), validTokentwo.end(), token1) != validTokentwo.end();

// if two tokens and second one is a digit
for(int i =0; i<token2.size() && bDigit; i++)
{
    if(!isdigit(token2.at(i)))
    {
        bDigit = false;
    }
}
if(bFound && bDigit )
return true;


}
return false;
}



