#include "header.h"
int c1=0;
int roll(st *);
void name(st *);
void del_node(st *p)
{
	st *hp=p;
	char op;
	if(p==0)
	{
		printf("no nodes are present\n");
		return;
	}
		while(1)
		{
			printf("\nr :enter roll to del\nn :enter name to del\n");
			printf("enter the option\n");		
			scanf(" %c",&op);
			switch(op)
			{
				case 'r': roll(hp);break;
				case 'n': name(hp);break;
				default:printf("invalid\n");
			}
			return;
		}
}
int roll(st *hp)
{
	struct st *del=hp,*prev,*new=malloc(sizeof(struct st));
	int num,c,flag=0,c2=1;
	if(del==0)
	{
		printf("node is not found\n");
		return 0;
	}
	printf("enter the number\n");
	scanf("%d",&num);
	while(del)
	{
		if((del->roll_no)==num)
		{
			c1=del->roll_no;
			if(del==hp)
			{
				hp=del->next;
			}
			else
				prev->next=del->next;
			free(del);
			flag=1;
		}
		prev=del;
		del=del->next;
	}
	if(flag==0)
		printf("no roll_no is not presnt\n");
}
void name(st *hp)
{
	struct st *del=hp,*prev;
	char s[20],flag=0;int c2=0,num;
	if(del==0)
	{
		printf("node is not found\n");
		return;
	}
	printf("enter the name\n");
	scanf("%s",s);	
	while(del)
	{

		if((strcmp(del->name,s))==0)
		{
			c2++;
			c1=del->roll_no;
			while(c2>1)
			{
				printf("which roll number\n");
				printf("%d %s %f\n",del->roll_no,del->name,del->percentage);
		        	scanf("%d",&num);
				while(num==del->roll_no)
				{
					if(del==hp)
						hp=del->next;
					else
						prev->next=del->next;
				}
			}
			free(del);
			flag=1;
		}
		prev=del;
		del=del->next;
	}
	if(flag==0)
		printf("no name is not found\n");
}






