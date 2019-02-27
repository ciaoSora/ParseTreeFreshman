/****************************************************
Author: ciaoSora
File: SVG.h
Desc: Interfaces that draw basic shapes in SVG
****************************************************/

#pragma once
#ifndef SVG_H_
#define SVG_H_
#include "shapes.h"
#include <vector>

class SVG {
private:
	std::vector<Shape*> shapes;

public:
	virtual ~SVG();
	void Add(Shape * shape);
	void SavePretty(const std::string filename);
	void SaveSimple(const std::string filename);
};

#endif // !SVG_H_
