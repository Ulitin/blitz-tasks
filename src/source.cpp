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
	m = Lenght(a)*Lenght(b) + 1;
	int **mas = new int*[m];		// mas[i][0] - номер символа с которго строка a начинает рвняться с b, mas[i][1] - по анологии с первым только для b, mas[i][2] - хранит длинну данного вхождения
	for (int i = 0; i < m; i++) {
		mas[i] = new int[3];
	}
	mas[0][0] = 0;
	mas[0][1] = 0;
	mas[0][2] = 0;
	int q = 0;
	for (int i = 0; a[i] != 0; i++) {
		for (int j = 0; b[j] != 0; j++) {
			if (a[i] == b[j]) {
				mas[q][0] = i;
				mas[q][1] = j;
				mas[q][2] = Lenght_input(a + i, b + j);
				mas[q + 1][0] = -1;
				max_in_first_el(mas, q);
				q++;
			}
		}
	}
	int size = 0;
	if (mas[0][2] > 0) {
		size = mas[0][2];
	}
	char *pref = new char[size];
	for (int j = 0; j < size; j++) {
		pref[j] = a[mas[0][0] + j];
	}
	pref[mas[0][2]] = 0; 
	for (int i = 0; (i < m) && ((mas+i) != 0); i++) {
		delete [] mas[i];
	}
	delete []mas;
	return pref;
}

char* find_pref(char**a, int n) { // a - array string, n - number of rows
	if ((a[0] == 0) && (a[1] == 0)) {
		throw 1;
	}
	if(n == 1) {
		return a[0];
	}
	char *pref = a[0];
	int i = 1;
	while((i < n) && (pref!=0)) {
		if (a[i] == 0) {
			throw 1;
		}
		pref = find_pref_two_el(pref, a[i]);
		i++;
	}
	return pref;
}


//задача 3

void moving(CNode *str, int position1 , int position2) { // counting of positions starts with 1
	if (str == 0) {
		throw 1;
	}
	int i;
	for (i = 1; i < position1; i++) {
		if (str->next == 0) {
			throw 1;
		}
		str = str->next;
	}
	CNode *str_2 = str;
	for (; i < position2; i++) {
		if (str_2->next == 0) {
			throw 1;
		}
		str = str->next;
	}
	i = str->data;
	str->data = str_2->data;
	str_2->data = i;
}

//задача 4
void fun_min_and_max(int *mas, int &min, int &max, int size) {
	min = mas[0];
	max = mas[0];
	for (int i = 0; i < size; i++) {
		if (mas[i] < min) {
			min = mas[i];
		}
		else if(mas[i] > max) {
			max = mas[i];
			}
	}
}

bool scan_elem(int *mas, int x, int size, int i, int j) {
	for (int q = 0; q < size; q++) {
		if ((x == mas[q]) && (i != q) && (q != j) ) {
			return true;
		}
	}
	return false;
}

int** search_pair_of_elements(int *mas, int size) {
	if (mas == 0) {
		throw 1;
	}
	int min = 0;
	int max = 0;
	int **output = new int*[size*size]; // output[i][0]=a output[i][1]=d output[i][2]=a+b
	for (int i = 0; i < (size*size); i++) {
		output[i] = new int[3];
	}
	output[0][0] = -1;
	output[0][1] = -1;
	fun_min_and_max(mas,min,max,size);
	int q = 0;
	for(int i=0; i < size-1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((mas[i] + mas[j] >= min) && (mas[i] + mas[j] <= max) && (scan_elem(mas, mas[i] + mas[j], size, i,j))) {
				output[q][0] = mas[i];
				output[q][1] = mas[j];
				output[q][2] = mas[i] + mas[j];
				q++;
			}
		}
	}
	output[q][0] = -1;
	output[q][1] = -1;
	return output;
}