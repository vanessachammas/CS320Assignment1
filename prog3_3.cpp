extern "C" {
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
    }

#include "lua.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    printf("Assignment #3-3, Vanessa Chammas, vvanessachammas@gmail.com\n");
    
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    luaL_dofile(L,argv[1]);
    // opening from commandline     
    

    string str;
    string cmd;
    getline(cin,str);
    cmd = "return InfixToPostfix('"+str+"')";
    luaL_dostring(L,cmd.c_str());
    cout << luaL_checkstring(L,1) << endl;
    lua_close(L);
    return 0;
}
// when finished close file









