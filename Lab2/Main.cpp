/*Написать программу формирования сбалансированного ВB-дерева из случайного множества n
целочисленных ключей с заданным показателем сбалансированности и определить его высоту.*/
//#include "WBT.h"
#include <iostream>
/*			Example
			 15(5)
*		12(5)	  20(10)
*	   8(3) 	    22(80)
*/

//using namespace std;
//
//WBTNode* null_node;
//
//int Choice()
//{
//	int choice;
//	do {
//		cout << "Enter your choice: ";
//		cin >> choice;
//	} while (choice > 5 || choice < 1);
//	return choice;
//}
//
//void LoopWBT()
//{
//	WBT wbt;
//	int data, weight;
//	cout << "1. Insert " << endl;
//	cout << "2. Delete" << endl;
//	cout << "3. Search" << endl;
//	cout << "4. Height" << endl;
//	cout << "5. Exit" << endl;
//	while (true)
//	{
//		switch (Choice())
//		{
//		case 1:
//		{
//			cout << "Enter element to insert: ";
//			cin >> data;
//			wbt.Insert(data);
//		} break;
//		case 2:
//		{
//			cout << "Enter element to delete: ";
//			cin >> data;
//			wbt.Remove(data);
//		} break;
//		case 3:
//		{
//			cout << "Enter element to search: ";
//			cin >> data;
//			if (wbt.Search(data) == true)
//				cout << "Element " << data << " found in the tree" << endl;
//			else
//				cout << "Element " << data << " not found in the tree" << endl;
//		} break;
//		case 4:
//		{
//			cout << "Heihgt: " << wbt.Height() << endl;
//		} break;
//		case 5:
//		{
//			exit(0);
//		}
//		}
//		cout << "Tree:" << endl;
//		wbt.Print();
//		cout << endl;
//	}
//}
//
//int main()
//{
//	null_node = new WBTNode(0, INT_MAX);
//	null_node->left = null_node->right = null_node;
//
//	LoopWBT();
//
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//class Node {
//public:
//    int key;
//    int weight;
//    Node* left;
//    Node* right;
//    Node(int k) : key(k), weight(1), left(nullptr), right(nullptr) {}
//};
//
//class WeightBalancedTree {
//private:
//    Node* root;
//
//    Node* rotateRight(Node* node) {
//        Node* temp = node->left;
//        node->left = temp->right;
//        temp->right = node;
//        node->weight = (node->left ? node->left->weight : 0) + (node->right ? node->right->weight : 0) + 1;
//        temp->weight = (temp->left ? temp->left->weight : 0) + (temp->right ? temp->right->weight : 0) + 1;
//        return temp;
//    }
//
//    Node* rotateLeft(Node* node) {
//        Node* temp = node->right;
//        node->right = temp->left;
//        temp->left = node;
//        node->weight = (node->left ? node->left->weight : 0) + (node->right ? node->right->weight : 0) + 1;
//        temp->weight = (temp->left ? temp->left->weight : 0) + (temp->right ? temp->right->weight : 0) + 1;
//        return temp;
//    }
//
//    Node* balance(Node* node) {
//        if (!node) return nullptr;
//        int balance_factor = (node->left ? node->left->weight : 0) - (node->right ? node->right->weight : 0);
//        if (balance_factor > 0.7) {
//            if ((node->left->left ? node->left->left->weight : 0) < (node->left->right ? node->left->right->weight : 0)) {
//                node->left = rotateLeft(node->left);
//            }
//            node = rotateRight(node);
//        }
//        else if (balance_factor < 0.3) {
//            if ((node->right->right ? node->right->right->weight : 0) < (node->right->left ? node->right->left->weight : 0)) {
//                node->right = rotateRight(node->right);
//            }
//            node = rotateLeft(node);
//        }
//        return node;
//    }
//
//public:
//    WeightBalancedTree() : root(nullptr) {}
//
//    void insert(int key) {
//        root = insert(root, key);
//    }
//
//    Node* insert(Node* node, int key) {
//        if (!node) return new Node(key);
//        if (key < node->key) {
//            node->left = insert(node->left, key);
//        }
//        else if (key > node->key) {
//            node->right = insert(node->right, key);
//        }
//        node->weight = (node->left ? node->left->weight : 0) + (node->right ? node->right->weight : 0) + 1;
//        return balance(node);
//    }
//
//    void traverseInOrder() {
//        traverseInOrder(root);
//        cout << endl;
//    }
//
//    void traverseInOrder(Node* node) {
//        if (!node) return;
//        traverseInOrder(node->left);
//        cout << node->key << " ";
//        traverseInOrder(node->right);
//    }
//
//    int Height(Node* r)
//    {
//        if (r == nullptr)
//            return 0;
//        else if (r->left == NULL && r->right == NULL)
//            return 0;
//        else if (Height(r->left) > Height(r->right))
//            return Height(r->left) + 1;
//        else
//            return Height(r->right) + 1;
//    }
//    int Height()
//    {
//        return Height(root);
//    }
//};

