/*�������� ��������� ������������ ����������������� �B-������ �� ���������� ��������� n
������������� ������ � �������� ����������� ������������������ � ���������� ��� ������.*/
#include "WBT.h"
/*		   Example
			 15				13
*		  11			 11    15
*	    10  13		   10
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