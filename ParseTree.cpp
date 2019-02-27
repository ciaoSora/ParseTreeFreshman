/****************************************************
Author: ciaoSora
File: ParseTree.cpp
Desc: The parse tree data structure
****************************************************/

#include "ParseTree.h"
#include <iostream>

int ParseTree::dfs1(const std::string & to_parse, int start, int depth, Node * parent) {
	while (to_parse[start] == ' ') {
		++start;
	}
	int i = start + 1;
	Node * tem = new Node();
	tem->depth = depth;
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
