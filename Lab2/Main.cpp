/*Написать программу формирования сбалансированного ВB-дерева из случайного множества n
целочисленных ключей с заданным показателем сбалансированности и определить его высоту.*/
#include "WBT.h"

using namespace std;

WBTNode* null_node;

int Choice()
{
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice > 4 || choice < 1);
	return choice;
}

void LoopWBT()
{
	WBT wbt;
	int data, weight;
	cout << "Weight Balanced Tree operations:" << endl;
	cout << "1. Insert " << endl;
	cout << "2. Delete" << endl;
	cout << "3. Search" << endl;
	cout << "4. Exit" << endl;
	while (true)
	{
		switch (Choice())
		{
		case 1:
		{
			cout << "Enter integer element to insert: ";
			cin >> data;
			cout << "Enter weight of the element in int: ";
			cin >> weight;
			wbt.Insert(data, weight);
		} break;
		case 2:
		{
			cout << "Enter integer element to delete: ";
			cin >> data;
			wbt.Remove(data);
		} break;
		case 3:
		{
			cout << "Enter integer element to search: ";
			cin >> data;
			if (wbt.Search(data) == true)
				cout << "Element " << data << " found in the tree" << endl;
			else
				cout << "Element " << data << " not found in the tree" << endl;
		} break;
		case 4:
		{
			exit(0);
		}
		}
		cout << "Tree:" << endl;
		wbt.Print();
		cout << endl;
	}
}

int main()
{
	null_node = new WBTNode(0, INT_MAX);
	null_node->left = null_node->right = null_node;

	LoopWBT();

	return 0;
}