#include <iostream>
#include <cstdlib>


//Board object will contain all of the games functions
class Board{
  public:
    //Constructor sets the initial values of the board into empty spaces as nothing has been marked yet
    Board(){
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          arr[i][j] = ' ';
        }
      }
    }


    //Function is used to nicely print out the board, including all the areas that have been marked.
    void printBoard(){
      std::cout<<"_____________"<<std::endl;
      for (int i = 0; i < 3; i++){
        std::cout<<'|'<<' '<<arr[i][0]<<' '<<'|'<<' '<<arr[i][1]<<' '<<'|'<<' '<<arr[i][2]<<' '<<'|'<<std::endl<<"-------------"<<std::endl;

      }
    }

    //The layout for the board allows the user to select a spot using numbers 1-9.
    //This function translates the integer to get the row that it would be in the array.
    int getRow(int space){
      if(space < 4){
        return 0;
      }
      else if(space < 7){
        return 1;
      }
      else{
        return 2;
      }
    }


    //The layout for the board allows the user to select a spot using numbers 1-9.
    //This function translates the integer to get the col that it would be in the array.
    int getCol(int space){
      if(space%3==1){
        return 0;
      }
      else if(space%3==2){
        return 1;
      }
      else{
        return 2;
      }
    }

    //takes a int value from 1-9 and checks to see if the value at [row][col] is empty ' '
    bool isSpaceEmpty(int space){
      if(arr[getRow(space)][getCol(space)]==' '){
        return true;
      }
      else{
        return false;
      }
    }

    //Function that allows a player to make their turn
    void playerTurn(char symbol){

      int input;
      do{
        std::cout<<"Please choose a space(1-9) to mark your " << symbol<<": ";
        std::cin>>input;
      } while(input<1||input>9||!isSpaceEmpty(input));   //makes sure the input is within the array and not already taken

      arr[getRow(input)][getCol(input)] = symbol;
    }


    //Checks to see if the board has a winner or is full and should end with a tie
    bool checkBoard(char symbol){
      for(int i = 0; i < 3; i++){
        if(arr[i][0] == symbol && arr[i][1] == symbol && arr[i][2] == symbol){
          std::cout<<symbol<<" has won the game!"<<std::endl;
          return true;
        }
        if(arr[0][i] == symbol && arr[1][i] == symbol && arr[2][i] == symbol){
          std::cout<<symbol<<" has won the game!"<<std::endl;
          return true;
        }
      }
      if(arr[0][0] == symbol && arr[1][1] == symbol && arr[2][2] == symbol){
        std::cout<<symbol<<" has won the game!"<<std::endl;
        return true;
      }
      if(arr[0][2] == symbol && arr[1][1] == symbol && arr[2][0] == symbol){
        std::cout<<symbol<<" has won the game!"<<std::endl;
        return true;
      }

      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(arr[i][j]==' '){
            return false;
          }
        }
      }

      std::cout<<"Tie Game!"<<std::endl;
      return true;
    }


    //Function used for computer to scan the board for potential blocking or winning moves.
    int checkForTwo(char symbol){
      for(int i = 0; i < 3; i++){
        if(arr[i][0] == symbol && arr [i][1]== symbol && arr[i][2]== ' '){
          return (3+3*i);
        }
        if(arr[i][0] == symbol && arr [i][1]== ' ' && arr[i][2]== symbol){
          return (2+3*i);
        }
        if(arr[i][0] == ' ' && arr [i][1]== symbol && arr[i][2]== symbol){
          return (1+3*i);
        }


        if(arr[0][i] == symbol && arr [1][i]== symbol && arr[2][i]== ' '){
          return (7+i);
        }
        if(arr[0][i] == symbol && arr [1][i]== ' ' && arr[2][i]== symbol){
          return (4+i);
        }
        if(arr[0][i] == ' ' && arr [1][i]== symbol && arr[2][i]== symbol){
          return (1+i);
        }
      }

      if(arr[0][0] == symbol && arr[1][1] == symbol && arr[2][2] == ' '){
        return 9;
      }
      if(arr[0][0] == symbol && arr[1][1] == ' ' && arr[2][2] == symbol){
        return 5;
      }
      if(arr[0][0] == ' ' && arr[1][1] == symbol && arr[2][2] == symbol){
        return 1;
      }

      if(arr[0][2] == symbol && arr[1][1] == symbol && arr[2][0] == ' '){
        return 7;
      }
      if(arr[0][0] == symbol && arr[1][1] == ' ' && arr[2][2] == symbol){
        return 5;
      }
      if(arr[0][0] == ' ' && arr[1][1] == symbol && arr[2][2] == symbol){
        return 3;
      }

      return -1;
    }

    //Function that allows a computer to make a turn
    //diffuculty is selcected by the player and decides the chances that the computer will use the checkForTwo function
    void computersTurn(int difficulty){
      int test;

      switch(difficulty){
        case 1: test = 0;
                break;
        case 2: test = rand()%5;
                break;
        case 3: test = 8;
      }

      std::cout<<test<<std::endl;
      if(test > 1){
        int move = checkForTwo('O');
        if(move != -1){
          arr[getRow(move)][getCol(move)] = 'O';
          return;
        }

        move = checkForTwo('X');
        if(move != -1){
          arr[getRow(move)][getCol(move)] = 'O';
          return;
        }
      }
      do{
        test = rand()%9;
      } while(test+1<1||test+1>9||!isSpaceEmpty(test+1));
      arr[getRow(test+1)][getCol(test+1)] = 'O';
      return;
    }


    //resets the board to empty spaces ' '
    void resetBoard(){
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          arr[i][j] = ' ';
        }
      }
    }

  private:
    char arr[3][3];   //Stores what areas have been marked already
};
