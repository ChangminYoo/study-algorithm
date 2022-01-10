#include "Graph.h"

class PathFind
{
private:
	int graph[6][6] = 
	{
		{ -1, 15, -1, 35, -1, -1 },
		{ 15, -1, 5, 10, -1, -1 },
		{ -1, 5, -1, -1, -1, -1 },
		{ 35, 10, -1, -1, 5, -1 },
		{ -1, -1, -1, 5, -1, 5 },
		{ -1, -1, -1, -1, 5, -1 },
	};

public:
	void Dijkstra(int start)
	{
		priority_queue<pair<int, int>> pq;		// vertex,  distance
		vector<int> distance(6, INT32_MAX);
		pq.push(make_pair(start, 0));
		distance[start] = 0;

		while (!pq.empty())
		{
			int now = pq.top().first;
			int dist = pq.top().second;
			pq.pop();			

			cout << now << " ";
			for (int next = 0; next < 6; next++)
			{
				if (graph[now][next] < 0) continue;

				int nextDistance = graph[now][next];

				if (distance[next] > distance[now] + nextDistance)
				{
					distance[next] = distance[now] + nextDistance;
					pq.push(make_pair(next, -distance[next]));
				}
			}

		}
		cout << "\n";
		for (int i = 0; i < 6; i++)
		{
			printf("%d\n", distance[i]);
		}
	}

};

