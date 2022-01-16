#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// 0 ----- 1
// |      /|  \
// |     / |   2
// |   /   |  /
// | /     | /
// 4	   3

class Graph
{
private:
	const int size = 5;
	int adjacencyMatirx[5][5] =
	{
		{0,1,0,0,1},
		{1,0,1,1,1},
		{0,1,0,1,0},
		{0,1,1,0,0},
		{1,1,0,0,0}
	};
	vector<int> adjacencyList[5];

	bool visited[5];
public:
	void InitList()
	{
		AddEdge(adjacencyList, 0, 1);
		AddEdge(adjacencyList, 0, 4);
		AddEdge(adjacencyList, 1, 2);
		AddEdge(adjacencyList, 1, 3);
		AddEdge(adjacencyList, 1, 4);
		AddEdge(adjacencyList, 2, 3);

		for (int v = 0; v < size; ++v)
		{
			cout << "정점 " << v << "의 인접 리스트\n ";
			for (auto x : adjacencyList[v])
			{
				cout << "-> " << x;
			}
			cout << endl;
		}
	}

	void AddEdge(vector<int> adj[], int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void DFS(int now)
	{
		cout << now << endl;
		visited[now] = true;
		for (int next = 0; next < size; next++)
		{
			if (adjacencyMatirx[now][next] == 0) continue;
			if (visited[next]) continue;

			DFS(next);
		}
	}

	void DFSWithStack(int now)
	{
		stack<int> s;
		s.push(now);
		visited[now] = true;

		while (!s.empty())
		{
			int top = s.top();
			s.pop();

			cout << top << endl;
			visited[top] = true;

			for (int i = 0; i < adjacencyList[top].size(); i++)
			{
				int next = adjacencyList[top][i];
				if (visited[next]) continue;

				s.push(next);
				visited[next] = true;
			}
		}
	}

	void BFS(int now)
	{
		queue<int> q;

		q.push(now);

		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			visited[front] = true;
			cout << front << endl;

			for (int i = 0; i < adjacencyList[front].size(); i++)
			{
				int next = adjacencyList[front][i];
				if (visited[next]) continue;

				q.push(next);
				visited[next] = true;
			}

		}

	}
};
