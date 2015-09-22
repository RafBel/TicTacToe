#ifndef TICTACTOE_HEADER_H
#define TICTACTOE_HEADER_H

#define TICTACTOE_SQUARES 9
#define PI_TWO 2*3.14159265359

enum TTT {blank, X, O}; //blank, X or O for the 6 squares

class tictactoe
{
public:
	//methods:
	tictactoe(void);
	bool newGame(void);
	void updateGame(unsigned);
	TTT getTTTSquare(unsigned);
	unsigned getPlayerTurn(void);
	bool getGameState(void);
	int AIBehaviour(void);

private:
	//attributes:
	TTT ttt[TICTACTOE_SQUARES];
	bool gameOver;
	unsigned player1Score, player2Score;
	unsigned playerTurn; //0 -> computer 1 -> player
	unsigned numEmptySquares;

	//methods:
	void checkForWin(void);
	void blankSquares(void);
	void AICheckMove(TTT, bool *);
	void sleep(int);

};

#endif