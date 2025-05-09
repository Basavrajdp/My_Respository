#include "header.h"
void del_all(st *p)
{
	struct st *del=p;
	if(p==0)
	{
		printf("no record is found\n");
		return;
	}
	else
	{
		while(del)
		{
			p=del->next;
			free(del);
			del=p;
		}
		printf("all records are deleted\n");

	}
}
