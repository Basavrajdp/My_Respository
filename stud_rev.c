#include "header.h"
void rev_list(st *p)
{
	st *hp=p;
	int i=0,c=count(hp);
	struct st **s=malloc(sizeof(struct st)*c),*ptr=p;
	if(ptr==0)
	{
		printf("no nodes are present\n");
		return;
	}	
	while(ptr)
	{
		s[i]=ptr;
		ptr=ptr->next;
		i++;
	}
	for(i=1;i<c;i++)
		s[i]->next=s[i-1];
	s[0]->next=0;
	p=s[c-1];
}
