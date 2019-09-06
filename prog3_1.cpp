#include "lua.hpp"
#include "lauxlib.h"
#include "lua.h" 
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
       cout << "Assignment #3-1, Vanessa Chammas, vvanessachammas@gmail.com"<< endl;
        
        lua_State *L = luaL_newstate();
        luaL_openlibs(L);
        
        luaL_dofile(L,argv[1]);
        lua_close(L);
    
        return 0;
       }
// opening file and closing
        
