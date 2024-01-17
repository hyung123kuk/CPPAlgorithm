#include <iostream>
#include <stack>
#include <queue>
using namespace std;


// 시간 복잡도 : 트리의 높이에 비례한 시간이 걸린다.
// 시간 복잡도를 줄이기 위해 높이에 대한 최적화가 필요한데, 높이가 큰 트리 아래에 높이가 낮은 트리가 들어가는 방법을 사용한다.
struct DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n,1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		//샐행할 때 부모 저장해 놓는다.
		return _parent[u] = Find(_parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		// rank[u] <= rank[v] 보장
		if (_rank[u] > _rank[v])
			swap(u, v);
		
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	
}
