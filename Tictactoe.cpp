#include "Board.cpp"


void runGameSinglePlayer(Board* board, int difficulty){
  bool game = true;
  board->resetBoard();

  while(game){
    system("clear");
    board->printBoard();
    board->playerTurn('X');
    system("clear");
    board->printBoard();
    if(board->checkBoard('X')){
      return;
    }

    board->computersTurn(difficulty);
    system("clear");
    board->printBoard();
    if(board->checkBoard('O')){
      return;
    }
  }
}

void runTwoPlayerGame(Board* board){
  bool game = true;
  board->resetBoard();

  while(game){
    system("clear");
    board->printBoard();
    board->playerTurn('X');
    system("clear");
    board->printBoard();
    if(board->checkBoard('X')){
      return;
    }

    board->playerTurn('O');
    system("clear");
    board->printBoard();
    if(board->checkBoard('O')){
      return;
    }
  }
}


int main(){
  Board* board = new Board();
  int players;
  bool game = true;
  char playAgain;
  do{
    std::cout<<"How many people are playing? 1 or 2: ";
    std::cin>>players;
  } while(players <1 || players > 2);


  if(players==1){
    int difficulty;
    do{
      std::cout<<"select diffuculty level (1,2 or 3): ";
      std::cin>>difficulty;
    } while (difficulty<1||difficulty>3);

    while(game){
      runGameSinglePlayer(board, difficulty);
      do{
        std::cout<<"Would you like to play again? Y or N: ";
        std::cin>>playAgain;
      } while (!(playAgain == 'Y'|| playAgain == 'N'));
      if(playAgain == 'N'){
        return 0;
      }
    }
  }

  else{
    runTwoPlayerGame(board);
    do{
      std::cout<<"Would you like to play again? Y or N: ";
      std::cin>>playAgain;
    } while (!(playAgain == 'Y'|| playAgain == 'N'));
    if(playAgain == 'N'){
      return 0;
    }
  }
  //make seperate class for multiplayer
  //add computer difficulty
}
