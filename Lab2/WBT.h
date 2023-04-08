#pragma once

#include <iostream>

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

static WBTNode* null_node;

class WBT
{
private:
	WBTNode* root;

	bool IsEmpty();
	WBTNode* RotateLeft(WBTNode* t);
	WBTNode* RotateRight(WBTNode* t);

	WBTNode* Insert(int data, int weight, WBTNode* t);
	WBTNode* Remove(int data, WBTNode* t);
	bool Search(int data, WBTNode* t);
	void Print(WBTNode* r);
public:
	WBT();

	void Insert(int data, int weight);
	void Remove(int data);
	bool Search(int data);
	void Print();
};