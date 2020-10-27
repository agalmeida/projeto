#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //toupper(char c) function
//My name is Arthur Gusmao de Almeida and this is my consonants program. This program tests analyzes the user input
//and gives back all consonants they entered. This is the updated version for the second part of project 5
int main(int argc, char* argv[])
{
  int i;
  int j;
  char consonants [] = {'q','w','r','t','y','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};

  if (argc == 1){
    printf("Usage: ./a.out input");
    return 0;
  }
  for (i=0; argv[1][i] != '\0';i++){
    for (j=0 ; j<=21; j++ ){
      if (argv[1][i]==consonants[j])
        putchar(argv[1][i]);
      else if(argv[1][i]== toupper(consonants[j]))
        putchar(argv[1][i]);
    }
  }

  return 0;
}
