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

TEST(find_pref_two_el, correct_1)
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

TEST(find_pref_two_el, correct_2)
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
	for (int i = 0; i < 3; i++) {
		if (a[i] == c[i]) {
			j++;
		}
	}
	ASSERT_EQ(3, j);
}

TEST(find_pref_two_el, correct_3)
{
	char* a = "aas";
	char* b = "aas";
	char* q = "as";
	char **x;
	char *c;
	int j = 0;
	x = new char*[3];
	*x = a;
	*(x + 1) = b;
	*(x + 2) = q;
	c = find_pref(x, 3);
	for (int i = 0; i < 3; i++) {
		if (q[i] == c[i]) {
			j++;
		}
	}
	ASSERT_EQ(2, j);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}