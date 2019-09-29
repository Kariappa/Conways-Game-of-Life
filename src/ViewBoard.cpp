//Info on how to read and write to files is from cplusplus.com
#include "GameBoard.h"
#include "GameBoard.cpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include "ViewBoard.h"


using namespace std;

    ViewBoard::ViewBoard(string inputFile){
        GameBoard g(inputFile);
        ofstream outputFile;
        cout << "Enter a file name\n";
        string filename;
        cin >> filename;
        outputFile.open (filename);

    
        for (int x = 1; x < SIZE_GRID - 1; x++){ 
            cout << "\n";
            for (int y = 1; y < SIZE_GRID - 1; y++){
                if (g.cellAlive(x,y) == false) 
                    cout << ".";
            
                else {
                    cout << "O";
                    outputFile << x;
                    outputFile << " ";
                    outputFile << y;
                    outputFile << "\n";
                }
            }
        }
}




