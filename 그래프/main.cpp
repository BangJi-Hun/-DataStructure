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
		cout << "프로그램을 선택하세요 " << endl;
		cout << "([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) : ";
		cin >> inputNum;

		switch(inputNum)
		{
		case 'S':
			cout << "무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit) : ";
			cin >> str;
			if(str == "quit")
				break;
			g.loadFile(str);
			g.showMatrix();
			g.showAdList();
			g.print();
			break;

		case 'M':
			cout << "무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit) : ";
			cin >> str;
			if(str == "quit")
				break;
			wl.loadFile(str,s);
			wl.sort();
			wl.selectEdge(s);
			wl.print();
			break;

		case 'T':
			cout << "무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit) : ";
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