class WBTNode
{
public:
	int weight, data;
	WBTNode* left, * right;

	WBTNode(int data, int weight, WBTNode* left, WBTNode* right) : data(data), weight(weight), left(left), right(right) {}
	WBTNode(int data) { WBTNode(data, 1, nullptr, nullptr); }
};

class WBT
{
private:
	WBTNode* root;

	WBTNode* RotateLeft(WBTNode* r)
	{
		WBTNode* tmp = r->right;
		r->right = tmp->left;
		tmp->left = r;
		r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
		tmp->weight = (tmp->left ? tmp->left->weight : 0) + (tmp->right ? tmp->right->weight : 0) + 1;
		return tmp;
	}
	WBTNode* RotateRight(WBTNode* r)
	{
		WBTNode* tmp = r->left;
		r->left = tmp->right;
		tmp->right = r;
		r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
		tmp->weight = (tmp->left ? tmp->left->weight : 0) + (tmp->right ? tmp->right->weight : 0) + 1;
		return tmp;
	}
	WBTNode* CheckBalance(WBTNode* r)
	{
		if (!r) return nullptr;
		int balance_factor = (r->left ? r->left->weight : 0) - (r->right ? r->right->weight : 0);
		if (balance_factor > 0.7) {
			if ((r->left->left ? r->left->left->weight : 0) < (r->left->right ? r->left->right->weight : 0)) {
				r->left = RotateLeft(r->left);
			}
			r = RotateRight(r);
		}
		else if (balance_factor < 0.3) {
			if ((r->right->right ? r->right->right->weight : 0) < (r->right->left ? r->right->left->weight : 0)) {
				r->right = RotateRight(r->right);
			}
			r = RotateLeft(r);
		}
		return r;
	}

	WBTNode* Insert(int data, WBTNode* r) //!!!!!!!!!!!!
	{
		if (!r) return new WBTNode(data);
		if (data < r->data) {
			r->left = Insert(data, r->left);
		}
		else if (data > r->data) {
			r->right = Insert(data, r->right);
		}
		r->weight = (r->left ? r->left->weight : 0) + (r->right ? r->right->weight : 0) + 1;
		return CheckBalance(r);
	}
	void Print(WBTNode* r)
	{
		if (!r)	return;
		Print(r->left);
		std::cout << r->data << " ";
		Print(r->right);
	}
	int Height(WBTNode* r)
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
public:
	WBT() : root(nullptr) {}

	void Insert(int data)
	{
		Insert(data, root);
	}
	void Print()
	{
		Print(root);
	}
	int Height()
	{
		return Height(root);
	}
};


int main() {
    WBT tree;

    tree.Insert(10);

    tree.Print();

    std::cout << tree.Height() + 1 << std::endl;

    return 0;
}