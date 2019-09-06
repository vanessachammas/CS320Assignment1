#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Tokenizer{
   public:
 //  queue < vector<string> > tokens;
   Tokenizer();
   ~Tokenizer();
   void Tokenize(string Tokenize);
   vector<string> GetTokens();
 
    private:
   queue< vector<string> > *data;
    //vector<string> *data;

    

 };
