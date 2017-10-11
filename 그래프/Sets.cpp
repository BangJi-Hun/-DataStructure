#include "Sets.h"

Sets::Sets(void)
{
}

Sets::Sets(int numberOfElements)
{
	if(numberOfElements < 2)
		throw "Must have at least 2 elements.";
	num = numberOfElements;
	par = new int[num];
	fill(par,par+num,-1);
}

Sets::~Sets(void)
{
}

void Sets::WeightedUnion(int i,int j)
{
	int temp = par[i] + par[j];
	if(par[i] > par[j])
	{
		par[i] = j;
		par[j] = temp;
	}
	else
	{
		par[j] = i;
		par[i] = temp;
	}
}
int Sets::CollapsingFind(int i)
{
	int r = 0;
	for(r = i; par[r] >= 0; r = par[r]);
	while(i != r)
	{
		int s = par[i];
		par[i] = r;
		i = s;

	}
	return r;
}


