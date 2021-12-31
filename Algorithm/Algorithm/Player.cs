using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithm
{
	class Pos
	{
		public int X;
		public int Y;
		public Pos(int x, int y)
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

		const int move_tick = 60;
		int _sumTick = 0;

		List<Pos> _points = new List<Pos>();

		public void Initialize(int posX, int posY, Board board)
		{
			PosX = posX;
			PosY = posY;
			_board = board;

			BFS();
		}

		int _lastIndex = 0;
		public void Update(int deltaTick)
		{
			if (_lastIndex >= _points.Count) return;

			_sumTick += deltaTick;
			if (_sumTick >= move_tick)
			{
				_sumTick = 0;

				PosX = _points[_lastIndex].X;
				PosY = _points[_lastIndex].Y;
				_lastIndex++;
			}
		}

		void BFS()
		{
			int[] deltaX = new int[] { -1, 0, 1, 0 };
			int[] deltaY = new int[] { 0, -1, 0, 1 };
			bool[,] visited = new bool[_board.Size, _board.Size];
			Pos[,] parent = new Pos[_board.Size, _board.Size];

			Queue<Pos> q = new Queue<Pos>();
			q.Enqueue(new Pos(PosX, PosY));

			visited[PosX, PosY] = true;
			parent[PosX, PosY] = new Pos(PosX, PosY);

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
					if (visited[nextX, nextY])
						continue;

					q.Enqueue(new Pos(nextX, nextY));
					visited[nextX, nextY] = true;
					parent[nextX, nextY] = new Pos(nowX, nowY);
				}
			}

			int x = _board.DestX;
			int y = _board.DestY;

			// 시작점까지 거꾸로 탐색
			while (parent[x, y].Y != y || parent[x, y].X != x)
			{
				_points.Add(new Pos(x, y));
				Pos pos = parent[x, y];
				y = pos.Y;
				x = pos.X;
			}
			_points.Add(new Pos(x, y));
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
