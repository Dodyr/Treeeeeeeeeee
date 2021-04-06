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