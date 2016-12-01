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
	int *buf = mas[i];
	if (mas[0][2] < buf[2]) {
		int *buf_2 = mas[i];
		buf = mas[0];
		mas[0] = buf_2;
	}
}

int Lenght_input(char *a, char *b) {
	int i = 0;
	for (; (a[i] != 0) && (b[i] != 0) && (b[i] = a[i]); i++) { }
	return i;
}
int Lenght(char* a) {
	int i = 0;
	for (; a[i] != 0; i++) {}
	return i;
}

char* find_pref_two_el(char*a, char* b) {
	int m;
	int l;
	if (Lenght(a) < Lenght(b)) {
		m = Lenght(b) - Lenght(a) + 1;
	} 
	else {
		m = Lenght(a) - Lenght(b) + 1;
	}
	int **mas = new int*[m];
	for (int i = 0; i < m; i++) {
		mas[i] = new int[3];
	}

	/*
	int lenght_b, lenght_m;
	for (int lenght_m = 0; (a[lenght_m] != 0) && (b[lenght_m] != 0); lenght_m++) {
		if ((a[lenght_m + 1] == 0) && (b[lenght_m + 1] != 0)) {
			char *buf = a;
			a = b;
			b = buf;
		}
	}
	for (int lenght_b = lenght_m; a[lenght_b] != 0; lenght_b++) { }
	char **pref = new char*[lenght_b - lenght_m + 1];
	for (int i = 0; i < (lenght_b - lenght_m + 1); i++) {
		pref[i] = new char [lenght_m];
	}
	*/

	int q = 0;
	for (int i = 0; a[i] != 0; i++) {
		for (int j = 0; b[j] != 0; j++) {
			if (a[i] == b[j]) {
				mas[q][0] = i;
				mas[q][1] = j;
				mas[q][2] = Lenght_input(a+i, b+j);
				mas[q + 1][0] = -1;
				max_in_first_el(mas, q);
			}
		}
	}
	char *pref = new char[mas[0][2]];
	for (int j = 0; j < mas[0][2]; j++) {
		pref[j] = a[mas[0][1] + j];
	}
	return pref;
}

char* find_pref(char**a, int n) {
	char*pref;
	int i = 1;
	if(a[i]==0)
		return 0;
	while((a[i] != 0) && (i < n)) {
		pref = find_pref_two_el(a[i-1], a[i]);
		i++;
	}
	return pref;
}



