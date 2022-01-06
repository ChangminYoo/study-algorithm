using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithm
{
	class Pos
	{
		public int X;
		public int Y;
		public Pos(int y, int x)
		{
			X = x;
			Y = y;
		}
	}

	class Player
	{
		enum Dir
		{
			Up = 0,
			Left,
			Down,
			Right,
		}
		public int PosX { get; private set; }
		public int PosY { get; private set; }
		Board _board;

		const int move_tick = 100;
		int _sumTick = 0;

		List<Pos> _points = new List<Pos>();

		public void Initialize(int posX, int posY, Board board)
		{
			PosX = posX;
			PosY = posY;
			_board = board;

			//BFS();
			AStar();
		}

		int _lastIndex = 0;
		public void Update(int deltaTick)
		{
			if (_lastIndex >= _points.Count)
			{
				_lastIndex = 0;
				_points.Clear();
				_board.Initialize(_board.Size, this);
				Initialize(1, 1, _board);
				return;
			}

			_sumTick += deltaTick;
			if (_sumTick >= move_tick)
			{
				_sumTick = 0;

				PosX = _points[_lastIndex].X;
				PosY = _points[_lastIndex].Y;
				_lastIndex++;
			}
		}

		struct PQNode : IComparable<PQNode>
		{
			public int F;
			public int G;
			public int Y;
			public int X;

			int IComparable<PQNode>.CompareTo(PQNode other)
			{
				if (F == other.F) return 0;
				return F < other.F ? 1 : -1;
			}
		}

		void AStar()
		{
			int[] cost = new int[] { 1, 1, 1, 1 };
			int[] deltaX = new int[] { -1, 0, 1, 0 };
			int[] deltaY = new int[] { 0, -1, 0, 1 };
			// 대각선 이동 추가시 cost delta 추가후(단 cost에 10곱 대각은 소수점이므로)
			// 아래 Math.Abs(_board.DestY - PosY) + Math.Abs(_board.DestX - PosX) 에 10 곱하면 됨 

			// 점수 매기기
			// F = G + H
			// F : 최종 점수 (작을 수록 좋음, 경로에 따라 달라짐)
			// G : 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을 수록 좋음, 경로에 따라 달라짐)
			// H : 목적지에서 얼마나 가까운지 (작을 수록 좋음, 고정)

			// (y, x)에 이미 방문했는지 여부( 방문 = closed 상태)
			bool[,] closed = new bool[_board.Size, _board.Size];

			// (y, x) 가는 길을 한 번이라도 발견했는지
			// 발견X => MaxValue
			// 발견O => F = G + H
			int[,] open = new int[_board.Size, _board.Size]; // OpenList
			for (int y = 0; y < _board.Size; y++)
			{
				for (int x = 0; x < _board.Size; x++)
				{
					open[y, x] = Int32.MaxValue;
				}
			}

			Pos[,] parent = new Pos[_board.Size, _board.Size];

			// 오픈 리스트에 있는 정보들 중에서, 가장 좋은 후보를 빠르게 뽑아오기 위한 도구
			PrioirtyQueue<PQNode> pq = new PrioirtyQueue<PQNode>();

			// 시작점 발견 (예약 진행) G = 0 H = (목표지점 - 시작지점)
			open[PosY, PosX] = Math.Abs(_board.DestY - PosY) + Math.Abs(_board.DestX - PosX);
			pq.Push(new PQNode() { F = Math.Abs(_board.DestY - PosY) + Math.Abs(_board.DestX - PosX), G = 0, Y = PosY, X = PosX });
			parent[PosY, PosX] = new Pos(PosY, PosX);

			while (pq.Count > 0)
			{
				// 제일 좋은 후보를 찾는다.
				PQNode node = pq.Pop();
				// 동일한 좌표를 여러 경로로 찾아서, 더 빠른 경로로 인해서 이미 방문(closed)된 경우 스킵
				if (closed[node.Y, node.X])
					continue;

				// 방문한다.
				closed[node.Y, node.X] = true;
				// 목적지 도착했으면 바로 종료
				if (node.Y == _board.DestY && node.X == _board.DestX)
					break;

				// 상하 좌우 등 이동할 수 있는 좌표인지 확인해서 예약(open)한다.
				for (int i = 0; i < deltaX.Length; i++)
				{
					int nextY = node.Y + deltaY[i];
					int nextX = node.X + deltaX[i];
					// 유효하지 않으면 스킵
					if (nextX < 0 || nextX >= _board.Size || nextY < 0 || nextY >= _board.Size)
						continue;
					// 벽으로 막힌경우 스킵
					if (_board.Tile[nextY, nextX] == Board.TileType.Wall)
						continue;
					// 이미 방문한 곳이면 스킵
					if (closed[nextY, nextX])
						continue;

					// 비용 계산
					int g = node.G + cost[i];
					int h = Math.Abs(_board.DestY - nextY) + Math.Abs(_board.DestX - nextX);

					// 이미 다른 경로에 더 빠른 길 있으면 스킵
					if (open[nextY, nextX] < g + h)
						continue;

					// 예약 진행
					open[nextY, nextX] = g + h;
					pq.Push(new PQNode { F = g + h, G = g, Y = nextY, X = nextX });

					parent[nextY, nextX] = new Pos(node.Y, node.X);
				}
			}

			CalcPathFromParent(parent);
		}

		void BFS()
		{
			int[] deltaX = new int[] { -1, 0, 1, 0 };
			int[] deltaY = new int[] { 0, -1, 0, 1 };
			bool[,] visited = new bool[_board.Size, _board.Size];
			Pos[,] parent = new Pos[_board.Size, _board.Size];

			Queue<Pos> q = new Queue<Pos>();
			q.Enqueue(new Pos(PosY, PosX));

			visited[PosY, PosX] = true;
			parent[PosY, PosX] = new Pos(PosY, PosX);

			while (q.Count > 0)
			{
				Pos pos = q.Dequeue();
				int nowX = pos.X;
				int nowY = pos.Y;	

				for (int i = 0; i < 4; i++)
				{
					int nextX = nowX + deltaX[i];
					int nextY = nowY + deltaY[i];
					if (nextX < 0 || nextX >= _board.Size || nextY < 0 || nextY >= _board.Size)
						continue;
					if (_board.Tile[nextY, nextX] == Board.TileType.Wall)
						continue;
					if (visited[nextY, nextX])
						continue;

					q.Enqueue(new Pos(nextY, nextX));
					visited[nextY, nextX] = true;
					parent[nextY, nextX] = new Pos(nowY, nowX);
				}
			}		
			CalcPathFromParent(parent);
		}

		void CalcPathFromParent(Pos[,] parent)
		{
			int x = _board.DestX;
			int y = _board.DestY;

			// 시작점까지 거꾸로 탐색
			while (parent[y, x].Y != y || parent[y, x].X != x)
			{
				_points.Add(new Pos(y, x));
				Pos pos = parent[y, x];
				y = pos.Y;
				x = pos.X;
			}
			_points.Add(new Pos(y, x));
			_points.Reverse();
		}

		#region 우수법
		
		int _dir = (int)Dir.Up;
		void RightHandFind()
		{
			int[] frontX = new int[] { 0, -1, 0, 1 };
			int[] frontY = new int[] { -1, 0, 1, 0 };
			int[] rightX = new int[] { 1, 0, -1, 0 };
			int[] rightY = new int[] { 0, -1, 0, 1 };

			_points.Add(new Pos(PosX, PosY));
			while (PosX != _board.DestX || PosY != _board.DestY)
			{
				// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
				if (_board.Tile[PosY + rightY[_dir], PosX + rightX[_dir]] == Board.TileType.Empty)
				{
					// 오른쪽 방향으로 90도 회전
					_dir = (_dir - 1 + 4) % 4;

					// 앞으로 한보 전진
					PosX = PosX + frontX[_dir];
					PosY = PosY + frontY[_dir];
					_points.Add(new Pos(PosX, PosY));
				}
				// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
				else if (_board.Tile[PosY + frontY[_dir], PosX + frontX[_dir]] == Board.TileType.Empty)
				{
					// 앞으로 한보 전진
					PosX = PosX + frontX[_dir];
					PosY = PosY + frontY[_dir];
					_points.Add(new Pos(PosX, PosY));
				}
				// 왼쪽으로 회전
				else
				{
					_dir = (_dir + 1 + 4) % 4;
				}
			}
		}

		#endregion
	}
}
