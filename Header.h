#pragma once

#include <iostream>
#include <fstream>

typedef int TInfo;
struct NODE
{
	TInfo info;
	NODE* left, * right;
};

typedef NODE* Tree;

class Search_tree
{
private:
	Tree root;
public:
	Search_tree(std::ifstream&);
	Tree gettree();
};