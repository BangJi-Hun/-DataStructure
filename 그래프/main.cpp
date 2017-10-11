#include "Graph.h"
#include "weightedList.h"
#include "linkedDigraph.h"
int main()
{
	Graph g;
	Sets* s = NULL;
	weightedList wl;
	linkedDigraph dg;
	char inputNum;
	string str;

	while(1)
	{
		system("cls");
		cout << "���α׷��� �����ϼ��� " << endl;
		cout << "([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) : ";
		cin >> inputNum;

		switch(inputNum)
		{
		case 'S':
			cout << "������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit) : ";
			cin >> str;
			if(str == "quit")
				break;
			g.loadFile(str);
			g.showMatrix();
			g.showAdList();
			g.print();
			break;

		case 'M':
			cout << "������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit) : ";
			cin >> str;
			if(str == "quit")
				break;
			wl.loadFile(str,s);
			wl.sort();
			wl.selectEdge(s);
			wl.print();
			break;

		case 'T':
			cout << "������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit) : ";
			cin >> str;
			if(str == "quit")
				break;
			dg.loadFile(str);
			dg.makeRoad();
			break;

		case 'Q':
			return 0;
		}
		system("pause");
	}

}