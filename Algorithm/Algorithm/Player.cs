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

		int _dir = (int)Dir.Up;

		List<Pos> _points = new List<Pos>();

		public void Initialize(int posX, int posY, Board board)
		{
			PosX = posX;
			PosY = posY;

			_board = board;

			int[] frontX = new int[] { 0, -1, 0, 1 };
			int[] frontY = new int[] { -1, 0, 1, 0 };
			int[] rightX = new int[] { 1, 0, -1, 0 };
			int[] rightY = new int[] { 0, -1, 0, 1 };

			_points.Add(new Pos(PosX, PosY));
			while (PosX != board.DestX || PosY != board.DestY)
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
	}
}
