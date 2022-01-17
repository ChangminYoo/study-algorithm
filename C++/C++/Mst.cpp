#include "Mst.h"

int MST::KruskalMST()
{
	int weight = 0;

	sort(graph->adjacencyList.begin(), graph->adjacencyList.end());
	DisjointSets ds(graph->V);

	vector<pair<int, pair<int, int>>> v;

	for (auto iter = graph->adjacencyList.begin(); iter != graph->adjacencyList.end(); iter++)
	{
		int u = iter->second.first;
		int v = iter->second.second;

		int root_u = ds.Find(u);
		int root_v = ds.Find(v);

		// 선택된 간선이 사이클을 만드는지 체크
		// u와v의 각 루트노드가 같다면 사이클
		if (root_u != root_v)
		{
			cout << u << " - " << v << endl;

			weight += iter->first;

			ds.Union(root_u, root_v);
		}
	}

	return weight;
}
