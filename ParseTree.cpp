/****************************************************
Author: ciaoSora
File: ParseTree.cpp
Desc: The parse tree data structure
****************************************************/

#include "ParseTree.h"
#include <iostream>
#include "SVG.h"
#include <algorithm>

std::string ParseTree::FILL1 = "#99cc33";
std::string ParseTree::FILL2 = "url(#grad1)";
std::string ParseTree::STROKE = "#006400";
std::string ParseTree::FONT = "consolas";
int ParseTree::FONT_SIZE = 18;
float ParseTree::STROKE_WIDTH = 3.0f;
float ParseTree::MARGIN_LEFT = 10.0f;
float ParseTree::MARGIN_TOP = 10.0f;
float ParseTree::FLOOR_HEIGHT = 25.0f;
float ParseTree::FLOOR_INTERVAL = 40.0f;
float ParseTree::HORIZONTAL_INTERVAL = 15.0f;

int ParseTree::dfs1(const std::string & to_parse, int start, int depth, Node * parent) {
	while (to_parse[start] == ' ') {
		++start;
	}
	int i = start + 1;
	Node * tem = new Node();
	tem->depth = depth;
	while (to_parse[i] == ' ') {
		++i;
	}
	while (to_parse[i] != '(' && to_parse[i] != ')') {
		tem->tag += to_parse[i];
		++i;
	}
	while (tem->tag[tem->tag.length() - 1] == ' ') {
		tem->tag.pop_back();
	}
	if (to_parse[i] == ')') {
		tem->isLeaf = true;
		leaves.push_back(tem);
	}

	while (to_parse[i] != ')') {
		i = dfs1(to_parse, i, depth + 1, tem) + 1;
	}

	if (parent) {
		parent->sons.push_back(tem);
	}
	else {
		root = tem;
	}
	return i;
}

void ParseTree::dfs2(Node * p) {
	for (int i = 0; i < p->depth; ++i) {
		putchar('\t');
	}
	std::cout << p->tag << std::endl;
	for (auto it = p->sons.begin(); it != p->sons.end(); ++it) {
		dfs2(*it);
	}
}

void dfs3(Node * p) {
	for (auto it = p->sons.begin(); it != p->sons.end(); ++it) {
		dfs3(*it);
	}
	p->sons.clear();
	delete p;
}

ParseTree::ParseTree(const std::string to_parse) {
	dfs1(to_parse, 0, 0, NULL);
}

ParseTree::~ParseTree() {
	dfs3(root);
}

void ParseTree::PrintConcole() {
	dfs2(root);
}

/* Return the width of the rectangle */
void AddTextRectangle(SVG * svg, const std::string text, float x, float y) {
	float width = text.length() * 10 + ParseTree::STROKE_WIDTH + 5.0f;
	float rx = std::min(width, ParseTree::FLOOR_HEIGHT) / 6.0f;
	svg->Add(new RoundedRectangle(x, y, width, ParseTree::FLOOR_HEIGHT, rx, rx, ParseTree::FILL1, ParseTree::STROKE, ParseTree::STROKE_WIDTH));
	svg->Add(new Text(x + 4.0f, y + ParseTree::FLOOR_HEIGHT * 0.75f, text, ParseTree::FONT, ParseTree::FONT_SIZE));
}

void AddDoubleTextRectangle(SVG * svg, const std::string text, float x, float y) {
	int sep = 0;
	for (sep = 0; text[sep] != ' '; ++sep);
	std::string str1 = text.substr(0, sep);
	std::string str2 = text.substr(sep + 1, text.length());
	struct Tem {
		float x, y, width;
		std::string * str;
	} t1, t2, *b, *s;
	t1.y = y + ParseTree::FLOOR_HEIGHT * 0.75f;
	t1.str = &str1;
	t2.y = y + ParseTree::FLOOR_HEIGHT * 1.75f;
	t2.str = &str2;
	if (str1.length() > str2.length()) {
		b = &t1;
		s = &t2;
	}
	else {
		b = &t2;
		s = &t1;
	}
	b->width = b->str->length() * 10 + ParseTree::STROKE_WIDTH + 5.0f;
	float rx = std::min(b->width, ParseTree::FLOOR_HEIGHT) / 6.0f;
	b->x = x + 4.0f;
	s->width = s->str->length() * 10 + ParseTree::STROKE_WIDTH + 5.0f;
	s->x = x + (b->width - s->width) * 0.5f + 4.0f;
	svg->Add(new RoundedRectangle(x, y, b->width, ParseTree::FLOOR_HEIGHT * 2, rx, rx, ParseTree::FILL2, ParseTree::STROKE, ParseTree::STROKE_WIDTH));
	svg->Add(new Text(t1.x, t1.y, *t1.str, ParseTree::FONT, ParseTree::FONT_SIZE));
	svg->Add(new Text(t2.x, t2.y, *t2.str, ParseTree::FONT, ParseTree::FONT_SIZE));
}

