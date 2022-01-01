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
			{ 0, 1, 0, 1, 0, 0 },
			{ 1, 0, 1, 1, 0, 0 },
			{ 0, 1, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 1, 0 },
			{ 0, 0, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 1, 0 },
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
				if (adj[now, next] == 0) continue;
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
					if (adj[now, next] == 0) continue;
					if (visited[next]) continue;

					q.Enqueue(next);
					visited[next] = true;
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
