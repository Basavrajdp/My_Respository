#include "header.h"
void name_sort(st *hp);
void percentage_sort(st *hp);
void sort_list(st *p)
{
	st *hp=p;
	char op;
	if(p==0)
		printf("no nodes are present\n");
	else
	{
		while(1)
		{
			printf("n :sort with names\np :sort with percentage\n");
			printf("enter the option\n");
			scanf(" %c",&op);
			switch(op)
			{
				case 'n': name_sort(hp);break;
				case 'p': percentage_sort(hp);break;
				default: printf(" INVALID  \n");
			}
			return;
		}
	}
}
void name_sort(st *hp)
{
	struct st *p1=hp,*p2,temp;
	int c=count(p1),i,j,len,len1;
	if(p1==0)
	{
		printf("no nodes are present\n");
		return;
	}
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-i-1;i++)
		{
			if((strcmp(p1->name,p2->name))>0)
			{
				temp.roll_no=p1->roll_no;
				strcpy(temp.name,p1->name);
				temp.percentage=p1->percentage;

				p1->roll_no=p2->roll_no;
				strcpy(p1->name,p2->name);
				p1->percentage=p2->percentage;

				p2->roll_no=temp.roll_no;
				strcpy(p2->name,temp.name);
				p2->percentage=temp.percentage;


			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}
void percentage_sort(st *hp)
{
	struct st *p1=hp,*p2,temp;
	int c=count(p1),i,j;
	if(p1==0)
	{
		printf("no nodes are present\n");
		return;
	}
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-i-1;j++)
		{
			if((p1->percentage)<(p2->percentage))
			{
				temp.roll_no=p1->roll_no;
				strcpy(temp.name,p1->name);
				temp.percentage=p1->percentage;

				p1->roll_no=p2->roll_no;
				strcpy(p1->name,p2->name);
				p1->percentage=p2->percentage;

				p2->roll_no=temp.roll_no;
				strcpy(p2->name,temp.name);
				p2->percentage=temp.percentage;


			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

















