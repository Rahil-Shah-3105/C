/* Circularly Linked List (Basic Operations) - Program to create a Circularly linked list abstract data type and perform various operations on it (Variable first and last declared globally) */

#include  <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#define  NULL  0

/* Assume that the data portion of each node consists of ONLY an integer.*/
struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  node  *first=NULL ;
struct  node  *last=NULL ;
/* first and last are global variables and need not be passed to any function. Any changes made to variables first and last by any of the functions in the program will be reflected in the entire program */

/* This function is responsible for creating the Circularly Linked List right from the BEGINNING. */
void  create()
{
fprintf(stderr, ">>> Entering create()\n");
  int  i , n ;
  struct  node  *pnode , *p ;

  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;
	fprintf(stderr, "create(): pnode → %d\n", pnode);
    if(pnode==NULL)
    {
      printf("Memory overflow. Unable to create.\n") ;
      return ;
    }

    scanf("%d",&pnode->data) ;

    if(first==NULL)
	fprintf(stderr, "Exception in create(): %d\n", errno);
	 first=last=pnode ;
	fprintf(stderr, "create(): first → %d\n", first);
    else
    {
	  last->next=pnode ;
	  last=pnode ;    /* last keeps track of last node */
    }

    last->next=first ;
  }
fprintf(stderr, "<<< Exiting create()\n");
}

/* This function will delete a node with value k from the Linked List if such a node exists */
void  deletenode(int  k)
{
fprintf(stderr, ">>> Entering deletenode(k=%d)\n", k);
  struct  node  *p , *follow ;

  /* searching the required node */
  p=first ;
fprintf(stderr, "deletenode(k=%d): p → %d\n", k, p);
  follow=NULL ;
fprintf(stderr, "deletenode(k=%d): follow → %d\n", k, follow);
  while(follow!=last)
  {
    if(p->data==k)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(follow==last)
    printf("Required node not found.\n") ;
  else
  {
    if(p==first&&p==last)  /* deleting the one and the only node */
	  first=last=NULL ;
	fprintf(stderr, "deletenode(k=%d): first → %d\n", k, first);
    else if(p==first)       /* deleting the first node */
    {
      first=first->next ;
      last->next=first ;
    }
    else if(p==last)      /* deleting the last node */
    {
      last=follow ;
      last->next=first ;
    }
    else		/* deleting any other node */
      follow->next=p->next ;

    free(p) ;
  }
fprintf(stderr, "<<< Exiting deletenode(k=%d)\n", k);
}

/* This function will go through all the nodes of Linked List exactly once and will display data value of each node */
void  traverse()
{
fprintf(stderr, ">>> Entering traverse()\n");
  struct  node  *p , *follow ;
  if(first==NULL)
    printf("Circularly Linked List Empty") ;
  else
  {
    printf("Circularly Linked List is as shown: \n") ;

    p=first ;
	fprintf(stderr, "traverse(): p → %d\n", p);
    follow = NULL ;
    while(follow!=last)
	fprintf(stderr, "traverse(): follow → %d\n", follow);
    {
      printf("%d " , p->data) ;
      follow=p ;
      p=p->next ;
    }

    printf("\n") ;
  }
fprintf(stderr, "<<< Exiting traverse()\n");
}

void main()
{
fprintf(stderr, ">>> Entering main()\n");
  int  x , k , ch ;
  clrscr() ;
  do
  {
    printf("\n Menu: \n") ;
    printf("1:Create Linked List \n") ;
    printf("2:Delete Node \n") ;
    printf("3:Traverse \n") ;
    printf("4:Exit \n") ;

    printf("\nEnter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      create() ;
      break ;

      case 2:
      printf("Enter the data value of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(k) ;
      break ;

      case 3:
      traverse() ;
      break ;

      case 4:
      break ;
    }
 }
 while(ch!=4) ;

 getch() ;
}



