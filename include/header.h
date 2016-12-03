#include <stack>

struct CNode
{
	int data;
	CNode* next;
};

int convert (int x);
char* find_pref(char**, int); 
void moving(CNode*, int, int);
int** search_pair_of_elements(int*, int);