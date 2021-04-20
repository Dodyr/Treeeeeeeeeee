#include "Header.h"

void Add(Tree& t, int elem)
{
	if (t == NULL)
	{
		t = new NODE;
		t->info = elem;
		t->left = NULL;
		t->right = NULL;
	}
	else
		if (elem < t->info)
			Add(t->left, elem);
		else
			if (elem > t->info)
				Add(t->right, elem);
}

Search_tree::Search_tree(std::ifstream& fin)
{
	int elem;
	root = NULL;
	while (!fin.eof())
	{
		fin >> elem;
		Add(root, elem);
	}
	fin.close();
}

Tree Search_tree::gettree()
{
	return root;
}