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

	class TreeNode<T>
	{
		public T Data { get; set; }
		public List<TreeNode<T>> Children { get; set; } = new List<TreeNode<T>>();
	}

	class PrioirtyQueue<T> where T : IComparable<T>
	{
		List<T> _heap = new List<T>();

		// O(logN)
		public void Push(T data)
		{
			_heap.Add(data);

			int now = _heap.Count - 1;

			// 맨 아래부터 올라오면서 비교하여 자기에게 맞는 자리 찾는다
			while (now > 0)
			{
				int next = (now - 1) / 2;
				if (_heap[now].CompareTo(_heap[next]) < 0)
					break;

				T temp = _heap[now];
				_heap[now] = _heap[next];
				_heap[next] = temp;

				now = next;
			}
		}

		// O(logN)
		public T Pop()
		{
			T ret = _heap[0];

			int lastIndex = _heap.Count - 1;
			_heap[0] = _heap[lastIndex];
			_heap.RemoveAt(lastIndex);
			lastIndex--;

			int now = 0;
			// 맨 위에서 부터 내려가면서 자기자리 찾는다.
			while (true)
			{
				int left = (now * 2) + 1;
				int right = (now * 2) + 2;

				int next = now;
				if (left <= lastIndex && _heap[next].CompareTo(_heap[left]) < 0)
				{
					next = left;
				}
				
				if (right <= lastIndex && _heap[next].CompareTo(_heap[right]) < 0)
				{
					next = right;
				}

				if (next == now) break;

				T temp = _heap[now];
				_heap[now] = _heap[next];
				_heap[next] = temp;

				now = next;
			}

			return ret;
		}

		public int Count()
		{
			return _heap.Count;
		}
	}

	class Knight : IComparable<Knight>
	{
		public int Id { get; set; }

		public int CompareTo(Knight other)
		{
			if (Id == other.Id)
				return 0;
			return Id > other.Id ? 1 : -1;
		}
	}

	class Program
	{
		static TreeNode<string> MakeTree()
		{
			TreeNode<string> root = new TreeNode<string>() { Data = "R1 개발실" };
			{
				{
					TreeNode<string> node = new TreeNode<string>() { Data = "디자인팀" };
					node.Children.Add(new TreeNode<string>() { Data = "전투" });
					node.Children.Add(new TreeNode<string>() { Data = "경제" });
					node.Children.Add(new TreeNode<string>() { Data = "스토리" });
					root.Children.Add(node);
				}
				{
					TreeNode<string> node = new TreeNode<string>() { Data = "프로그래밍팀" };
					node.Children.Add(new TreeNode<string>() { Data = "서버" });
					node.Children.Add(new TreeNode<string>() { Data = "클라" });
					node.Children.Add(new TreeNode<string>() { Data = "엔진" });
					root.Children.Add(node);
				}
				{
					TreeNode<string> node = new TreeNode<string>() { Data = "아트팀" };
					node.Children.Add(new TreeNode<string>() { Data = "배경" });
					node.Children.Add(new TreeNode<string>() { Data = "캐릭터" });
					root.Children.Add(node);
				}
			}

			return root;
		}

		static void PrintTree(TreeNode<string> root)
		{
			//접근
			Console.WriteLine(root.Data);
			
			foreach (TreeNode<string> child in root.Children)
			{
				PrintTree(child);
			}
		}

		static int GetHeight(TreeNode<string> root)
		{
			int height = 0;
			foreach (TreeNode<string> child in root.Children)
			{
				int newHight = GetHeight(child) + 1;
				height = Math.Max(height, newHight);
			}

			return height;
		}

		static void Main(string[] args)
		{
			#region graph
			Graph graph = new Graph();
			// DFS
			//graph.DFS_Stack(0);

			// BFS
			//graph.BFS(0);
			#endregion

			#region Tree
			//TreeNode<string> root = MakeTree();
			//PrintTree(root);

			#endregion

			PrioirtyQueue<Knight> q = new PrioirtyQueue<Knight>();
			q.Push(new Knight() { Id = 20 });
			q.Push(new Knight() { Id = 30 });
			q.Push(new Knight() { Id = 40 });
			q.Push(new Knight() { Id = 10 });
			q.Push(new Knight() { Id = 05 });

			while (q.Count() > 0)
			{
				Console.WriteLine(q.Pop().Id);
			}
		}
	}
}
