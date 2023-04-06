#include "WBT.h"

WBTNode::WBTNode(int data, int weight, WBTNode* left, WBTNode* right) : data(data), weight(weight), left(left), right(right) {}

WBTNode::WBTNode(int data, int weight)
{
	WBTNode(data, weight, nullptr, nullptr);
}

//int WBTNode::GetData()
//{
//	return data;
//}



WBTNode* WBT::Insert(int data, int weight, WBTNode* t)
{
	if (t == null_node)
		t = new WBTNode(data, weight, null_node, null_node);
	else if (data < t->data)
	{
		t->left = Insert(data, weight, t->left);

	}
}

WBT::WBT() : root(null_node) {}

void WBT::Insert(int data, int weight)
{

}
