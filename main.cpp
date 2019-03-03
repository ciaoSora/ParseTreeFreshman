#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ParseTree.h"
#include "shapes.h"
#include "SVG.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG


int main() {
	std::string to_parse;
	getline(std::cin, to_parse);
	ParseTree * pt = new ParseTree(to_parse);
	pt->SaveAsSVG("parse_tree.html");

	delete pt;
	#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
	#endif // _DEBUG
	return 0;
}
