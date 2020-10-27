// My name is Arthur Almeida and I wrote this program. This program goes through a file of a list in the format first_last_phone and creates a new file with a list of only the phone numbers.

#include <stdio.h>


void extract_phone (char *input, char *phone);

int main() {
  
  char fileName[100];
  char phone [14];
  char input [100];
  printf("Enter the file name: ");
  scanf("%s", fileName);
  printf("\nOutput file name: phone_input_names.txt\n");
  FILE* file = fopen(fileName, "r");
  FILE* finalFile = fopen ("phone_input_names.txt", "w");
  
 
  while (fgetc(file)!= EOF){
    fscanf(file,"%s", input);
    extract_phone(input, phone);
    phone[13]='\0';
    fputs(phone, finalFile);
    fputs("\n", finalFile);
 
  }
  
}
// this function goes through the list and gives back only the phone number from each contact. 
void extract_phone (char *input, char *phone){
  int i=0;
  int j=0;
  
  while (input[i]!='('){
    i++;
  }
  while(input[i]!='\0'){
    phone[j]=input[i];
    i++;
    j++;
  }
}

