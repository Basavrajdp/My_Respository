#include <bits/stdc++.h>
using namespace std;
typedef struct dll
{
	struct dll *prev;
	string name;
	int acc_no;
	int pin;
	double bal;
	int w;
	int d;
	struct dll *next;
}dll;
dll *head=0;
dll *head1=0;
void add_last();
void print();
