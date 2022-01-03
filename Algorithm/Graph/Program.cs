using System;
using System.Collections.Generic;

namespace Graph
{
	class Graph
	{
		//    0
		//  /  |
		// 1 - 3 
		// |   |
		// 2   4   
		//	   |
		//	   5

		int[,] adj = new int[6, 6]
		{
			{ -1, 15, -1, 35, -1, -1 },
			{ 14, -1, 5, 10, -1, -1 },
			{ -1, 5, -1, -1, -1, -1 },
			{ 35, 10, -1, -1, 5, -1 },
			{ -1, -1, -1, 5, -1, 5 },
			{ -1, -1, -1, -1, 5, -1 },
		};

		List<int>[] adj2 = new List<int>[]
		{
			new List<int>(){ 1, 3 },
			new List<int>(){ 0, 2, 3 },
			new List<int>(){ 1 },
			new List<int>(){ 0, 1, 4 },
			new List<int>(){ 3 ,5 },
			new List<int>(){ 4 },
		};

		bool[] visited = new bool[6];
		public void DFS(int now) // adj
		{
			Console.WriteLine(now);
			visited[now] = true;

			for (int next = 0; next < 6; next++)
			{
				if (adj[now, next] < 0) continue;
				if (visited[next]) continue;

				DFS(next);
			}
		}

		public void DFS2(int now) // adj2
		{
			Console.WriteLine(now);
			visited[now] = true;

			foreach (int next in adj2[now])
			{
				if (visited[next]) continue;
				DFS2(next);
			}
		}

		public void DFS_Stack(int now)
		{
			Stack<int> s = new Stack<int>();
			s.Push(now);
			visited[now] = true;

			while (s.Count > 0)
			{
				now = s.Pop();
				Console.WriteLine(now);

				foreach (int next in adj2[now])
				{
					if (visited[next]) continue;
					visited[next] = true;
					s.Push(next);
				}
			}

		}

		public void SearchAll()
		{
			visited = new bool[6];
			for (int now = 0; now < 6; now++)
			{
				if (visited[now] == false)
				{
					DFS(now);
				}
			}
		} // Edge가 끊긴 경우 전체 탐색하여 끊긴 부분부터 다시 탐색할 수 있게함

		public void BFS(int now)
		{
			Queue<int> q = new Queue<int>();
			q.Enqueue(now);
			visited[now] = true;

			while (q.Count > 0)
			{
				now = q.Dequeue();
				Console.WriteLine(now);

				for (int next = 0; next < 6; next++)
				{
					if (adj[now, next] < 0) continue;
					if (visited[next]) continue;

					q.Enqueue(next);
					visited[next] = true;
				}
			}
		}

		void DijkstraNoPrioriyQueue(int start)
		{
			int[] distance = new int[6];
			int[] parent = new int[6];
			Array.Fill(distance, Int32.MaxValue);

			distance[start] = 0;
			parent[start] = start;
			while (true)
			{
				// 가장 가까이에 있는 후보 탐색

				// 가장 유력한 후보의 거리와 번호 저장
				int closet = Int32.MaxValue;
				int now = -1;
				for (int i = 0; i < 6; i++)
				{
					if (visited[i]) continue;

					// 아직 방문되지 않았거나, 기존 후보보다 멀리있으면 스킵
					if (distance[i] == Int32.MaxValue || distance[i] >= closet) continue;

					closet = distance[i];
					now = i;
				}

				if (now == -1)
					break;

				visited[now] = true;

				// 방문한 정점과 인접한 정점들을 조사해서
				// 상황에 따라 발견한 최단거리를 갱신한다.
				for (int next = 0; next < 6; next++)
				{
					// 연결되지 않은 정점 스킵
					if (adj[now, next] == -1) continue;
					if (visited[next]) continue;

					// 새로 조사된 정점의 최단거리를 계산한다.
					int nextDist = distance[now] + adj[now, next];
					if (nextDist < distance[next])
					{
						distance[next] = nextDist;
						parent[next] = now;
					}
				}
			}

		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			Graph graph = new Graph();
			// DFS
			graph.DFS_Stack(0);

			// BFS
			//graph.BFS(0);
		}
	}
}
