#include "prog2_1.hpp"
#include "prog2_3.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int main(int argc, char *argv[]) {
    cout << "Assignment #2-4, Vanessa Chammas,vvanessachammas@gmail.com" <<endl;
    vector <string> finaltokens;
    Tokenizer tokenize1;
    
    //using command line 
    ifstream file(argv[1]);
    string tokenize2;
    Parser p;
    int lineNumber = 1;
    queue < vector<string> > tokens;
    

    while(!file.eof()){
    getline(file,tokenize2);
    if(tokenize2.size() > 0){
    try{
    tokenize1.Tokenize(tokenize2);
    }
    // if bad line, throw error
    catch( const runtime_error& error){
    cout << "Error on line " << lineNumber << ":" << error.what() <<endl;
    return 0;
    }
    lineNumber++;
    }
    }

   for(int k=1; k<lineNumber; k++){
    finaltokens = tokenize1.GetTokens();
    // if parse error ourput
    if(p.Parse(finaltokens)==false){
    cout << "Parse error on line " << +k << ":";
    for(int j =0; j< finaltokens.size(); j++){
        cout << " " << finaltokens[j];
    }
    
    cout <<endl;
    return 1;
    }
    else{
    tokens.push(finaltokens);
    }
}
    
    for(int k=1; k<lineNumber; k++){
    finaltokens = tokens.front();
    tokens.pop();
    cout<<finaltokens[0];
    for(int i =1;i<finaltokens.size();i++){
    cout<< ","<<finaltokens[i];
    }
    cout<<endl;
}
}



