#include<iostream>
#include<stdlib.h>

using namespace std;

int screenWidth = 10, screenHeight = 10;
int playerX = 1, playerY = 1;
char grid[10][10];
bool doRun = true;

class EnemyBase{
  public:
    int x;
    int y;
    EnemyBase(int positionX, int positionY){
      x = positionX;
      y = positionY;
    }
  
  void setEnemyOnGrid(int x, int y){
    grid[x][y] = '$';
  }

  void setMovementRoute(int squareHeight, int squareWidth){
    while(doRun == true){
      int counter = 0;
      if(counter == 0){
        if(this->y < squareHeight){
          this->y++;
        }else{
          counter = 1;
        }
      }
      if(counter == 1){
        if(this->x < squareWidth){
          this->x++;
        }
      }
    }
  }
};

EnemyBase enemy(0, 0);

void getGrid(int height, int width){
  for(int x = 0; x < height; x++){
    for(int y = 0; y < width; y++){ 
      grid[x][y] = '#'; 
    }
  }
}
void printGrid(int height, int width){
  for(int x = 0; x < height; x++){
    cout << "" << endl;
    for(int y = 0; y < width; y++){
      cout << grid[x][y];
    }
  }
}
void checkInput(){
  int userInput;
  cout << "\nPara qual direcao deseja andar:\n";
  cout << "1: Direita 2: Esquerda 3: Baixo 4: Cima" << endl;
  cin >> userInput;
  switch(userInput){
    case 1:
      playerY++;
      break;
    
    case 2:
      playerY--;
      break; 
    case 3:
      playerX++;
      break; 
    case 4:
      playerX--;
      break; 
    default:
      cout << "Valor Invalido" << endl;
  }
}
void runGame(){

  system("CLS");
  getGrid(screenWidth, screenHeight);
  grid[playerX][playerY] = '@';
  enemy.setMovementRoute(6, 6);
  enemy.setEnemyOnGrid(enemy.x, enemy.y);
  printGrid(screenWidth, screenHeight);
  checkInput();

}
int main(){
  while(doRun == true){
    runGame();
  }
