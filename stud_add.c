#include "header.h"
extern int c1;
struct st *headptr=0;
int main()
{
	char op;
	int c,i=0,c1;
	while(1)
	{		
		printf("***** STUDENT RECORD MENU *****\n");
		printf(" a :add new record\n c :count\n d :delete a node\n s :show the list\n m :modify a record\n v :save the file\n t :sort the list\n l :delete all the records\n r :reverse the list\n e :exit\n");
		printf("enter the choice:\n");
		scanf(" %c",&op);
		switch(op)
		{
			case 'a':add_node(&headptr); break;
			case 'c':c=count(headptr);
				 printf("the nodes are %d\n",c); break;
			case 'd':del_node(headptr);break;
			case 's':show_list(headptr); break;
			case 'm':mod_record(headptr); break;
			case 'v':save(headptr); break;
			case 't':sort_list(headptr); break;
			case 'l':del_all(headptr);break;			
			case 'r':rev_list(headptr);break;
			case 'e':exit(0);
			default : printf("    INVALID    \n");
		}
	}
}
void add_node(st **p)
{
	static int c=1;
	struct st  *new=malloc(sizeof(struct st)),*ptr;
	printf("enter the node name and percentage\n");
	if(c1>0)
		printf("%d \t",c1);
	else	
		printf("%d \t",c);
	scanf("%s %f",new->name,&new->percentage);
	if(c1>0)
	{
		new->roll_no=c1;
		c1=0;
		c--;
	}
	else
		new->roll_no=c;
	if(*p==0)
	{
		new->next=*p;
		*p=new;
	}
	else
	{
		ptr=*p;
		while(ptr->next!=0&&(new->roll_no)>(ptr->next->roll_no))
			ptr=ptr->next;
		new->next=ptr->next;
		ptr->next=new;

	}
	c++;
}

