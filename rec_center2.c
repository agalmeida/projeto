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

struct request *add(struct request *list);
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

  struct request *wait_list = NULL;  
  printf("Operation Code: a for adding to the ordered list,"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = add(wait_list);
		break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct request *add(struct request *list){

 struct request *cur, *prev;
 struct request *new_node;
 char f_name[NAME_LEN+1];
 char l_name[NAME_LEN+1];
 char e_address[EMAIL_LEN+1];
 char class_name[CLASS_LEN+1];


 //collects the data
 
 printf("Enter the email address:\n");
 scanf("%s", e_address);
 printf("Enter the class name:\n");
 scanf("%s", class_name);
 printf("Enter the first name:\n");
 scanf("%s", f_name);
 printf("Enter the last name:\n");
 scanf("%s", l_name);

 if (list==NULL){
  printf("it is emppty");
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
    
	 if (list!=NULL){
	  new_node = malloc(sizeof(struct request));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
    printf("does this");
	  strcpy(new_node->first, f_name);
	  strcpy(new_node->last, l_name);
	  strcpy(new_node->email, e_address);
	  strcpy(new_node->class, class_name);

    for (cur = list, prev = NULL;
       cur != NULL && strcmp(cur->class, class_name)>0;
       prev = cur, cur = cur->next){
         printf("diff class");
       }
    if (cur==NULL){
      prev->next = new_node;
		  new_node->next= cur;
    }
	  new_node->next = cur->next;
    cur->next = new_node;
	  return list;
}


  return list;
}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  printf("\nEmail\t\t\t\t\t\tFirst Name\tLast Name\t\t"
         "class\n");
  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/*************************************************************
 * clearList: release the memory in the linked list passed   *
 * in as parameter                                           *
 *************************************************************/


void clearList(struct request *list)
{

 
  struct request *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
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
