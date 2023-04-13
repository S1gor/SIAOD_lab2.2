#include "WBT.h"

WBTNode::WBTNode(int data) : data(data), weight(1), left(nullptr), right(nullptr) {}

WBTNode* WBT::RotateLeft(WBTNode* r)
{
	WBTNode* tmp = r->right;
	r->right = tmp->left;
	tmp->left = r;
	r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
	tmp->weight = (tmp->left ? tmp->left->weight : 0) + (tmp->right ? tmp->right->weight : 0) + 1;
	return tmp;
}

WBTNode* WBT::RotateRight(WBTNode* r)
{
	WBTNode* tmp = r->left;
	r->left = tmp->right;
	tmp->right = r;
	r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
	tmp->weight = (tmp->left ? tmp->left->weight : 0) + (tmp->right ? tmp->right->weight : 0) + 1;
	return tmp;
}

WBTNode* WBT::CheckBalance(WBTNode* r)
{
	if (!r) return nullptr;
	int balance = (r->left ? r->left->weight : 0) - (r->right ? r->right->weight : 0);
	if (balance > 0.70711)
	{
		if ((r->left->left ? r->left->left->weight : 0) < (r->left->right ? r->left->right->weight : 0))
			r->left = RotateLeft(r->left);
		r = RotateRight(r);
	}
	else if (balance < 0.29289)
	{
		if ((r->right->right ? r->right->right->weight : 0) < (r->right->left ? r->right->left->weight : 0))
			r->right = RotateRight(r->right);
		r = RotateLeft(r);
	}
	return r;
}

WBTNode* WBT::Insert(WBTNode* r, int data)
{
	if (!r) return new WBTNode(data);
	if (data < r->data)
		r->left = Insert(r->left, data);
	else if (data > r->data)
		r->right = Insert(r->right, data);
	r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
	return CheckBalance(r);
}

void WBT::Print(WBTNode* r)
{
	if (!r) return;
	Print(r->left);
	std::cout << r->data << " ";
	Print(r->right);
}

int WBT::Height(WBTNode* r)
{
	if (r == nullptr)
		return 0;
	else if (r->left == NULL && r->right == NULL)
		return 0;
	else if (Height(r->left) > Height(r->right))
		return Height(r->left) + 1;
	else
		return Height(r->right) + 1;
}

WBT::WBT() : root(nullptr) {}

void WBT::Insert(int data)
{
	root = Insert(root, data);
}

void WBT::Print()
{
	Print(root);
	std::cout << std::endl;
}

int WBT::Height()
{
	return Height(root);
}