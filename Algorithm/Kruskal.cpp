
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
namespace Kruskal
{
	class DisjointSet
	{
	public:
		DisjointSet(int n) : _parent(n), _rank(n, 1)
		{
			for (int i = 0; i < n; i++)
				_parent[i] = i;
		}

		int Find(int u)
		{
			if (u == _parent[u])
				return u;

			//������ �� �θ� ������ ���´�.
			return _parent[u] = Find(_parent[u]);
		}

		void Merge(int u, int v)
		{
			u = Find(u);
			v = Find(v);

			if (u == v)
				return;

			// rank[u] <= rank[v] ����
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

	struct Vertex
	{

	};

	vector<Vertex> vertices;
	vector<vector<int>> adjacent;

	void CreateGraph()
	{
		vertices.resize(6);
		adjacent = vector<vector<int>>(6, vector<int>(6, -1));

		adjacent[0][1] = adjacent[1][0] = 15;
		adjacent[0][3] = adjacent[3][0] = 35;
		adjacent[1][2] = adjacent[2][1] = 5;
		adjacent[1][3] = adjacent[3][1] = 10;
		adjacent[3][4] = adjacent[4][3] = 5;
		adjacent[3][5] = adjacent[5][3] = 10;
		adjacent[5][4] = adjacent[4][5] = 5;
	}

	struct CostEdge
	{
		int cost;
		int u;
		int v;

		bool operator<(CostEdge& other)
		{
			return cost < other.cost;
		}
	};

	int Kruskal(vector<CostEdge>& selected)
	{
		int ret = 0;

		selected.clear();

		vector<CostEdge> edges;

		for (int u = 0; u < adjacent.size(); u++)
		{
			for (int v = 0; v < adjacent[u].size(); v++)
			{
				if (u > v)
					continue;


				int cost = adjacent[u][v];
				if (cost == -1)
					continue;

				edges.push_back(CostEdge{ cost, u ,v });
			}
		}

		std::sort(edges.begin(), edges.end());


		//DisjoiuntSet �̿�
		DisjointSet sets(vertices.size());

		for (CostEdge& edge : edges)
		{
			// ���� �׷��̸� ��ŵ (�� �׷��� ����Ŭ �߻�)
			if (sets.Find(edge.u) == sets.Find(edge.v))
				continue;

			// �� �׷��� ��ģ��.
			sets.Merge(edge.u, edge.v);
			selected.push_back(edge);
			ret += edge.cost;
		}

		return ret;
	}
}