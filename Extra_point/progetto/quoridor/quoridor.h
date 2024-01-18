#ifndef _QUORIDOR_H_
#define _QUORIDOR_H_

#include "../coordinates/coordinates.h"

// Valori di modalit� e giocatore
#define WAITING 0
#define PLAYING 1
#define CHOOSING 2
#define READY 3
#define PLAYER1 0
#define PLAYER2 1
#define HUMAN 0
#define NPC 1
#define BOARD1_ID 0
#define BOARD2_ID 1
#define DEFAULT_CHOICE 0
#define NO_PLAYER 0xFF
#define HANDSHAKE_OFF 0
#define HANDSHAKE_ON 1
#define HANDSHAKE_DONE 2
#define HANDSHAKE_READY 3

// Numero massimo muri
#define MAX_NUM_WALLS 8

// Lunghezza massima di un messaggio, stampabile su singola riga
#define MESSAGE_LENGTH (MAX_X / 8 + 1)

// Valori per caratteristiche mossa
#define PLAYER_MOVE 0
#define WALL_PLACEMENT 1
#define OUT_OF_TIME_MOVE 1
#define VERTICAL_WALL 0
#define HORIZONTAL_WALL 1

// Modalit� di gioco
typedef struct {
	unsigned char handshake;
	unsigned char numBoards;
	unsigned char boardPlayer;
	unsigned char playersType[2];
} ModeType;

// Muro
typedef struct{
	Coordinates position[MAX_NUM_WALLS];	// posizione del centro dei muri
	char dir[MAX_NUM_WALLS];								// direzione dei muri
	char used;															// numero di muri utilizzati, in [0, MAX_NUM_WALLS]
} WallType;

// Variabile di stato
typedef struct {
	char mode;									// modalit� di gioco {0: attesa, 1: gioco}
	char timeRemaining;					// tempo rimanente, in [0, 20] s
	char player;								// indice del giocatore, pari a playerId-1
	char pendingWall;						// flag per indicare presenza muro in attesa di conferma
	int lastMove;								// intero a 32 bit per salvare l'ultima mossa effettuata
	char validMove;							// flag per indicare se l'ultimo movimento effettuato � verso una posizione valida
	char numHighlited;					// numero celle evidenziate
	char finishedNPCMove;				// indica mossa effettuata dal NPC: {0: in corso/non in gioco, 1: mossa conclusa, partita in corso, 2: mossa conclusa, partita terminata}
	Coordinates highlited[5];		// posizione celle evidenziate
	Coordinates currentPos[2];	// posizione corrente dei due giocatori
	WallType walls[2];					// muri correnti dei due giocatori
} MatchType;

// quoridor.c
int victory(Coordinates pos, char player);
int getAvailableWalls(char player);
int checkNotOverlapping(Coordinates centerPos, char dir);
int validPos(Coordinates destPos, Coordinates currentPos);
void selectAdj(Coordinates *pos, char player, Coordinates *selected, char *numSelected);
void setVictoryMessage(void);
void setWall(Coordinates centerPos, char direction, char playerId);
void initGame(void);
void setMode(char modeValue);
void setPlayer(char playerValue);
int getOtherPlayer(char player);
void highliteAdj(Coordinates pos);
void eraseHighlightedAdj(void);
void setNextPos(int h, int v);
void move(void);
void newWall(Coordinates centerPos, char direction);
void rotateWall(void);
void confirmWall(void);
void undoWall(void);
void setNextWall(int h, int v);
void saveMove(int playerId, int moveType, int wallOrientation, Coordinates *destPos);
void sendMove(void);
void setNextChoice(int step);
void confirmChoice(void);
void updateOpponentData(unsigned char playerId, unsigned char moveType, unsigned char wallDir, int y, int x);
void setOpponentTurn(void);

// NPC.c
void NPC_playTurn(MatchType *status, ModeType *mode, Coordinates *nextPos);

#endif
