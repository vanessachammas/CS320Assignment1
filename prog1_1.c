#include <stdio.h>
#include <stdlib.h>

int main(){


printf("Assignment #1-1, Vanessa Chammas, vvanessachammas@gmail.com\n");
char fullName [256];

    printf("What is your name?\n");
    scanf("%[^\n]s", fullName);
    printf("Hello %s!\n", fullName);

    return 0;
}

