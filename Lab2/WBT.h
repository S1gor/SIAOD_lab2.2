#pragma once
#include <iostream>

class WBTNode
{
public:
	int weight, data;
	WBTNode* left, * right;

	WBTNode(int data);
};
	
class WBT
{
private:
	WBTNode* root;

	WBTNode* RotateLeft(WBTNode* r);
	WBTNode* RotateRight(WBTNode* r);
	WBTNode* CheckBalance(WBTNode* r);

	WBTNode* Insert(WBTNode* r, int data);
	void Print(WBTNode* r);
	int Height(WBTNode* r);
public:
	WBT();

	void Insert(int data);
	void Print();
	int Height();
};