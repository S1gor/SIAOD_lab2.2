#pragma once

class WBTNode
{
//private:
public:
	WBTNode* left, * right;
	int weight, data;

public:
	WBTNode(int data, int weight, WBTNode* left, WBTNode* right);
	WBTNode(int data, int weight);

	//int GetData();
};

WBTNode* null_node;

class WBT
{
private:
	WBTNode* root;

	WBTNode* Insert(int data, int weight, WBTNode* t);
public:
	WBT();

	void Insert(int data, int weight);

};

