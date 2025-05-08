#include <bits/stdc++.h>
using namespace std;
typedef struct dll
{
	struct dll *prev;
	string name;
	int acc_no;
	int pin;
	double bal;
	char date[1024];
	int w;
	char w_t[1024];
	int d;
	char d_t[1024];
	struct dll *next;
}dll;
dll *head=0;
dll *head1=0;
void add_last();
void print();
