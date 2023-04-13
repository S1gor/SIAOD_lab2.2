/*Написать программу формирования сбалансированного ВB-дерева из случайного множества n
целочисленных ключей с заданным показателем сбалансированности и определить его высоту.*/
#include "WBT.h"
/*		   Example
			 15
*		10		  20
*	   4  12	 17 23
*/

using namespace std;

int Choice()
{
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice > 3 || choice < 1);
	return choice;
}

void LoopWBT()
{
	WBT wbt;
	cout << "1. Insert " << endl;
	cout << "2. Height" << endl;
	cout << "3. Exit" << endl;
	while (true)
	{
		switch (Choice())
		{
		case 1:
		{
			int data;
			cout << "Enter element to insert: ";
			cin >> data;
			wbt.Insert(data);
		} break;
		case 2:
		{
			cout << "Heihgt: " << wbt.Height() + 1 << endl;
		} break;
		case 3:
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
	LoopWBT();
    return 0;
}