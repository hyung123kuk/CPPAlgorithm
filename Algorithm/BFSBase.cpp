#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace BFS
{
}

struct Vertex
{

	vector<Vertex> vertices;
	vector<vector<int>> adjacent;
	vector<bool> discovered;

	void CreateGraph()
	{
		vertices.resize(6);
		adjacent = vector<vector<int>>(6);
		adjacent[0] = { 1,3 };
		adjacent[1] = { 0,2,3 };
		adjacent[3] = { 4 };
		adjacent[5] = { 4 };

	}

	void Bfs(int here)
	{

		queue<int> q;
		q.push(here);
		discovered[here] = true;

		while (q.empty() == false)
		{
			here = q.front();
			q.pop();

			cout << "Visited : " << here << endl;

			for (int there : adjacent[here])
			{
				if (discovered[there])
					continue;

				q.push(there);
				discovered[there] = true;
			}

		}

	}

	void BfsAll()
	{
		for (int i = 0; i < 6; i++)
			if (discovered[i] == false)
				Bfs(i);
	}

};
