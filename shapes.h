/****************************************************
Author: ciaoSora
File: shapes.h
Desc: Basic shapes in SVG
****************************************************/

#pragma once
#ifndef SHAPES_H_
#define SHAPES_H_
#include <string>

class Shape {
protected:
	std::string stroke;
	float strokeWidth;
	Shape(const std::string stroke_, float strokeWidth_);

public:
	virtual ~Shape() {

	}
	virtual std::string ToString() = 0;
};

class Rectangle : public Shape {
protected:
	float x, y, width, height;
	std::string fill;

public:
	Rectangle(float x_, float y_, float w_, float h_, const std::string f_, const std::string stroke_, float strokeWidth_);
	virtual ~Rectangle() {

	}
	virtual std::string ToString();
};

class RoundedRectangle : public Rectangle {
protected:
	float rx, ry;

public:
	RoundedRectangle(float x_, float y_, float w_, float h_, float rx_, float ry_, const std::string f_, const std::string stroke_, float strokeWidth_);
	virtual ~RoundedRectangle() {

	}
	virtual std::string ToString();
};

class Line : public Shape {
protected:
	float x1, y1, x2, y2;

public:
	Line(float x1_, float y1_, float x2_, float y2_, const std::string stroke_, float strokeWidth_);
	virtual ~Line() {

	}
	virtual std::string ToString();
};

class Text : public Shape {
protected:
	float x, y;
	std::string text;
	std::string fontFamily;
	int fontSize;

public:
	Text(float x_, float y_, const std::string text_, const std::string font_, int size_);
	~Text() {

	}
	virtual std::string ToString();
};

#endif // !SHAPES_H_
