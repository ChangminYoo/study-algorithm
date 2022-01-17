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

		// ���õ� ������ ����Ŭ�� ������� üũ
		// u��v�� �� ��Ʈ��尡 ���ٸ� ����Ŭ
		if (root_u != root_v)
		{
			cout << u << " - " << v << endl;

			weight += iter->first;

			ds.Union(root_u, root_v);
		}
	}

	return weight;
}
