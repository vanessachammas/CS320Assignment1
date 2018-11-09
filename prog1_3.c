#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prog1_2.h"


int main(int argc, char* argv[]){
    int N;
    N = atoi(argv[1]);

    char *token;
    char input[256];
    char sep[] = " \n";
    char tokenlist[256][256];
    char nTokenCount;

printf("Assignment #1-3, Vanessa Chammas, vvanessachammas@gmail.com\n");
    if (argc < 2){
        printf("error message\n");
        return -1;
    }

STACK *newStack = MakeStack(10);
    for(int i =1; i<=N; i++){
        printf("> ");

        fgets(input,256,stdin); //reads until
        input[strlen(input)-1]='\0'; 

        int numTokens = 0;
        char *token =strtok(input,sep); //make pointer of tokens the input line
    
    while(token!= NULL){
        strcpy(tokenlist[numTokens],token); // copies contents of tokens into []
        //printf("..%s..",tokenlist[numTokens]);
        numTokens++;
        token =strtok(NULL,sep); // neccessary 
    }

    //printf("\n nt:%d 0: %s 1: %s\n",numTokens,tokenlist[0],tokenlist[1]);

    if (numTokens == 2){
        if (strcmp(tokenlist[0],"push")==0){

        Push(newStack,atoi(tokenlist[1])); 
        }
    }

    else if (numTokens == 1){
    if (strcmp(tokenlist[0],"pop")==0){
    printf("%d\n",Pop(newStack));
    }
    }
}
}


















