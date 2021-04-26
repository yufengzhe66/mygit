#include <iostream>
#include <vector>
using namespace std;

vector<int> par;

vector<int> ran;

//初始化n个元素
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par.push_back(i);
		ran.push_back(0);
	}
}


//查询树的根
int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

//合并x和y所属的集合
void unite(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	if (ran[x] < ran[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (ran[x] == ran[y])
			ran[x]++;
	}
}

//判断x和y是否属于同一集合
bool same(int x, int y)
{
	return find(x) == find(y);
}


int main()
{
	return 0;
}