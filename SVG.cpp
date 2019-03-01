/****************************************************
Author: ciaoSora
File: SVG.cpp
Desc: Interfaces that draw basic shapes in SVG
****************************************************/

#include "SVG.h"
#include <fstream>

SVG::SVG() {
	width = height = 0.0f;
}

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
	std::ofstream fout(filename);
	fout << "<svg width=\"" << width << "\" ";
	fout << "height=\"" << height << "\" ";
	fout << "xmlns = \"http://www.w3.org/2000/svg\">" << std::endl;
	/*<defs>
		<linearGradient id = "grad1" x1 = "0%" y1 = "0%" x2 = "0%" y2 = "55%">
		<stop offset = "0%" style = "stop-color:#99cc33;stop-opacity:1" / >
		<stop offset = "100%" style = "stop-color:#47eaff;stop-opacity:1" / >
		< / linearGradient>
		< / defs>*/
	fout << "<defs>" << std::endl;
	fout << "\t<linearGradient id=\"grad1\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">" << std::endl;
	fout << "\t\t<stop offset=\"0%\"style=\"stop-color:#99cc33;stop-opacity:1\"/>" << std::endl;
	fout << "\t\t<stop offset=\"30%\"style=\"stop-color:#99cc33;stop-opacity:1\"/>" << std::endl;
	fout << "\t\t<stop offset=\"70%\"style=\"stop-color:#47eaff;stop-opacity:1\"/>" << std::endl;
	fout << "\t\t<stop offset=\"100%\"style=\"stop-color:#47eaff;stop-opacity:1\"/>" << std::endl;
	fout << "\t</LinearGradient>" << std::endl;
	fout << "</defs>" << std::endl;
	fout << "\t<rect width=\"100%\" height=\"100%\" fill=\"#F7EED6\"/>" << std::endl;
	std::string tem;
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		tem = (*it)->ToString();
		fout << '\t' << tem << std::endl;
	}

	fout << "</svg>" << std::endl;
}

void SVG::SaveSimple(const std::string filename) {
	std::ofstream fout(filename);
	fout << "<svg width=\"" << width << "\" ";
	fout << "height=\"" << height << "\" ";
	fout << "xmlns = \"http://www.w3.org/2000/svg\">";
	fout << "<defs>";
	fout << "<linearGradient id=\"grad1\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">";
	fout << "<stop offset=\"0%\"style=\"stop-color:#99cc33;stop-opacity:1\"/>";
	fout << "<stop offset=\"30%\"style=\"stop-color:#99cc33;stop-opacity:1\"/>";
	fout << "<stop offset=\"70%\"style=\"stop-color:#47eaff;stop-opacity:1\"/>";
	fout << "<stop offset=\"100%\"style=\"stop-color:#47eaff;stop-opacity:1\"/>";
	fout << "</LinearGradient>";
	fout << "</defs>";
	fout << "<rect width=\"100%\" height=\"100%\" fill=\"#F7EED6\"/>";
	std::string tem;
	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		tem = (*it)->ToString();
		fout << tem;
	}

	fout << "</svg>" << std::endl;
}
