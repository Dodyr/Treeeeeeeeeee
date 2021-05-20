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

void Print_tree(Tree t, int level)
{
	if (t != NULL)
	{
		Print_tree(t->right, level + 1);
		for (int i = 1; i <= level; i++)
			std::cout << "  ";
		std::cout << t->info << std::endl;
		Print_tree(t->left, level + 1);
	}
}

Tree copy_t(Tree t, int n, int level)
{
	Tree copyt;
	if ((level == n + 1)||!t)
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
	if (1)
	{
		std::ifstream fin("tre.txt");
		Search_tree t(fin);
		fin.close();
		Print_tree(t.gettree(), 0);
		Tree tr = copy_t(t.gettree(), 5, 0);
		Print_tree(tr, 0);
	}
	else
	{
		Tree t = createt(3, 0);
		Print_tree(t, 0);
		Tree tr = copy_t(t, 2, 0);
		Print_tree(tr, 0);
	}
	return 0;
}