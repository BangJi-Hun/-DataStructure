#pragma once
class graphNode
{
private:
	int vertax;
	int count;
	graphNode* link;
public:
	friend class linkedDigraph;
	graphNode(){count = 0,link = nullptr;}
	graphNode(int vt){vertax = vt , link = nullptr;}
	~graphNode(void){}
};

