#include <vector>
#include <string>
using namespace std;

class Parser{

   public:
   Parser(); // constructor with no arguments
   ~Parser();
    vector<string> *data;
    bool Parse(vector <string> tokens);
};
