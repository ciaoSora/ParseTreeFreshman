#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ParseTree.h"

int main() {
	std::string to_parse;
	getline(std::cin, to_parse);
	ParseTree * pt = new ParseTree(to_parse);
	pt->PrintConcole();
	delete pt;
	return 0;
}

