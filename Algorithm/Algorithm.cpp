#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

}

void Dfs(int here)
{
	// 방문 했다.
	visited[here] = true;
	cout << "Visited : " << here << endl;

	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}

}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
		if (visited[i] == false)
			Dfs(i);
}

int main()
{
	CreateGraph();

	DfsAll();
}

