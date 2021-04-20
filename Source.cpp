#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#include "Header.h"

Tree createt(int n, int level)
{
	Tree t;
	if (level == n + 1)
	{
		t = NULL;
	}
	else
	{
		t = new NODE;
		t->info = level;
		t->left = createt(n, level + 1);
		t->right = createt(n, level + 1);
	}
	return t;
}

void printt(Tree t, int space)
{
	if (t != NULL)
	{
		printt(t->left, space + 1);
		for (int i = 1; i <= space; i++)
		{
			std::cout << ' ';
		}
		std::cout << t->info << std::endl;
		printt(t->right, space + 1);
	}
}

Tree copy_t(Tree t, int n, int level)
{
	Tree copyt;
	if (level == n + 1)
	{
		copyt = NULL;
	}
	else
	{
		copyt = new NODE;
		copyt->info = t->info;
		copyt->left = copy_t(t->left, n, level + 1);
		copyt->right = copy_t(t->right, n, level + 1);
	}
	return copyt;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream fin("tre.txt");
	Search_tree t(fin);
	fin.close();
	printt(t.gettree(), 0);
	if (0)
	{
		Tree tr = copy_t(t.gettree(), 3, 0);
		printt(tr, 0);
	}
}