#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

struct request *load();
void save(struct request *list);
struct request *append(struct request *list);
struct request *delete(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = load();  
  printf("Operation Code: d for removing from the list, a for appending to the list,"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'd': wait_list = delete(wait_list);
                break;
      case 'a': wait_list = append(wait_list);
		break;
      case 'p': printList(wait_list);
                break;
      case 'q': save(wait_list);
		clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * load: read file "waiting_list.txt" and store the data  *
 *       in a linked list and returns the linked list     *
 **********************************************************/

struct request *load(){
	struct request * list= NULL;
	struct request *prev, *new_node;
	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char class_name[CLASS_LEN+1];

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "r");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return NULL;
	}

        while(!feof(pFile)&&!ferror(pFile))
	{
	       if(fscanf(pFile, "%s%s%s%s", e_address, class_name, f_name, l_name)== 4)
		{

 			 new_node = malloc(sizeof(struct request));
 			 if (new_node == NULL) {
    				printf("Database is full; loding error.\n");
    				return NULL;
 			 }

			strcpy(new_node->email, e_address);	
			strcpy(new_node->class, class_name);
			strcpy(new_node->first, f_name);
			strcpy(new_node->last, l_name);
			new_node->next = NULL;



			if(list == NULL)	
				list = new_node;
			else
				prev->next = new_node;
			prev = new_node;				
				
        	}
	}
	return list;
}

/**********************************************************
 * save: write to file "waiting_list.txt" with the data   *
 *       in the linked list passed in as parameter        *
 **********************************************************/


void save(struct request *list)
{

	struct request * p;

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "w");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return;
	}
	for (p =list; p != NULL; p = p->next)
    		fprintf(pFile, "%-s %s %s %s\n", p->email, p->class, p->first,p->last);

	fclose(pFile);


}

struct request *delete(struct request *list){

 //add your code
 struct request *cur, *prev;
 char f_name[NAME_LEN+1];
 char l_name[NAME_LEN+1];
 char e_address[EMAIL_LEN+1];
 char class_name[CLASS_LEN+1];
 printf("Enter the first name:\n");
 scanf("%s", f_name);
 printf("Enter the last name:\n");
 scanf("%s", l_name);
 printf("Enter the email address:\n");
 scanf("%s", e_address);
 printf("Enter the class name:\n");
 scanf("%s", class_name);
 //search for request match match
 for (cur = list, prev = NULL;
       cur != NULL && !(strcmp(cur->email,e_address)==0 && strcmp(cur->last,l_name)==0 &&
	   strcmp(cur->first,f_name)==0 && strcmp(cur->class,class_name)==0);
       prev = cur, cur = cur->next)
    ;	

 if (cur == NULL){
	 printf("Request not found on the list\n");
	 return list;
 }

 //deletes the the request if its the first one
 if (prev==NULL){
	 list = cur->next;
 //deletes the request if its another one
 } else {
	 prev->next = cur->next;
 }
 free(cur);
 return list;

}
struct request *append(struct request *list){

 //add your code
 struct request *cur, *prev;
 struct request *new_node;
 char f_name[NAME_LEN+1];
 char l_name[NAME_LEN+1];
 char e_address[EMAIL_LEN+1];
 char class_name[CLASS_LEN+1];
 printf("Enter the first name:\n");
 scanf("%s", f_name);
 printf("Enter the last name:\n");
 scanf("%s", l_name);
 printf("Enter the email address:\n");
 scanf("%s", e_address);
 printf("Enter the class name:\n");
 scanf("%s", class_name);
//search for request match match
 for (cur = list, prev = NULL;
       cur != NULL && !(strcmp(cur->email,e_address)==0 && strcmp(cur->last,l_name)==0 &&
	   strcmp(cur->first,f_name)==0 && strcmp(cur->class,class_name)==0);
       prev = cur, cur = cur->next)
    ;
	if (cur!=NULL||prev==NULL){
	printf("This request already exists");
	return list;
	} else{
	  new_node = malloc(sizeof(struct request));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
	  strcpy(new_node->first, f_name);
	  strcpy(new_node->last, l_name);
	  strcpy(new_node->email, e_address);
	  strcpy(new_node->class, class_name);
	  new_node->next = list;
	  return new_node;
}

 
 
 return list;

}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

void clearList(struct request *list)
{
    struct request *cur = list, *prev = NULL;
    while(cur != NULL)
    {
        prev = cur;
        cur = cur->next;
        free(prev);
    }

}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
