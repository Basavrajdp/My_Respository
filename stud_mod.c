#include "header.h"
void roll_no(st *);
void name_mod(st *);
void percentage(st *);
char op;
void mod_record(st *p)
{
	st *hp=p;
	if(p==0)
	{
		printf("no nodes are present\n");
		return;
	}
	else
	{
		while(1)
		{
			printf("r :to search a rollno\nn :to search a name\np :to search percentage\n");
			printf("enter the option\n");
			scanf(" %c",&op);
			switch(op)
			{
				case 'r':roll_no(hp);break;
				case 'n':name_mod(hp);break;
				case 'p':percentage(hp);break;
				default:printf(" INVALID  \n");
			}
			return;
		}
	}
}
void roll_no(st *hp)
{
	struct st *ptr=hp;
	static int c2=1;	
	int num,flag=0;
	printf("enter the num\n");
	scanf("%d",&num);
	while(ptr)
	{
		if((ptr->roll_no)==num)
		{
			struct st new;
			printf("name and percentage\n");
			scanf("%s",new.name);
			scanf("%f",&new.percentage);
			strcpy(ptr->name,new.name);
			ptr->percentage=new.percentage;
			flag=1;
			c2++;
			if(c2>1)
			{
				c2=1;
				break;
			}

		}
		ptr=ptr->next;

	}
	if(flag==0)
		printf("roll no is not found\n");
}
void name_mod(st *hp)
{
	char s[20],flag=0;
	static int c2=1;
	printf("enter the string\n");
	scanf("%s",s);
	struct st *ptr=hp;
	while(ptr)
	{
		if((strcmp(ptr->name,s))==0)
		{
			struct st new;
			printf("name and percentage\n");
			scanf("%s",new.name);
			scanf("%f",&new.percentage);
			strcpy(ptr->name,new.name);
			ptr->percentage=new.percentage;
			flag=1;
			c2++;
			if(c2>1)
			{
				c2=1;
				break;
			}
		}
		ptr=ptr->next;
	}
	if(flag==0)
		printf("name is not found\n");

}
void percentage(st *hp)
{
	float per;int flag=0;
	static int c2=1;
	printf("enter the percentage\n");
	scanf("%f",&per);
	struct st *ptr=hp;
	while(ptr)
	{
		if((ptr->percentage)==per)
		{
			struct st new;
			printf("name and percentage\n");
			scanf("%s",new.name);
			scanf("%f",&new.percentage);
			strcpy(ptr->name,new.name);
			ptr->percentage=new.percentage;
			flag=1;
			c2++;
			if(c2>1)
			{
				c2=1;
				break;
			}
		}
		ptr=ptr->next;
	}
	if(flag==0)
		printf("percentage is not found\n");
}
















