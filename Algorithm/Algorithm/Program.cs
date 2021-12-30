using System;

namespace Algorithm
{
	class Program
	{
		static void Main(string[] args)
		{
			Board board = new Board();
			Player player = new Player();
			board.Initialize(25, player);
			player.Initialize(1, 1, board);

			Console.CursorVisible = false;
			int lastTick = 0;
			const int wait_Tick = 1000 / 60;

			while (true)
			{
				#region 프레임 관리
				int currTick = System.Environment.TickCount;
				int delatTick = currTick - lastTick;
				if (delatTick < wait_Tick) continue;
				lastTick = currTick;
				#endregion

				player.Update(delatTick);

				Console.SetCursorPosition(0, 0);
				board.Render();
			}
			
		}

	}
}
