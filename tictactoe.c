#include<stdio.h>
#include<stdlib.h>

void printBoard(const char (*board)[3]){
  printf("\n");
  printf(" %c ┃ %c ┃ %c\n", board[0][0], board[0][1], board[0][2]);
  printf("━━━╋━━━╋━━━\n");

  printf(" %c ┃ %c ┃ %c\n", board[1][0], board[1][1], board[1][2]);
  printf("━━━╋━━━╋━━━\n");
    
  printf(" %c ┃ %c ┃ %c\n", board[2][0], board[2][1], board[2][2]);
}

int isAligned(const char (*board)[3]){
  if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
    board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return 1;
  else{
    for(unsigned int row = 0; row <=2 ; ++row){
      if(board[row][0] == board[row][1] && board[row][1] == board[row][2])
        return 1;
    }
    for(unsigned int col = 0; col <=2; ++col){
      if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
        return 1;
    }
  }
  return 0;
}
int main(){
  char board[][3] = {
    {'0', '1', '2'},
    {'3', '4', '5'},
    {'6', '7', '8'}
  };
  int player = 1;
  int ch;
  int winner = 0;
  unsigned int row, col;

  for(unsigned int i = 0; i < 9; i++){
    system("clear");
    printBoard(board);
    do{
      printf("\nPlayer %d turn. Select a valid square number for symbol \'%c\'\n> ", player, (player==1) ? 'X' : 'O');
      scanf("%d", &ch);
      row = ch/3;
      col = ch%3;
    }while(ch < 0 || ch > 8 || board[row][col] == 'X' || board[row][col] == 'O');
    board[row][col] = (player == 1) ? 'X' : 'O';
    
    if(isAligned(board)){
      winner = player;
      break;
    }
    player = (player == 2) ? 1 : 2;
    system("clear");
  }
  printBoard(board);

  if(winner){
    printf("\n\033[1mWinner is Player %d\033[0m\n", player); 
  } else {
    printf("\nThe game is a draw\n");
  }
}
