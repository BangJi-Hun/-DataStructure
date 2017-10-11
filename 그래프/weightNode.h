#pragma once
class weightNode
{
private:
	int vertax1;
	int vertax2;
	int weight;
public:
	friend class Sets;
	friend class weightedList;
	weightNode(){}
	weightNode(int ver1,int ver2,int w){vertax1 = ver1,vertax2 = ver2,weight = w;}
	~weightNode(void){}

	int getWeight(){return weight;}
};

