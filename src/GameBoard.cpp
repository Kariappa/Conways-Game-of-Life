//Info on how to read and write to files is from cplusplus.com
#include "GameBoard.h"
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;



GameBoard::GameBoard(string fileName){

    ifstream file(fileName);
    
	    if (file.is_open()) { 
            string line;
            while (getline(file,line)) {
		        stringstream read(line);
                string xCord;
                string yCord;
		        getline(read,xCord,' ');
		        getline(read,yCord,' ');
                this->Grid[stoi(xCord)][stoi(yCord)] = true;
            }
        } 
}


int GameBoard::countNeighbours(int xCord, int yCord){
    int neighbours = 0;
    for (int side = -1; side <= 1; side++) {
        for (int vert = -1; vert <= 1; vert++) {
            if (this->Grid[xCord + side][yCord + vert] == true)
                neighbours = neighbours + 1;
        }
    }
    return neighbours - 1;
}

 
void GameBoard::nextGeneration(){
    bool copyBoard[SIZE_GRID][SIZE_GRID] = {};  
       for(int xCord = 1; xCord < SIZE_GRID - 1; xCord++) {
           for(int yCord = 1; yCord < SIZE_GRID - 1; yCord++) {
               if (countNeighbours(xCord, yCord) < 2)
                    copyBoard[xCord][yCord] = false;
               else if (countNeighbours(xCord, yCord) > 3)
                    copyBoard[xCord][yCord] = false;
               else if (countNeighbours(xCord, yCord) == 3)
                    copyBoard[xCord][yCord] = true;
               else if (countNeighbours(xCord, yCord) == 2)
                    copyBoard[xCord][yCord] = true;
           }
       }
    for(int xCopy = 0; xCopy < SIZE_GRID; xCopy++) {
        for(int yCopy = 0; yCopy < SIZE_GRID; yCopy++) {
            this->Grid[xCopy][yCopy] = copyBoard[xCopy][yCopy];
            }
        }
}




bool GameBoard::cellAlive(int xCord, int yCord) {
    return this->Grid[xCord][yCord];
}

int main() {
    //Test
    //GameBoard test("text.txt.txt");
    //test.nextGeneration();
 

//To print
/*
    for (int x = 1; x < SIZE_GRID - 1; x++){ 
            cout << "\n";
        for (int y = 1; y < SIZE_GRID - 1; y++){
            if (test.cellAlive(x,y) == false) {
                cout << ".";
            }
            else {
                cout << "O";
            }
        }
        }

   //ViewBoard("text.txt.txt");
   */
    return 0;

}







