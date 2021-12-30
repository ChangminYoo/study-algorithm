using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithm
{
	class Board
	{
		public TileType[,] Tile { get; private set; }
		public int Size { get; private set; }
		const char circle = '\u25cf';

		public int DestX { get; private set; }
		public int DestY { get; private set; }

		Player _player;

		public enum TileType
		{
			Empty,
			Wall,
		}

		public void Initialize(int size, Player player)
		{
			if (size % 2 == 0)
				return;

			Tile = new TileType[size, size];
			Size = size;

			_player = player;
			DestX = Size - 2;
			DestY = Size - 2;
			// Mazes for Programmers
			//GenerateByBinaryTree();
			GenerateBySideWinder();
		}

		void GenerateByBinaryTree()
		{		
			// 벽을 막기
			for (int x = 0; x < Size; x++)
			{
				for (int y = 0; y < Size; y++)
				{
					if (x % 2 == 0 || y % 2 == 0)
					{
						Tile[y, x] = TileType.Wall;
					}
					else
					{
						Tile[y, x] = TileType.Empty;
					}
				}
			}
			// 랜덤으로 우측 혹은 아래로 길 뚫기
			Random rand = new Random();
			for (int x = 0; x < Size; x++)
			{
				for (int y = 0; y < Size; y++)
				{
					if (x % 2 == 0 || y % 2 == 0) continue;
					if (x == Size - 2 && y == Size - 2) continue;
					if (x == Size - 2)
					{
						Tile[y + 1, x] = TileType.Empty;
						continue;
					}
					if (y == Size - 2)
					{
						Tile[y, x + 1] = TileType.Empty;
						continue;
					}


					if (rand.Next(0, 2) == 0)
					{
						Tile[y, x + 1] = TileType.Empty;
					}
					else
					{
						Tile[y + 1, x] = TileType.Empty;
					}
				}
			}
		}

		void GenerateBySideWinder()
		{
			// 벽을 막기
			for (int x = 0; x < Size; x++)
			{
				for (int y = 0; y < Size; y++)
				{
					if (x % 2 == 0 || y % 2 == 0)
					{
						Tile[y, x] = TileType.Wall;
					}
					else
					{
						Tile[y, x] = TileType.Empty;
					}
				}
			}
			// 랜덤으로 우측 혹은 아래로 길 뚫기
			Random rand = new Random();
			for (int y = 0; y < Size; y++)
			{
				int count = 1;
				for (int x = 0; x < Size; x++)
				{
					if (x % 2 == 0 || y % 2 == 0) continue;
					if (x == Size - 2 && y == Size - 2) continue;
					if (x == Size - 2)
					{
						Tile[y + 1, x] = TileType.Empty;
						continue;
					}
					if (y == Size - 2)
					{
						Tile[y, x + 1] = TileType.Empty;
						continue;
					}

					if (rand.Next(0, 2) == 0)
					{
						Tile[y , x + 1] = TileType.Empty;
						count++;
					}
					else
					{
						int path = rand.Next(0, count);
						Tile[y + 1, x - path * 2] = TileType.Empty;
						count = 1;
					}
				}
			}
		}

		public void Render()
		{
			ConsoleColor prevColor = Console.ForegroundColor;
			for (int x = 0; x < Size; x++)
			{
				for (int y = 0; y < Size; y++)
				{
					// 플레이어 좌표
					if (y == _player.PosY && x == _player.PosX)
					{
						Console.ForegroundColor = ConsoleColor.Blue;
					}
					// 목적지 (출구)
					else if (y == DestY && x == DestX)
					{
						Console.ForegroundColor = ConsoleColor.Yellow;
					}
					else
					{
						Console.ForegroundColor = GetConsoleColor(Tile[y, x]);
					}

					Console.Write(circle);
				}
				Console.WriteLine();
			}

			Console.ForegroundColor = prevColor;
		}

		ConsoleColor GetConsoleColor(TileType type)
		{
			switch (type)
			{
				case TileType.Empty:
					return ConsoleColor.Green;

				case TileType.Wall:
					return ConsoleColor.Red;
				default:
					return ConsoleColor.Green;
			}
		}
	}
}
