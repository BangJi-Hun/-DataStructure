#include "linkedDigraph.h"


linkedDigraph::linkedDigraph()
{
	count = 0;
}

linkedDigraph::~linkedDigraph(void)
{
}

void linkedDigraph::loadFile(string msg)
{
	ifstream ifs;
	ifs.open(msg);     

	int num,ver1,ver2;

	ifs >> num;
	count = num;
	visited = new bool[count];
	for(int i = 0 ; i < count ; i++)
	{
		graphList[i] = new graphNode;
		visited[i] = false;
	}
	while(!ifs.eof())
	{
		ifs >> ver1;
		if(ver1 == -1)
			break;
		ifs	>> ver2;
		insertList(ver1,ver2);
	}

	ifs.close();
}

void linkedDigraph::insertList(int ver1,int ver2)
{
	if(graphList[ver1]->link == nullptr)
	{
		graphList[ver1]->link = new graphNode(ver2);
		graphList[ver2]->count += 1;
		graphList[ver2]->vertax = ver2;
	}
	else
	{
		graphNode* currentNode = graphList[ver1]->link;
		while(currentNode->link != nullptr)
		{
			currentNode = currentNode->link;
		}
		currentNode->link = new graphNode(ver2);
		graphList[ver2]->count += 1;
		graphList[ver2]->vertax = ver2;
	}
}

void linkedDigraph::makeRoad()
{
	cout << "가능한 하나의 위상정렬 : ";
	int cnt = 0;
	graphNode* currentNode = graphList[0];
	visited[0] = true;
	cout << 0 << " ";
	while(1)
	{
		if(currentNode->link != nullptr)
		{
			graphList[currentNode->link->vertax]->count -= 1;
			if(graphList[currentNode->link->vertax]->count == 0)
			{
				s.push(currentNode->link->vertax);
			}
			currentNode = currentNode->link;
		}
		else
		{
			cout << s.Top() << " " ;
			currentNode = graphList[s.Top()];
			visited[s.Top()] = true;
			s.pop();
		}
		for(int j = 0 ; j < count ;j++)
		{
			if(visited[j] == true)
				cnt++;
		}
		if(cnt == count)
			break;
		cnt = 0;
	}
	cout << endl;
}
