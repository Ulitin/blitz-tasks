#include <stack>

struct CNode
{
	int data;
	CNode* next;
};

int convert (int x);
char* find_pref(char**a, int n); 
void moving(CNode*, int, int);
