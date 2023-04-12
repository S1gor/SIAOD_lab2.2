#include "WBT.h"

//WBTNode::WBTNode(int data, int weight, WBTNode* left, WBTNode* right) : data(data), weight(weight), left(left), right(right) {}
//
//WBTNode::WBTNode(int data, int weight)
//{
//	WBTNode(data, weight, nullptr, nullptr);
//}
//
//
//
//bool WBT::IsEmpty()
//{
//	return root == null_node;
//}
//
//WBTNode* WBT::RotateLeft(WBTNode* t)
//{
//	WBTNode* tmp = t->left;
//	t->left = tmp->right;
//	tmp->right = t;
//	return tmp;
//}
//
//WBTNode* WBT::RotateRight(WBTNode* t)
//{
//	WBTNode* tmp = t->right;
//	t->right = tmp->left;
//	tmp->left = t;
//	return tmp;
//}
//
//WBTNode* WBT::Insert(int data, int weight, WBTNode*& t)
//{
//	if (t == null_node)
//		t = new WBTNode(data, weight, null_node, null_node);
//	else if (data < t->data)
//	{
//		t->left = Insert(data, weight, t->left);
//		if (t->left->weight < t->weight)
//			t = RotateLeft(t);
//	}
//	else if (data > t->data)
//	{
//		t->right = Insert(data, weight, t->right);
//		if (t->right->weight < t->weight)
//			t = RotateRight(t);
//	}
//	return t;
//}
//
//WBTNode* WBT::Remove(int data, WBTNode* t)
//{
//	if (t != null_node)
//	{
//		if (data < t->data)
//			t->left = Remove(data, t->left);
//		else if (data > t->data)
//			t->right = Remove(data, t->right);
//		else
//		{
//			if (t->left->weight == 0)
//				t->left->weight = INT_MAX;
//			if (t->right->weight == 0)
//				t->right->weight = INT_MAX;
//			if (t->left->weight < t->right->weight)
//				t = RotateLeft(t);
//			else
//				t = RotateRight(t);
//			if (t != null_node)
//				t = Remove(data, t);
//			else
//				t->left = null_node;
//		}
//	}
//	return t;
//}
//
//bool WBT::Search(int data, WBTNode* t)
//{
//	bool found = false;
//	while (t != null_node && !found)
//	{
//		int t_data = t->data;
//		if (data < t_data)
//			t = t->left;
//		else if (data > t_data)
//			t = t->right;
//		else
//		{
//			found = true;
//			break;
//		}
//		found = Search(data, t);
//	}
//	return found;
//}
//
//void WBT::Print(WBTNode* r)
//{
//	if (r != null_node)
//	{
//		Print(r->left);
//		std::cout << r->data << " ";
//		Print(r->right);
//	}
//}
//
//int WBT::Height(WBTNode* r)
//{
//	if (r == null_node)
//		return 0;
//	else if (r->left == NULL && r->right == NULL)
//		return 0;
//	else if (Height(r->left) > Height(r->right))
//		return Height(r->left) + 1;
//	else
//		return Height(r->right) + 1;
//}
//
//WBT::WBT() : root(null_node) {}
//
//void WBT::Insert(int data, int weight)
//{
//	Insert(data, weight, root);
//}
//
//void WBT::Remove(int data)
//{
//	if (IsEmpty())	std::cout << "Tree is empty!" << std::endl;
//	else if (Search(data) == false)	std::cout << "There is not number" << std::endl;
//	else
//	{
//		root = Remove(data, root);
//		std::cout << "Number " << data << " deleted from the tree" << std::endl;
//	}
//}
//
//bool WBT::Search(int data)
//{
//	return Search(data, root);
//}
//
//void WBT::Print()
//{
//	Print(root);
//}
//
//int WBT::Height()
//{
//	return Height(root);
//}


WBTNode::WBTNode(int data, int weight, WBTNode* left, WBTNode* right) : data(data), weight(weight), left(left), right(right) {}

WBTNode::WBTNode(int data, int weight)
{
	WBTNode(data, weight, nullptr, nullptr);
}



bool WBT::IsEmpty()
{
	return root == null_node;
}

WBTNode* WBT::RotateLeft(WBTNode* r)
{
	WBTNode* tmp = r;
	r = r->right;
	tmp->right = r->left;
	r->left = tmp;
	r->weight = tmp->weight;
	tmp->weight = tmp->left->weight + tmp->right->weight + 1;
	return tmp;
}

WBTNode* WBT::RotateRight(WBTNode* r)
{
	WBTNode* tmp = r;
	r = r->left;
	tmp->left = r->right;
	r->right = tmp;
	r->weight = tmp->weight;
	tmp->weight = tmp->left->weight + tmp->right->weight + 1;
	return tmp;
}

WBTNode* WBT::CheckBalance(WBTNode* r)
{
	float wbal = (float)r->left->weight / (float)r->weight;
	if (wbal > 0.70711 && r->left != null_node)
	{
		if ((float)r->left->left->weight / (float)r->left->weight > 0.414213)
			r = RotateRight(r);
		else
		{
			r->left = RotateLeft(r->left);
			r = RotateRight(r);
		}
	}
	else if (wbal < 0.29289 && r->right != null_node)
	{
		if ((float)(r->right->left->weight / (float)r->right->weight) < 0.585786)
			r = RotateLeft(r);
		else
		{
			r->right = RotateRight(r->right);
			r = RotateLeft(r);
		}
	}
	return r;
}

WBTNode* WBT::Insert(int data, WBTNode*& r)
{
	if (r == null_node)
		r = new WBTNode(data, 1, null_node, null_node);
	else if (data < r->data)
		r->left = Insert(data, r->left);
	else if (data > r->data)
		r->right = Insert(data, r->right);

	r->weight = r->left->weight + r->right->weight + 1;
	return CheckBalance(r);
}

WBTNode* WBT::Remove(int data, WBTNode* r)
{
	if (r == null_node)
		return r;
	if (data < r->data)
		r->left = Remove(data, r->left);
	else if (data > r->data)
		r->right = Remove(data, r->right);

	else if (r->left == null_node)
		r = r->right;
	else if (r->right == null_node)
		r = r->left;

	else if (r->left->weight > r->right->weight)
	{
		r = RotateRight(r);
		r->right = Remove(data, r->right);
	}
	else
	{
		r = RotateLeft(r);
		r->left = Remove(data, r->left);
	}

	if (r != null_node)
	{
		r->weight = r->left->weight + r->right->weight + 1;
		r = CheckBalance(r);
	}
	return r;
}

bool WBT::Search(int data, WBTNode* r)
{
	if (r == null_node)
		return null_node;

	if (r->data == data)
		return root;

	if (r->data < data)
		return Search(data, r->right);

	return Search(data, r->left);
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

int WBT::Height(WBTNode* r)
{
	if (r == null_node)
		return 0;
	else if (r->left == NULL && r->right == NULL)
		return 0;
	else if (Height(r->left) > Height(r->right))
		return Height(r->left) + 1;
	else
		return Height(r->right) + 1;
}

WBT::WBT() : root(null_node) {}

void WBT::Insert(int data)
{
	Insert(data, root);
}

void WBT::Remove(int data)
{
	if (IsEmpty())	std::cout << "Tree is empty!" << std::endl;
	else if (Search(data) == false)	std::cout << "There is not number" << std::endl;
	else
	{
		root = Remove(data, root);
		std::cout << "Number " << data << " deleted from the tree" << std::endl;
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

int WBT::Height()
{
	return Height(root);
}