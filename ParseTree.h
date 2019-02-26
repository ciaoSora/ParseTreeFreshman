#pragma once
#ifndef PARSETREE_H_
#define PARSETREE_H_
#include <string>
#include <vector>

struct Node {
	std::string tag;
	int depth;
	bool isLeaf;
	std::vector<Node*> sons;
	Node() {
		tag = "";
		sons.clear();
		depth = 0;
		isLeaf = false;
	}
};

class ParseTree {
private:
	std::vector<Node*> leaves;
	int dfs1(const std::string & to_parse, int start, int depth, Node * parent);
	void dfs2(Node * p);
	Node * root;

public:
	ParseTree(const std::string to_parse);
	virtual ~ParseTree();
	void SaveAsSVG(const std::string filename);
	void PrintConcole();
};

#endif // !PARSETREE_H_
