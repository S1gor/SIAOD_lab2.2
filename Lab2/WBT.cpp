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



bool WBT::IsEmpty()
{
	return root == null_node;
}

WBTNode* WBT::RotateLeft(WBTNode* t)
{
	WBTNode* tmp = t->left;
	t->left = tmp->right;
	tmp->right = t;
	return tmp;
}

WBTNode* WBT::RotateRight(WBTNode* t)
{
	WBTNode* tmp = t->right;
	t->right = tmp->left;
	tmp->left = t;
	return tmp;
}

WBTNode* WBT::Insert(int data, int weight, WBTNode* t)
{
	if (t == null_node)
		t = new WBTNode(data, weight, null_node, null_node);
	else if (data < t->data)
	{
		t->left = Insert(data, weight, t->left);
		if (t->left->weight < t->weight)
			t = RotateLeft(t);
	}
	else if (data > t->data)
	{
		t->right = Insert(data, weight, t->right);
		if (t->right->weight < t->weight)
			t = RotateRight(t);
	}
	return t;
}

WBTNode* WBT::Remove(int data, WBTNode* t)
{
	if (t != null_node)
	{
		if (data < t->data)
			t->left = Remove(data, t->left);
		else if (data > t->data)
			t->right = Remove(data, t->right);
		else
		{
			if (t->left->weight == 0)
				t->left->weight = INT_MAX;
			if (t->right->weight == 0)
				t->right->weight = INT_MAX;
			if (t->left->weight < t->right->weight)
				t = RotateLeft(t);
			else
				t = RotateRight(t);
			if (t != null_node)
				t = Remove(data, t);
			else
				t->left = null_node;
		}
	}
	return t;
}

bool WBT::Search(int data, WBTNode* t)
{
	bool found = false;
	while (t != null_node && !found)
	{
		int t_data = t->data;
		if (data < t_data)
			t = t->left;
		else if (data > t_data)
			t = t->right;
		else
		{
			found = true;
			break;
		}
		found = Search(data, t);
	}
	return found;
}

void WBT::Print(WBTNode* r)
{
	if (r != null_node)
	{
		Print(r->left);
		std::cout << r->data << " ";
		Print(r->right);
	}
}

WBT::WBT() : root(null_node) {}

void WBT::Insert(int data, int weight)
{
	Insert(data, weight, root);
}

void WBT::Remove(int data)
{
	if (IsEmpty())	std::cout << "Tree is empty!" << std::endl;
	else if (Search(data) == false)	std::cout << "There is not number" << std::endl;
	else
	{
		root = Remove(data, root);
		std::cout << "Number " << data << "deleted from the tree" << std::endl;
	}
}

bool WBT::Search(int data)
{
	return Search(data, root);
}

void WBT::Print()
{
	Print(root);
}