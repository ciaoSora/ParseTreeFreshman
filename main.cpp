#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ParseTree.h"
#include "shapes.h"
#include "SVG.h"

int main() {
	Rectangle * re = new RoundedRectangle(20, 20, 400, 300, 50, 50, "#00FF00", "yellow", 5.4f);
	std::cout << re->ToString() << std::endl;
	Shape * ln = new Line(30, 30, 100, 120, "red", 5);
	std::cout << ln->ToString() << std::endl;
	SVG * svg = new SVG();
	svg->Add(re);
	svg->Add(ln);
	svg->Add(new Text(30, 40, "Genji", "consolas", 18));
	svg->SaveSimple("haha");

	std::string to_parse;
	getline(std::cin, to_parse);
	ParseTree * pt = new ParseTree(to_parse);
	pt->PrintConcole();
	delete pt;
	return 0;
}

