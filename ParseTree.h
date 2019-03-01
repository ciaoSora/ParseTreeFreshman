/****************************************************
Author: ciaoSora
File: ParseTree.h
Desc: The parse tree data structure
****************************************************/

#pragma once
#ifndef PARSETREE_H_
#define PARSETREE_H_
#include <string>
#include <vector>
#ifdef _DEBUG
#include <crtdbg.h>
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

struct Node {
	std::string tag;
	int depth;
	bool isLeaf;
	std::vector<Node*> sons;
	float x, y, width, height, ql, qr, delta;

	Node() {
		tag = "";
		sons.clear();
		depth = 0;
		isLeaf = false;
		
		x = y = width = height = ql = qr = delta = 0.0f;
	}
};

class ParseTree {
private:
	std::vector<Node*> leaves;
	Node * root;

	int dfs1(const std::string & to_parse, int start, int depth, Node * parent);
	void dfs2(Node * p);

public:
	static std::string FILL1;
	static std::string FILL2;
	static std::string STROKE;
	static float STROKE_WIDTH;
	static std::string FONT;
	static int FONT_SIZE;
	static float MARGIN_TOP, MARGIN_LEFT;
	static float FLOOR_HEIGHT, FLOOR_INTERVAL;
	static float HORIZONTAL_INTERVAL;

	ParseTree(const std::string to_parse);
	virtual ~ParseTree();
	void SaveAsSVG(const std::string filename);
	void PrintConcole();
};

#endif // !PARSETREE_H_
