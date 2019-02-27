/****************************************************
Author: ciaoSora
File: shapes.cpp
Desc: Basic shapes in SVG
****************************************************/

#include "shapes.h"

Shape::Shape(const std::string stroke_, float strokeWidth_) {
	stroke = stroke_;
	strokeWidth = strokeWidth_;
}

Rectangle::Rectangle(float x_, float y_, float w_, float h_, const std::string f_,
					 const std::string stroke_, float strokeWidth_) : Shape(stroke_, strokeWidth_) {
	x = x_;
	y = y_;
	width = w_;
	height = h_;
	fill = f_;
}

std::string Rectangle::ToString() {
	std::string rt = "<rect ";
	rt += ("x=\"" + std::to_string(x) + "\" ");
	rt += ("y=\"" + std::to_string(y) + "\" ");
	rt += ("width=\"" + std::to_string(width) + "\" ");
	rt += ("height=\"" + std::to_string(height) + "\" ");
	rt += ("fill=\"" + fill + "\" ");
	rt += ("stroke=\"" + stroke + "\" ");
	rt += ("stroke-width=\"" + std::to_string(strokeWidth) + "\"");
	rt += "/>";
	return rt;
}

RoundedRectangle::RoundedRectangle(float x_, float y_, float w_, float h_, float rx_, float ry_, const std::string f_,
								   const std::string stroke_, float strokeWidth_) : Rectangle(x_, y_, w_, h_, f_, stroke_, strokeWidth_) {
	rx = rx_;
	ry = ry_;
}

std::string RoundedRectangle::ToString() {
	std::string rt = "<rect ";
	rt += ("x=\"" + std::to_string(x) + "\" ");
	rt += ("y=\"" + std::to_string(y) + "\" ");
	rt += ("width=\"" + std::to_string(width) + "\" ");
	rt += ("height=\"" + std::to_string(height) + "\" ");
	rt += ("rx=\"" + std::to_string(rx) + "\" ");
	rt += ("ry=\"" + std::to_string(ry) + "\" ");
	rt += ("fill=\"" + fill + "\" ");
	rt += ("stroke=\"" + stroke + "\" ");
	rt += ("stroke-width=\"" + std::to_string(strokeWidth) + "\"");
	rt += "/>";
	return rt;
}

Line::Line(float x1_, float y1_, float x2_, float y2_, const std::string stroke_,
		   float strokeWidth_) : Shape(stroke_, strokeWidth_) {
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
}

std::string Line::ToString() {
	std::string rt = "<line ";
	rt += ("x1=\"" + std::to_string(x1) + "\" ");
	rt += ("y1=\"" + std::to_string(y1) + "\" ");
	rt += ("x2=\"" + std::to_string(x2) + "\" ");
	rt += ("y2=\"" + std::to_string(y2) + "\" ");
	rt += ("stroke=\"" + stroke + "\" ");
	rt += ("stroke-width=\"" + std::to_string(strokeWidth) + "\"");
	rt += "/>";
	return rt;
}

Text::Text(float x_, float y_, const std::string text_, const std::string font_, int size_) : Shape("", 0) {
	x = x_;
	y = y_;
	text = text_;
	fontFamily = font_;
	fontSize = size_;
}

std::string Text::ToString() {
	std::string rt = "<text ";
	rt += ("x=\"" + std::to_string(x) + "\" ");
	rt += ("y=\"" + std::to_string(y) + "\" ");
	rt += ("style=\"font-family:" + fontFamily + ";font-size:" + std::to_string(fontSize) + "\">");
	rt += text;
	rt += "</text>";
	return rt;
}
