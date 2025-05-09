#include "header.h"
void save_exit(st *);
void save(st *p)
{
	st *hp=p;
	char op;
	if(hp==0)
	{
		printf("no nodes are present\n");
		return;
	}
	else
	{	
		while(1)
		{
			printf("s :save and exit\ne :exit without save\n");
			printf("enter option\n");
			scanf(" %c",&op);
			switch(op)
			{
				case 's':save_exit(hp);break;
				case 'e':return;
				default:printf("  INVALID  \n");
			}
		}
	}
}
void save_exit(st *hp)
{
	struct st *ptr=hp;
	if(ptr==0)
	{
		printf("No Record Found\n");
		return;
	}
	FILE *fp;
	fp=fopen("data","w");
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->roll_no,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}

fclose(fp);
}
