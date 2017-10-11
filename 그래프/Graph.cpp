#include "Graph.h"

Graph::Graph()
{
	count = 0;

}


Graph::~Graph(void)
{
}

void Graph::loadFile(string msg)
{
	ifstream ifs;
	ifs.open(msg);     

	int num, i , j;
	ifs >> num;
	
	count = num;
	MatrixList = new int*[num];
	for (int i = 0; i < num; i++)
	{
		MatrixList[i] = new int[num];
	}

	for(int i = 0 ; i < count ;i++)
	{
		adList[i] = new Node(i);
	}

	for (int i = 0; i < count; i++)
	{
		flag[i] = 0;
	}
		
	while(!ifs.eof())
	{
		ifs >> i;
		if(i == -1)
			break;
		ifs >> j;
		insertMatrix(i,j);
	}

	ifs.close();
}

void Graph::insertMatrix(int x,int y)
{
	MatrixList[x][y] = 1;
	MatrixList[y][x] = 1;
}

void Graph::makeMatrix()
{
	for(int i = 0 ; i < count ; i++)
	{
		for(int j = 0 ; j < count ; j++)
		{
			if(MatrixList[i][j] != 1)
			{
				MatrixList[i][j] = 0;
			}
		}
	}
}

void Graph::showMatrix()
{
	makeMatrix();
	cout << "입력된 그래프의 인접 행렬 표현 " << endl;
	for(int i = 0 ; i < count ; i++)
	{
		for(int j = 0 ; j < count ; j++)
		{
			cout << MatrixList[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::makeAdList()
{
	Node* currentNode;
	for(int i = 0 ; i < count ; i++)
	{
		for(int j = 0 ; j < count ; j++)
		{
			if(MatrixList[i][j] == 1)
			{
				if(adList[i]->rowsLink == nullptr)
				{
					adList[i]->rowsLink = new Node(j);
					currentNode = adList[i]->rowsLink;
				}
				else
				{
					Node* newNode = new Node(j);
					newNode->rowsLink = currentNode;
					adList[i]->rowsLink = newNode;
					currentNode = newNode;
				}
			}
		}
	}
}

void Graph::showAdList()
{
	makeAdList();
	cout << "입력된 그래프의 인접리스트 표현" << endl;
	Node* currentNode;
	for(int i = 0 ; i < count ; i++)
	{
		currentNode = adList[i];
		cout << currentNode->data << " -> ";
		currentNode = currentNode->rowsLink;
		if(currentNode == nullptr)
		{
			cout << "null" << endl;
		}
		else
		{
			while(currentNode->rowsLink != nullptr) 
			{
				cout << currentNode->data << " - ";
				currentNode = currentNode->rowsLink;
			}
			cout << currentNode->data;
			cout << endl;
		}
	}
}

void Graph::showAdMatrixDFS(int x)
{
	int j = 0;
	cout << x << " ";
	isCheck[x] = true;
	for(int i = x ; i < count ; i++)
	{
		for(j = 0 ; j < count ; j++)
		{
			if(MatrixList[i][j] == 1)
			{
				if(isCheck[j] == true){flag[i] = flag[i] +1;}
				else
				{
					cout << j << " ";
					isCheck[j] = true;
					s.push(i);
					break;
				}
			}
			else
				flag[i] = flag[i] + 1;
		}
		if(flag[i] == count)
		{
			if(s.IsEmpty())
			{
				break;
			}
			flag[i] = 0;
			i = s.Top() - 1;
			s.pop();
			continue;
		}
		flag[i] = 0;
		i = j-1;
	}
}

void Graph::showAdListDFS(int x)
{
	Node* currentNode = adList[x];
	cout << x << " ";
	isCheck[x] = true;
	s.push(x);
	for(int i = x ; i < count + 1 ; i++)
	{
		if(currentNode->rowsLink != nullptr)
		{
			if(isCheck[currentNode->rowsLink->data] == true)
			{
				currentNode = currentNode->rowsLink;
			}
			else
			{
				isCheck[currentNode->rowsLink->data] = true;
				s.push(currentNode->rowsLink->data);
				cout << currentNode->rowsLink->data << " ";
				currentNode = adList[currentNode->rowsLink->data];
				i = currentNode->data - 1;
				continue;
			}
		}
		else if(currentNode->rowsLink == nullptr)
		{
			if(!s.IsEmpty())
			{
				s.pop();
				if(s.IsEmpty())
				{
					break;
				}
				currentNode = adList[s.Top()];
				i = s.Top() - 1;

				continue;
			}
		}
	}
}

void Graph::showAdMatrixBFS(int x)
{
	cout << x << " ";
	isCheck[x] = true;
	for(int i = x ; i < count ; i++)
	{
		for(int j = 0 ; j < count ; j++)
		{
			if(MatrixList[i][j] == 1)
			{
				if(isCheck[j] == true){}
				else
				{
					isCheck[j] = true;
					q.push(j);	
				}
			}
		}
		if(q.isEmpty())
			break;

		i = q.Front() - 1;
		cout << q.Front() << " ";
		q.pop();
	}
}

void Graph::showAdListBFS(int x)
{

}
void Graph::print()
{
	int number = 2;
	cout << "연결요소" << endl;
	cout << "1. 인접행렬 + DFS" << endl;
	cout << "인접요소1 - "; 
	showAdMatrixDFS(0);
	cout << endl;

	for(int i = 0 ; i < count ; i++)
	{
		if(isCheck[i] != true)
		{
			cout << "인접요소" << number++ << " - ";
			showAdMatrixDFS(i);
			cout << endl;
		}
		isCheck[i] = false;
	}
	cout << endl;
	cout << "2. 인접행렬 + BFS" << endl;
	cout << "인접요소1 - "; 
	showAdMatrixBFS(0);
	cout << endl;
	for(int i = 0 ; i < count ; i++)
	{
		if(isCheck[i] != true)
		{
			cout << "인접요소" << number++ << " - ";
			showAdMatrixBFS(i);
			cout << endl;
		}
		isCheck[i] = false;
	}
	cout << endl;
	cout << "3. 인접리스트 + DFS" << endl;
	cout << "인접요소1 - "; 
	showAdListDFS(0);
	cout << endl;
	for(int i = 0 ; i < count ; i++)
	{
		if(isCheck[i] != true)
		{
			cout << "인접요소" << number++ << " - ";
			showAdListDFS(i);
			cout << endl;
		}
		isCheck[i] = false;
	}
}