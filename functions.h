#include <iostream>
#include <string>
#include <time.h>

void CommandAnalyzer(void);
int gamepvp(void);
int gamepve(void);
int aimove(int[9]);
void printgrid(int [9]);
bool winCondition(int [9]);

void CommandAnalyzer(void)
{
	int t = 0, pvpg = 0, pveg = 0, pvpd = 0, pved = 0;
	int p1 = 0, p2 = 0, p = 0, comp = 0;
	std::cout << "Welcome to Tic Tac Toe game\nType 'start' to start a new game\nType 'quit' to shutdown\n";
	while (true)
	{
		char input[64];
		std::cout << "Enter command:\n";
		std::cin >> input;
		if (strncmp(input, "quit", 5) == 0)
		{
			break;
		}
		else if (strncmp(input, "help", 5) == 0)
		{
			std::cout << "Tic Tac Toe is a game for two players who take turns marking the spaces in a three-by-three grid with X or O.\n";
			std::cout << "The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner.\n";
			std::cout << "   |   |   \n 1 | 2 | 3 \n___|___|___\n   |   |   \n 4 | 5 | 6 \n___|___|___\n   |   |   \n 7 | 8 | 9 \n   |   |   \n";
		}
		else if (strncmp(input, "start", 6) == 0)
		{
			std::cout << "Type '1' to start game vs computer\nType '2' to start game vs player\n";
			std::cin >> t;
			if (t == 2)
			{
				t = gamepvp();
				if (t == 1)
				{
					p1++;
				}
				else if (t == 2)
				{
					p2++;
				}
				else
				{
					pvpd++;
				}
				pvpg++;
				std::cout << "Games vs player played: " << pvpg << "\nPlayer1 won: " << p1 << "\nPlayer2 won: " << p2 << "\nDraws:" << pvpd << "\n\n";
				std::cout << "Welcome to Tic Tac Toe game\nType 'start' to start a new game\nType 'quit' to shutdown\n";
			}
			else if (t == 1)
			{
				t = gamepve();
				if (t == 1)
				{
					p++;
				}
				else if (t == 2)
				{
					comp++;
				}
				else
				{
					pvpd++;
				}
				pvpg++;
				std::cout << "Games vs computer played: " << pveg << "\nPlayer won: " << p << "\nComputer won: " << comp << "\nDraws:" << pved << "\n\n";
				std::cout << "Welcome to Tic Tac Toe game\nType 'start' to start a new game\nType 'quit' to shutdown\n";
			}
			else
			{
				std::cout << "Wrong command. Type 'help' to get info\n";
			}
		}
		else
		{
			std::cout << "Wrong command. Type 'help' to get info\n";
		}
	}
}

int gamepvp(void)
{
	int c = 0;
	int i = 0;
	int grid[9] = {0};
	while (true)
	{
		i = 0;
		c++;
		printgrid(grid);
		std::cout << "Turn " << c << "\nPlayer" << 2 - (c%2) <<"'s turn, choose cell number(1 - 9):\n";
		while (i < 1 || i > 9 || grid[i - 1] != 0)
		{
			std::cin >> i;
			if (i < 1 || i > 9 || grid[i - 1] != 0)
			{
				std::cout << "Illegal move\n";
			}
		}
		grid[i - 1] = 2 - (c % 2);
		if (winCondition(grid))
		{
			printgrid(grid);
			std::cout << "Player" << 2 - (c % 2) << " won";
			if (c % 2 == 1)
			{
				std::cout << "(X)\n";
			}
			else
			{
				std::cout << "(O)\n";
			}
			return 2 - (c % 2);
		}
		else if (c == 9)
		{
			printgrid(grid);
			std::cout << "Draw\n";
			return 0;
		}
	}
}

int gamepve(void)
{
	int c = 0;
	int i = 0;
	int grid[9] = { 0 };
	while (true)
	{
		i = 0;
		c++;
		printgrid(grid);
		if (c % 2 == 1)
		{
			std::cout << "Turn " << c << "\nPlayer's turn, choose cell number(1 - 9):\n";
			while (i < 1 || i > 9 || grid[i - 1] != 0)
			{
				std::cin >> i;
				if (i < 1 || i > 9 || grid[i - 1] != 0)
				{
					std::cout << "Illegal move\n";
				}
			}
			grid[i - 1] = 2 - (c % 2);
		}
		else
		{
			std::cout << "Turn " << c << "\nComputer's turn:\n";
			if (aimove(grid) == -1)
			{
				while (i < 1 || i > 9 || grid[i - 1] != 0)
				{
					i = (rand() % 9);
				}
			}
			else
			{
				i = aimove(grid);
			}
			std::cout << i + 1 << "\n";
			grid[i] = 2 - (c % 2);
		}
		if (winCondition(grid))
		{
			printgrid(grid);
			if (c % 2 == 1)
			{
				std::cout << "Player won(X)\n";
			}
			else
			{
				std::cout << "Computer won(O)\n";
			}
			return 2 - (c % 2);
		}
		else if (c == 9)
		{
			printgrid(grid);
			std::cout << "Draw\n";
			return 0;
		}
	}
}

