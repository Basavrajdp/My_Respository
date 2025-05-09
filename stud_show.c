#include "header.h"
void show_list(st *hp)
{
	struct st *ptr=hp;
	if(ptr==0)
	{
		printf("no node are present\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->roll_no,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
	return;
}
int count(st *hp)
{
	struct st *ptr=hp;
	if(ptr==0)
	{
		printf("no node are present\n");
		return 0;
	}
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
