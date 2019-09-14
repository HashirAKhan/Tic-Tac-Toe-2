# Tic-Tac-Toe-2

HOW TO RUN
simply compile the two cpp files together using "g++ Board.cpp Tictactoe.cpp" and run with ./a.out
The program will proceed to ask you how many people are playing (Single Player against a computer or Multiplayer against another human)

If you select single player you will then have the option to select the computers difficulty
Heres the difference between each of your options

  Difficulty 1: The computer will select a space to mark completely at random.
  
  Difficulty 2: If the computer has an oppurtunity to win on its turn or to block the player from winning, There is a high chance it will mark that space.
                (winning takes priority over blocking)
  
  Difficulty 3: If the computer has has an oppurtunity to win on its turn or black the player from winning it will ALWAYS mark that spot.
                (winning takes priority over blocking)
                (The only way for the player to win is to have two different spaces that would allow you to win on the same turn, the computer can only block one)
                
                
 HOW TO PLAY
 
 -------------
 | 1 | 2 | 3 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 7 | 8 | 9 |
 -------------
 
 Simply choose a number between 1 and 9 inclusive to select a space you wish to mark
 in Single player the computer will make its turn after you
 in Multiplayer you must alternate in choosing a space to mark
 
 HOW TO WIN
 just like normal tic-tac-toe make a row, column or diagnal filled with your mark and you win.
