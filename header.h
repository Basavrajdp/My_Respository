#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st{
int roll_no;
char name[20];
float percentage;
struct st *next;
}st;
//struct st *headptr;
void add_node(st **);
int count(st *);
void print(st *);
void del_node(st *);
void show_list(st *);
void mod_record(st *);
void save(st *);
void sort_list(st *);
void del_all(st *);
void rev_list(st *);