float GetWidth(const std::string text) {
	return text.length() * 10 + ParseTree::STROKE_WIDTH + 5.0f;
}

float GetLeafWidth(const std::string text) {
	int sep;
	for (sep = 0; text[sep] != ' '; ++sep);
	return std::max(sep, (int)(text.length() - sep - 1)) * 10 + ParseTree::STROKE_WIDTH + 5.0f;
}

void dfs4(Node * p, float leftBound) {
	if (p->isLeaf) {
		p->x = leftBound;
		p->y = ParseTree::MARGIN_TOP + p->depth * (ParseTree::FLOOR_HEIGHT + ParseTree::FLOOR_INTERVAL);
		p->width = GetLeafWidth(p->tag);
		p->height = ParseTree::FLOOR_HEIGHT;
		p->ql = p->x;
		p->qr = p->x + p->width;
		p->delta = 0.0f;
		return;
	}
	auto last = p->sons.begin();
	dfs4(*last, leftBound);
	float mid1 = (*last)->x + 0.5f * (*last)->width;
	p->ql = (*last)->ql;
	for (auto it = p->sons.begin() + 1; it != p->sons.end(); ++it) {
		dfs4(*it, (*last)->qr + ParseTree::HORIZONTAL_INTERVAL);
		last = it;
	}
	float mid2 = (*last)->x + 0.5f * (*last)->width;
	p->qr = (*last)->qr;
	p->width = GetWidth(p->tag);
	p->height = ParseTree::FLOOR_HEIGHT;
	p->x = (mid1 + mid2 - p->width) * 0.5f;
	p->y = ParseTree::MARGIN_TOP + p->depth * (ParseTree::FLOOR_HEIGHT + ParseTree::FLOOR_INTERVAL);
	if (p->x < p->ql) {
		p->delta = p->ql - p->x;
		p->qr += p->delta;
		p->x += p->delta;
	}
	p->qr = std::max(p->qr, p->x + p->width);
}

void dfs5(SVG * svg, Node * p) {
	svg->height = std::max(svg->height, (float)(p->depth));
	if (p->isLeaf) {
		AddDoubleTextRectangle(svg, p->tag, p->x, p->y);
		return;
	}
	AddTextRectangle(svg, p->tag, p->x, p->y);
	float x1, y1, x2, y2;
	for (auto it = p->sons.begin(); it != p->sons.end(); ++it) {
		(*it)->x += p->delta;
		(*it)->delta += p->delta;
		dfs5(svg, *it);
	}

	auto tem = p->sons.begin();
	float left1 = (*tem)->x + 0.5f * (*tem)->width;
	tem = p->sons.end();
	--tem;
	float right1 = (*tem)->x + 0.5f * (*tem)->width;
	float len1 = right1 - left1;
	float len2 = std::min(len1 * 0.2f, p->width * 0.6f);
	float left2 = p->x + (p->width - len2) * 0.5f;
	for (auto it = p->sons.begin(); it != p->sons.end(); ++it) {
		x1 = (*it)->x + 0.5f * (*it)->width;
		y1 = (*it)->y - ParseTree::STROKE_WIDTH * 0.5f;
		if (fabs(len1) < 1e-6) {
			x2 = left2;
		}
		else {
			x2 = (x1 - left1) * len2 / len1 + left2;
		}
		y2 = p->y + ParseTree::FLOOR_HEIGHT + ParseTree::STROKE_WIDTH * 0.5f;
		svg->Add(new Line(x1, y1, x2, y2, ParseTree::STROKE, ParseTree::STROKE_WIDTH * 0.5f));
	}
}

void ParseTree::SaveAsSVG(const std::string filename) {
	SVG * svg = new SVG();
	
	dfs4(root, ParseTree::MARGIN_LEFT);
	dfs5(svg, root);
	svg->width = root->qr - root->ql + ParseTree::MARGIN_LEFT * 2;
	svg->height = ParseTree::MARGIN_TOP * 2 + svg->height * (ParseTree::FLOOR_HEIGHT + ParseTree::FLOOR_INTERVAL) + ParseTree::FLOOR_HEIGHT * 2;
	svg->SavePretty(filename);
	delete svg;
}
