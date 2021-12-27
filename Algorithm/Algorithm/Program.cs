using System;

namespace Algorithm
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.CursorVisible = false;
			int lastTick = 0;
			const int waitTick = 1000 / 100;
			const int boardX = 25, boardY = 25;

			while (true)
			{
				#region 프레임 관리
				int currTick = System.Environment.TickCount;
				if (currTick - lastTick < waitTick) continue;
				lastTick = currTick;
				#endregion

				Console.SetCursorPosition(0, 0);
				Print(boardX, boardY);
			}
			
		}

		static void Print(int sizeX, int sizeY)
		{
			const char circle = '\u25cf';
			for (int i = 0; i < sizeX; i++)
			{
				for(int j = 0; j < sizeY; j++)
				{
					Console.Write(circle);
				}
				Console.WriteLine();
			}
		}
	}
}
