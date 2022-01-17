#pragma once
#include "Graph.h"

// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/

class DisjointSets
{
public:
	int* parent;
	int* rank;
	int n;

	explicit DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		// Init
		for (int i = 0; i <= n; i++)
		{
			rank[i] = 0;
			parent[i] = i;
		}
	}
	~DisjointSets() {}

	// ��Ʈ��� ã��
	int Find(int u)
	{
		// �θ��尡 �ڽ� �� ��Ʈ �������
		if (u != parent[u])
		{
			parent[u] = Find(parent[u]);
		}
		return parent[u];
	}

	// Union By Rank
	void Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		// rank�� �������� Ʈ���� �����ʿ� ������.
		if (rank[x] > rank[y])
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}

		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
	}

};

class MST
{
public:
	Graph2* graph = nullptr;

	MST()
	{
		graph = new Graph2();
	}
	~MST()
	{
		delete graph;
	}

	int KruskalMST();
};
