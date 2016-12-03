#include <gtest/gtest.h>
#include"header.h"

TEST(Convert, correct)
{
	int a = 123;
	a = convert(a);
	ASSERT_EQ(a, 321);

}

TEST(Convert, correct_namber_with_minus)
{
	int a = -123;
	a = convert(a);
	ASSERT_EQ(a, -321);

}

TEST(find_pref, correct_on_zero)
{
	char* a = "aas";
	char **x;
	x = new char*[2];
	*x = a;
	*(x + 1) = 0;
	ASSERT_ANY_THROW(find_pref(x, 2));
}


TEST(find_pref, correct_1)
{
	char* a = "aas";
	char* b = "aas";
	char **x;
	char *c;
	int j = 0;
	x = new char* [2];
	*x = a;
	*(x + 1) = b;
	c = find_pref(x, 2);
	for (int i = 0; i < 3; i++) {
		if (a[i] == c[i]) {
			j++;
		}
	}
	ASSERT_EQ(3,j);
}

TEST(find_pref, correct_2)
{
	char* a = "aas";
	char* b = "as";
	char **x;
	char *c;
	int j = 0;
	x = new char*[2];
	*x = a;
	*(x + 1) = b;
	c = find_pref(x, 2);
	for (int i = 0; i < 2; i++) {
		if (b[i] == c[i]) {
			j++;
		}
	}
	ASSERT_EQ(2, j);
}

TEST(find_pref, correct_3)
{
	char* a = "aas";
	char* b = "las";
	char* q = "as";
	char **x;
	char *c;
	int j = 0;
	x = new char*[3];
	*x = a;
	*(x + 1) = b;
	*(x + 2) = q;
	c = find_pref(x, 3);
	for (int i = 0; i < 2; i++) {
		if (q[i] == c[i]) {
			j++;
		}
	}
	ASSERT_EQ(2, j);
}

TEST(find_pref, correct_4)
{
	char* a = "aas";
	char* b = "azs";
	char* q = "zas";
	char **x;
	char *c;
	int j = 0;
	x = new char*[3];
	*x = a;
	*(x + 1) = b;
	*(x + 2) = q;
	c = find_pref(x, 3);
	for (j; c[j] != 0; j++) {}
	ASSERT_EQ(1, j);
}

TEST(find_pref, correct_5)
{
	char* a = "a";
	char* b = "s";
	char* q = "z";
	char **x;
	char *c;
	int j = 0;
	x = new char*[3];
	*x = a;
	*(x + 1) = b;
	*(x + 2) = q;
	c = find_pref(x, 3);
	for (j; c[j] != 0; j++) {}
	ASSERT_EQ(0, j);
}


TEST(moving, correct_on_zero)
{
	CNode *a = 0;
	ASSERT_ANY_THROW(moving(a, 1, 3));
}

TEST(moving, test_on_correct_moving)
{
	CNode *a = new CNode;
	a->data = 0;
	a->next = new CNode;
	a = a->next;
	a->data = 1;
	a->next = 0;
	ASSERT_ANY_THROW(moving(a, 1, 3));
}

TEST(moving, correct_1)
{
	CNode *a = new CNode;
	CNode *b = a;
	a->data = 0;
	a->next = new CNode;
	a = a->next;
	a->data = 1;
	a->next = new CNode;
	a = a->next;
	a->data = 2;
	a->next = 0;

	moving(b,1,3);
	ASSERT_EQ(2, b->data);
	b = b->next;
	ASSERT_EQ(1, b->data);
	b = b->next;
	ASSERT_EQ(0, b->data);
}

TEST(moving, correct_2)
{
	CNode *a = new CNode;
	CNode *b = a;
	a->data = 0;
	a->next = new CNode;
	a = a->next;
	a->data = 1;
	a->next = new CNode;
	a = a->next;
	a->data = 2;
	a->next = 0;

	moving(b, 2, 3);
	ASSERT_EQ(0, b->data);
	b = b->next;
	ASSERT_EQ(2, b->data);
	b = b->next;
	ASSERT_EQ(1, b->data);
}

TEST(moving, correct_3)
{
	CNode *a = new CNode;
	CNode *b = a;
	a->data = 0;
	a->next = new CNode;
	a = a->next;
	a->data = 1;
	a->next = new CNode;
	a = a->next;
	a->data = 2;
	a->next = 0;

	moving(b, 1, 2);
	ASSERT_EQ(1, b->data);
	b = b->next;
	ASSERT_EQ(0, b->data);
	b = b->next;
	ASSERT_EQ(2, b->data);
}

TEST(moving, moving_the_same_element)
{
	CNode *a = new CNode;
	CNode *b = a;
	a->data = 0;
	a->next = new CNode;
	a = a->next;
	a->data = 1;
	a->next = new CNode;
	a = a->next;
	a->data = 2;
	a->next = 0;

	moving(b, 1, 1);
	ASSERT_EQ(0, b->data);
	b = b->next;
	ASSERT_EQ(1, b->data);
	b = b->next;
	ASSERT_EQ(2, b->data);
}

TEST(search_pair_of_elements, test_on_zero)
{
	int *mas = 0;
	ASSERT_ANY_THROW(search_pair_of_elements(mas,5));
}

TEST(search_pair_of_elements, input_zero_elements)
{
	int *mas = new int [3];
	mas[0] = 0;
	mas[1] = 5;
	mas[2] = 1;
	int **output;
	output = search_pair_of_elements(mas, 3);
	ASSERT_EQ(-1, output[0][0]);
	ASSERT_EQ(-1, output[0][1]);
}

TEST(search_pair_of_elements, test)
{
	int *mas = new int[6];
	mas[0] = 1;
	mas[1] = 6;
	mas[2] = 0;
	mas[3] = 3;
	mas[4] = -5;
	mas[5] = 2;
	int **output;
	output = search_pair_of_elements(mas, 6);
	ASSERT_EQ(1, output[0][0]);
	ASSERT_EQ(2, output[0][1]);
	ASSERT_EQ(3, output[0][2]);
	ASSERT_EQ(6, output[1][0]);
	ASSERT_EQ(-5, output[1][1]);
	ASSERT_EQ(1, output[1][2]);
}


int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}