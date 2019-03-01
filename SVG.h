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
#ifdef _DEBUG
#include <crtdbg.h>
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

class SVG {
private:
	std::vector<Shape*> shapes;

public:
	float width, height;

	SVG();
	virtual ~SVG();
	void Add(Shape * shape);
	void SavePretty(const std::string filename);
	void SaveSimple(const std::string filename);
};

#endif // !SVG_H_
