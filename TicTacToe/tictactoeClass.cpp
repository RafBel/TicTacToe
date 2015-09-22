#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "tictactoe_header.h"

tictactoe::tictactoe(void)
{
	blankSquares();
	gameOver = false;
	player1Score = 0; player2Score = 0;
	srand(time(NULL));
	playerTurn = rand()%2;
	numEmptySquares = TICTACTOE_SQUARES;
}

void tictactoe::sleep(int milisecs)
{
	clock_t goal = clock() + milisecs;
	while (goal > clock() );
}

void tictactoe::blankSquares(void)
{
	//all squares are blank
	for (unsigned counter = 0; counter < TICTACTOE_SQUARES; counter++)
		ttt[counter] = blank;
}

bool tictactoe::getGameState(void) {return gameOver; }

unsigned tictactoe::getPlayerTurn(void) {return playerTurn; }

TTT tictactoe::getTTTSquare(unsigned square)
{ 
	if ((square >= 0) || (square <= 8 ) )
		return ttt[square];
}

void tictactoe::checkForWin(void)
{
	//checks for all possibilities

	if ((ttt[0] == ttt[1]) && (ttt[0] == ttt[1])) //top horizontal line 
	{
		if (ttt[0] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[0] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[3] == ttt[4]) && (ttt[3] == ttt[5])) //middle horizontal line 
	{
		if (ttt[3] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[3] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[6] == ttt[7]) && (ttt[6] == ttt[8])) //bottom horizontal line 
	{
		if (ttt[6] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[6] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[0] == ttt[3]) && (ttt[0] == ttt[6])) //left vertical line 
	{
		if (ttt[0] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[0] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[1] == ttt[4]) && (ttt[1] == ttt[7])) //middle vertical line 
	{
		if (ttt[1] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[1] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[2] == ttt[5]) && (ttt[2] == ttt[8])) //right vertical line 
	{
		if (ttt[2] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[2] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[0] == ttt[4]) && (ttt[0] == ttt[8])) //left diagonal line 
	{
		if (ttt[0] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[0] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if ((ttt[2] == ttt[4]) && (ttt[2] == ttt[6])) //right diagonal line 
	{
		if (ttt[2] == X)
		{
			gameOver = true;
			player1Score++;
		}
		if (ttt[2] == O)
		{
			gameOver = true;
			player2Score++;
		}
	}

	if (numEmptySquares == 0) //if board is filled -> end game (draw or last minute win)
		gameOver= true;
}

bool tictactoe::newGame(void)
{
	if (gameOver == true)
	{
		sleep(2500);

		gameOver = false;
		blankSquares();

		//randomly selects the next player
		playerTurn = rand()%2;
		numEmptySquares = TICTACTOE_SQUARES;
		return true;
	}
	return false;
}

void tictactoe::updateGame(unsigned position) //designed for player
{
	if ((position >= 0) && (position <= 8) && (ttt[position] == blank)) //checks for mistakes
	{
		ttt[position] = X;
		--numEmptySquares;
		playerTurn = 0; //now AI's turn
		checkForWin();
	}

	
}

void tictactoe::AICheckMove(TTT check, bool *moveMade)
{
	unsigned counter;
	//horizontal lines
	for (counter = 0; (counter < TICTACTOE_SQUARES) && (*moveMade == false); counter += 3)
	{
		if ((ttt[counter] == check) && (ttt[counter + 1] == check) && (ttt[counter + 2] == blank)) // O O -
		{
			*moveMade = true;
			ttt[counter + 2] = O;
		}
		
		if ((ttt[counter] == check) && (ttt[counter + 1] == blank) && (ttt[counter + 2] == check)) // O - O
		{
			*moveMade = true;
			ttt[counter + 1] = O;
		}

		if ((ttt[counter] == blank) && (ttt[counter + 1] == check) && (ttt[counter + 2] == check)) // - O O
		{
			*moveMade = true;
			ttt[counter] = O;
		}
			
	}

	//vertical lines
	for (counter = 0; (counter < TICTACTOE_SQUARES/3) && (*moveMade == false); counter++)
	{
		if ((ttt[counter] == check) && (ttt[counter + 3] == check) && (ttt[counter + 6] == blank)) // O O -
		{
			*moveMade = true;
			ttt[counter + 6] = O;
		}
		
		if ((ttt[counter] == check) && (ttt[counter + 3] == blank) && (ttt[counter + 6] == check)) // O - O
		{
			*moveMade = true;
			ttt[counter + 3] = O;
		}

		if ((ttt[counter] == blank) && (ttt[counter + 3] == check) && (ttt[counter + 6] == check)) // - O O
		{
			*moveMade = true;
			ttt[counter] = O;
		}
			
	}

	//diagonal lines
	if ((ttt[4] == blank) && (*moveMade == false))
	{
		if ((ttt[0] == check && ttt[8] == check) || (ttt[2] == check && ttt[6] == check))
		{
			ttt[4] = O;
			*moveMade = true;
		}
	}

	if ((ttt[4] == check)  && (*moveMade == false))
	{
		if ((ttt[0] == check) && (ttt[8] == blank)) // O O -
		{
			ttt[8] = O;
			*moveMade = true;
		}

		if ((ttt[8] == check) && (ttt[0] == blank)) // - O O
		{
			ttt[0] = O;
			*moveMade = true;
		}

		if ((ttt[2] == check) && (ttt[6] == blank)) // O O -
		{
			ttt[6] = O;
			*moveMade = true;
		}

		if ((ttt[6] == check) && (ttt[2] == blank)) // - O O
		{
			ttt[2] = O;
			*moveMade = true;
		}

	}


	
}

int tictactoe::AIBehaviour(void) //tries to make AI seem somewhat intelligent
{
	unsigned counter;
	bool moveMade = false; //won't mark the tictactoe board twice if the move has already been made

	if (playerTurn == 0 && gameOver == false) //only execs if its AI's turn
	{
		//sleep(800);
		int tryMove;

		//1st priority - > finish the game (last move)
		AICheckMove(O, &moveMade);

		//2nd priority - > interrupt player's finishing move
		AICheckMove(X, &moveMade);

		//3rd priority -> trying to make a play
		if (moveMade == false)
		{
			tryMove = rand()%9;
			while (ttt[tryMove] != blank) {tryMove = rand()%9;}
			ttt[tryMove] = O;
		}

		--numEmptySquares; //one square filled
		checkForWin();
		playerTurn = 1; //now player's turn
	}

	return -1;
}