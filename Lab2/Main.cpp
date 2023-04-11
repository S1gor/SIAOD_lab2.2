/*Написать программу формирования сбалансированного ВB-дерева из случайного множества n
целочисленных ключей с заданным показателем сбалансированности и определить его высоту.*/
#include "WBT.h"

/*			Example
			 15(5)
*		12(5)	  20(10)
*	   8(3) 	    22(80)
*/

using namespace std;

WBTNode* null_node;

int Choice()
{
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice > 5 || choice < 1);
	return choice;
}

void LoopWBT()
{
	WBT wbt;
	int data, weight;
	cout << "1. Insert " << endl;
	cout << "2. Delete" << endl;
	cout << "3. Search" << endl;
	cout << "4. Height" << endl;
	cout << "5. Exit" << endl;
	while (true)
	{
		switch (Choice())
		{
		case 1:
		{
			cout << "Enter element to insert: ";
			cin >> data;
			cout << "Enter weight of the element: ";
			cin >> weight;
			wbt.Insert(data, weight);
		} break;
		case 2:
		{
			cout << "Enter element to delete: ";
			cin >> data;
			wbt.Remove(data);
		} break;
		case 3:
		{
			cout << "Enter element to search: ";
			cin >> data;
			if (wbt.Search(data) == true)
				cout << "Element " << data << " found in the tree" << endl;
			else
				cout << "Element " << data << " not found in the tree" << endl;
		} break;
		case 4:
		{
			cout << "Heihgt: " << wbt.Height() << endl;
		} break;
		case 5:
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