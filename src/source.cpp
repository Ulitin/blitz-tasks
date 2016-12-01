#include "header.h"

//задача 1
int convert(int x) {
	int q = 0;
	if (x < 0) {
		q = 1;
		x = -x;
	}
	std::stack <int> el;
	for (int i = 0; x > 9; i++) {
		el.push(x % 10);
		x = x / 10;
	}
	el.push(x);
	x = 0;
	for (int i = 0; !el.empty(); i++) {
		x = x + el.top()*pow(10, i);
		el.pop();
	}
	if (q == 1) {
		x = -x;
	}
	return x;
}


//задача 2
void max_in_first_el(int **mas, int i) {
	if (mas[0][2] < mas[i][2]) {
		int buf;
		for (int j = 0; j < 3; j++) {
			buf = mas[i][j];
			mas[i][j] = mas[0][j];
			mas[0][j] = buf;
		}
	}
}

int Lenght_input(char *a, char *b) {
	int i = 1;
	for (;(b[i] != 0) && (b[i] == a[i]); i++) {}
	return i;
}
int Lenght(char* a) {
	int i = 0;
	for (; a[i] != 0; i++) {}
	return i + 1;
}

char* find_pref_two_el(char*a, char* b) {
	int m;
	int l;
	m = Lenght(a)*Lenght(b) + 1;
	int **mas = new int*[m];
	for (int i = 0; i < (m); i++) {
		mas[i] = new int[3];
	}

	int q = 0;
	for (int i = 0; a[i] != 0; i++) {
		for (int j = 0; b[j] != 0; j++) {
			if (a[i] == b[j]) {
				mas[q][0] = i;
				mas[q][1] = j;
				mas[q][2] = Lenght_input(a+i, b+j);
				mas[q + 1][0] = -1;
				max_in_first_el(mas, q);
				q++;
			}
		}
	}
	char *pref = new char[mas[0][2]];
	for (int j = 0; j < mas[0][2]; j++) {
		pref[j] = a[mas[0][0] + j];
	}
	pref[mas[0][2]] = 0;
	return pref;
}

char* find_pref(char**a, int n) { // a - массив строк, n - b - кол-во строк
	if ((a[0] == 0) && (a[1] == 0)) {
		throw 1;
	}
	if(n == 1) {
		return a[0];
	}
	char *pref = a[0];
	int i = 1;
	while(i < n) {
		if (a[i] == 0) {
			throw 1;
		}
		pref = find_pref_two_el(pref, a[i]);
		i++;
	}
	return pref;
}



