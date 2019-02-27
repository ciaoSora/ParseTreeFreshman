/****************************************************
Author: ciaoSora
File: SVG.cpp
Desc: Interfaces that draw basic shapes in SVG
****************************************************/

#include "SVG.h"
#include <fstream>

SVG::~SVG() {
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		delete *it;
	}
	shapes.clear();
}

void SVG::Add(Shape * shape) {
	shapes.push_back(shape);
}

void SVG::SavePretty(const std::string filename) {
	std::ofstream fout(filename + ".svg");
	fout << "<svg xmlns = \"http://www.w3.org/2000/svg\">" << std::endl;
	std::string tem;
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		tem = (*it)->ToString();
		fout << '\t' << tem << std::endl;
	}

	fout << "<svg>" << std::endl;
}

void SVG::SaveSimple(const std::string filename) {
	std::ofstream fout(filename + ".svg");
	fout << "<svg xmlns = \"http://www.w3.org/2000/svg\">";
	std::string tem;
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		tem = (*it)->ToString();
		fout << tem;
	}

	fout << "<svg>" << std::endl;
}
