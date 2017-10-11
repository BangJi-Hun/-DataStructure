#include "weightedList.h"


weightedList::weightedList(void)
{
	sortList = new weightNode[20];
	count = 0;
	vertaxCount = 0;
}


weightedList::~weightedList(void)
{
}

void weightedList::loadFile(string msg,Sets*& s)
{
	ifstream ifs;
	ifs.open(msg);     

	int num,ver1,ver2,w;

	ifs >> num;
	s = new Sets(num);
	vertaxCount = num;
	while(!ifs.eof())
	{
		ifs >> ver1;
		if(ver1 == -1)
			break;
		ifs	>> ver2 >> w;
		insertList(ver1,ver2,w);

	}

	ifs.close();
}
void weightedList::insertList(int ver1,int ver2,int w)
{
	weightNode num(ver1,ver2,w);
	sortList[count++] = num;
}

void weightedList::sort()
{
	for(int i = 0 ; i < count-1 ; i++)
	{
		for(int j = i+1 ; j < count ; j++)
		{
			if(sortList[i].getWeight() > sortList[j].getWeight())
			{
				weightNode temp = sortList[i];
				sortList[i] = sortList[j];
				sortList[j] = temp;
			}
		}
	}
}

void weightedList::deleteSortList(int x)
{
	for(int i = x ; i < count ; i++)
	{
		sortList[i] = sortList[i+1];
	}
	count--;
}

void weightedList::selectEdge(Sets* s)
{
	int vertax1;
	int vertax2;
	for(int i = 0; i < count; i++)
	{
		vertax1 = s->CollapsingFind(sortList[i].vertax1);
		vertax2 = s->CollapsingFind(sortList[i].vertax2);
		if(vertax1 == vertax2)
		{
			deleteSortList(i);
			i--;
		}
		s->WeightedUnion(vertax1,vertax2);
	}

}

void weightedList::print()
{
	int sum = 0;
	if(count != vertaxCount - 1)
	{
		cout <<"최소비용 신장트리를 못 구합니다." << endl;
	}
	else
	{
		for(int i = 0 ; i < count ; i++)
		{
			cout << "(" << sortList[i].vertax1 << "," << sortList[i].vertax2 << ") ";
		}
		cout << endl << "최소비용은 ";
		for(int i = 0 ; i < count-1 ; i++)
		{
			sum = sum + sortList[i].getWeight();
			cout << sortList[i].getWeight() << "+";
		}
		sum = sum + sortList[count-1].getWeight();
		cout << sortList[count-1].getWeight() << "=" << sum << endl;
	}
}