bool winCondition(int grid[9])
{
	for (int i = 0; i < 3; i++)
	{
		if (grid[i] == grid[i + 3] && grid[i] == grid[i + 6] && grid[i] != 0)
		{
			return true;
		}
		if (grid[3 * i] == grid[3 * i + 1] && grid[3 * i] == grid[3 * i + 2] && grid[3 * i] != 0)
		{
			return true;
		}
	}
	if (grid[0] == grid[4] && grid[0] == grid[8] && grid[0] != 0)
	{
		return true;
	}
	if (grid[2] == grid[4] && grid[2] == grid[6] && grid[2] != 0)
	{
		return true;
	}
	return false;
}

int aimove(int grid[9])
{
	for (int i = 0; i < 3; i++)
	{
		if (grid[3 * i] == grid[3 * i + 1] && grid[3 * i] == 2 && grid[3 * i + 2] == 0)
		{
			return 3 * i + 2;
		}
		if (grid[3 * i] == grid[3 * i + 2] && grid[3 * i] == 2 && grid[3 * i + 1] == 0)
		{
			return 3 * i + 1;
		}
		if (grid[3 * i + 1] == grid[3 * i + 2] && grid[3 * i + 1] == 2 && grid[3 * i] == 0)
		{
			return 3 * i;
		}

		if (grid[i] == grid[i + 3] && grid[i] == 2 && grid[i + 6] == 0)
		{
			return i + 6;
		}
		if (grid[i] == grid[i + 6] && grid[i] == 2 && grid[i + 3] == 0)
		{
			return i + 3;
		}
		if (grid[i + 3] == grid[i + 6] && grid[i + 3] == 2 && grid[i] == 0)
		{
			return i;
		}

		if (grid[0] == grid[4] && grid[0] == 2 && grid[8] == 0)
		{
			return 8;
		}
		if (grid[0] == grid[8] && grid[0] == 2 && grid[4] == 0)
		{
			return 4;
		}
		if (grid[4] == grid[8] && grid[4] == 2 && grid[0] == 0)
		{
			return 0;
		}

		if (grid[2] == grid[4] && grid[2] == 2 && grid[6] == 0)
		{
			return 6;
		}
		if (grid[2] == grid[6] && grid[2] == 2 && grid[4] == 0)
		{
			return 4;
		}
		if (grid[4] == grid[6] && grid[4] == 2 && grid[2] == 0)
		{
			return 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (grid[3 * i] == grid[3 * i + 1] && grid[3 * i] == 1 && grid[3 * i + 2] == 0)
		{
			return 3 * i + 2;
		}
		if (grid[3 * i] == grid[3 * i + 2] && grid[3 * i] == 1 && grid[3 * i + 1] == 0)
		{
			return 3 * i + 1;
		}
		if (grid[3 * i + 1] == grid[3 * i + 2] && grid[3 * i + 1] == 1 && grid[3 * i] == 0)
		{
			return 3 * i;
		}

		if (grid[i] == grid[i + 3] && grid[i] == 1 && grid[i + 6] == 0)
		{
			return i + 6;
		}
		if (grid[i] == grid[i + 6] && grid[i] == 1 && grid[i + 3] == 0)
		{
			return i + 3;
		}
		if (grid[i + 3] == grid[i + 6] && grid[i + 3] == 1 && grid[i] == 0)
		{
			return i;
		}

		if (grid[0] == grid[4] && grid[0] == 1 && grid[8] == 0)
		{
			return 8;
		}
		if (grid[0] == grid[8] && grid[0] == 1 && grid[4] == 0)
		{
			return 4;
		}
		if (grid[4] == grid[8] && grid[4] == 1 && grid[0] == 0)
		{
			return 0;
		}

		if (grid[2] == grid[4] && grid[2] == 1 && grid[6] == 0)
		{
			return 6;
		}
		if (grid[2] == grid[6] && grid[2] == 1 && grid[4] == 0)
		{
			return 4;
		}
		if (grid[4] == grid[6] && grid[4] == 1 && grid[2] == 0)
		{
			return 2;
		}
	}
	return -1;
}



void printgrid(int grid[9])
{
	std::cout << "   |   |   \n ";
	if(grid[0] == 0)
	{
		std::cout << " ";
	}
	else if(grid[0] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if(grid[1] == 0)
	{
		std::cout << " ";
	}
	else if (grid[1] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if(grid[2] == 0)
	{
		std::cout << " ";
	}
	else if (grid[2] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " \n___|___|___\n   |   |   \n ";
	if (grid[3] == 0)
	{
		std::cout << " ";
	}
	else if (grid[3] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if (grid[4] == 0)
	{
		std::cout << " ";
	}
	else if (grid[4] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if (grid[5] == 0)
	{
		std::cout << " ";
	}
	else if (grid[5] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " \n___|___|___\n   |   |   \n ";
	if (grid[6] == 0)
	{
		std::cout << " ";
	}
	else if (grid[6] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if (grid[7] == 0)
	{
		std::cout << " ";
	}
	else if (grid[7] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " | ";
	if (grid[8] == 0)
	{
		std::cout << " ";
	}
	else if (grid[8] == 1)
	{
		std::cout << "X";
	}
	else
	{
		std::cout << "O";
	}
	std::cout << " \n   |   |   \n";
}