/**
 * \file GameBoard.h
 * \brief Module for respresenting the state of Conways Game of Life
 * \author Ali Kariapper
*/

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include <string>
#include "GameBoard.h"

#define SIZE_GRID   18



class GameBoard {
    private:
        bool Grid[SIZE_GRID][SIZE_GRID] = {};
        int countNeighbours(int xCord, int yCord);

    
    



    public:

    	/**
		 *  \brief Constructor for gameboard
		 *  \param fileName is the filename containing coordinates of live cells
		 */
        GameBoard(std::string fileName);
        
    	/**
		 *  \brief Updates the game board by updating the state of every cell
		 */
        void nextGeneration();

    	/**
		 *  \brief Returns whether or not a cell is alive
		 *  \param xCord The x coordinate of a cell
         *  \param yCord The y coordinate of a cell
         *  \return true if cell is alive and false if not
		 */
        bool cellAlive(int xCord, int yCord);

        
        





};







#endif
