/******************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for grid class.
 ** Date: 11/28/16
 *****************************************************/

#include "grid.hpp"
/****************************************************************************
 ** Function: Grid
 ** Description: Constructor initializes gridSize, creates 2d array of Space
 ** pointers and sets to NULL.
 ** Parameters: N/a.
 ** Pre-Conditions: Grid does not exist.
 ** Post-Conditions:  Grid exists.
 ** Return: N/a.
 ***************************************************************************/
Grid::Grid()
{
    gridSize = 10;
    // Initialize bool for whether Ezekiel will fight to false.
    Ezekiel = false;
    
    // Create grid.
    grid = new Space**[gridSize];
    for(int row = 0; row < gridSize; row++)
    {
        grid[row] = new Space*[gridSize];
    }
    
    // Set pointers to NULL.
    for(int row = 0; row < gridSize; row++)
    {
        for(int col = 0; col < gridSize; col++)
        {
            grid[row][col] = NULL;
        }
    }
}
/************************************************************
 ** Function: getSpace
 ** Description: Returns space for specified row and column.
 ** Parameters: Integer for row and column.
 ** Pre-Conditions: Space at row and column unknown.
 ** Post-Conditions:  Space at row and column known.
 ** Return: Space pointer to selected space.
 ************************************************************/
Space* Grid::getSpace(int r, int c)
{
    return grid[r][c];
}
/*************************************************************************
 ** Function: print
 ** Description: Loops through grid and prints out symbol for player if
 ** they occupy that space, or space symbol if space is unoccupied.
 ** Parameters: N/a.
 ** Pre-Conditions: Current grid not displayed.
 ** Post-Conditions: Current grid displayed.
 ** Return: N/a.
 ************************************************************************/
void Grid::print()
{
    for(int row = 0; row < gridSize; row++)
    {
        for(int col = 0; col < gridSize; col++)
        {
            if(grid[row][col])
            {
                if((row == playRow) && (col == playCol))
                {
                    // If player is in space, print out their symbol.
                    cout << grid[row][col]->getPlayer()->getChar() << " ";
                }
                else if(grid[row][col]->getPlayer() == NULL)
                {
                    // Else print out symbol for that space.
                    cout << grid[row][col]->getChar() << " ";
                }
                else
                    cout << "e ";  // used in testing to detect NULL spaces.
            }
            else
                cout << ". ";
        }
        cout << endl;
    }
}
/*********************************************************************************
 ** Function: setPlayer
 ** Description: Assigns player character to space at that row and column at
 ** start of game.
 ** Parameters: Two integers (row and column) and one fighter representing player.
 ** Pre-Conditions: Player not on board/in space.
 ** Post-Conditions:  Player set on the board/new space.
 ** Return: N/a.
 *********************************************************************************/
void Grid::setPlayer(int r, int c, Fighter* f)
{
    this->player = f;
    // Initialize player row and column.
    playRow = r;
    playCol = c;
    
    // Assign player to appropriate space.
    grid[r][c]->setPlayer(f);
    player->setLoc(grid[playRow][playCol]);
}
/***********************************************************
 ** Function: getPlayer
 ** Description: Returns pointer to the player character.
 ** Parameters: N/a.
 ** Pre-Conditions: Player character unknown.
 ** Post-Conditions: Player character known.
 ** Return: Fighter pointer to player's chosen character.
 *********************************************************/
Fighter* Grid::getPlayer()
{
    return player; 
}
/***********************************************************
 ** Function: makeMove
 ** Description: Based on user selection, makes move on the 
 ** board by first getting player, setting player value for
 ** current space to null, adjusting player row/column value,
 ** setting player in the next appropriate space, and then 
 ** calling turn function for the new space.
 ** Parameters: Integer value representing direction to move.
 ** Pre-Conditions: Player is in old space and turn function
 ** not yet called.
 ** Post-Conditions:  Old space player value set to NULL, 
 ** player location updated to new space, and turn called.
 ** Return: N/a.
 *********************************************************/
void Grid::makeMove(int m)
{
    int move  = m;
    
    if(move == 1) // Move up
    {
        if(playRow > 0)
        {
            grid[playRow][playCol]->getTop()->setPlayer(grid[playRow][playCol]->getPlayer());
            grid[playRow][playCol]->setPlayer(NULL);
            playRow = playRow-1;
            player->setLoc(grid[playRow][playCol]);
            grid[playRow][playCol]->turn();
        }
        else if(playRow == 0)
        {
            cout << "Forest filled with walkers, need to find another way." << endl;
        }
    }
    else if(move == 2) // Move down
    {
        if(playRow < 9)
        {
            grid[playRow][playCol]->getBottom()->setPlayer(grid[playRow][playCol]->getPlayer());
            grid[playRow][playCol]->setPlayer(NULL);
            playRow = playRow+1;
            player->setLoc(grid[playRow][playCol]);
            grid[playRow][playCol]->turn();
        }
        else if(playRow == 9)
        {
            cout << "Road filled with hundreds of wakers! Turn back!" << endl;
        }
    }
    else if(move == 3) // Move left
    {
        if(playCol > 0)
        {
            grid[playRow][playCol]->getLeft()->setPlayer(grid[playRow][playCol]->getPlayer());
            grid[playRow][playCol]->setPlayer(NULL);
            playCol = playCol-1;
            player->setLoc(grid[playRow][playCol]);
            grid[playRow][playCol]->turn();
        }
        else if(playCol == 0)
        {
            cout << "Wall of Saviors turn back!" << endl;
        }
    }
    else if(move == 4) // Move right
    {
        if(playCol < 9)
        {
            grid[playRow][playCol]->getRight()->setPlayer(grid[playRow][playCol]->getPlayer());
            grid[playRow][playCol]->setPlayer(NULL);
            playCol = playCol+1;
            player->setLoc(grid[playRow][playCol]);
            grid[playRow][playCol]->turn();
        }
        else if(playCol == 9)
        {
            cout << "Road barricaded by Saviors turn back" << endl;
        }
    }
    
}
/*********************************************************************
 ** Function: getGrid
 ** Description: Returns 2D array.
 ** Parameters: N/a.
 ** Pre-Conditions: 2d array not known.
 ** Post-Conditions:  2d array known.
 ** Return: 2d array grid.
 *********************************************************************/
Space*** Grid::getGrid()
{
    return grid;
}
/*********************************************************************
 ** Function: setBoard
 ** Description: Initializes array with 5 Doodlebugs and 100 Ants.
 ** Parameters: N/a.
 ** Pre-Conditions: Empty array.
 ** Post-Conditions:  2d array filled with 5 Doodelbugs and 100 Ants.
 ** Return: N/a.
 *********************************************************************/
void Grid::setBoard()
{
  
    // Initialize specific spaces on map for presentation of visual map.
    int random;
    random = 0;
    grid[0][9] = new Kingdom('K',grid, 0, 9);
    grid[1][8] = new Negansmen('.', grid, 1, 8);
    grid[2][1] = new Prison('P', grid, 2, 1);
    grid[2][2] = new Horde('#', grid, 2, 2);
    grid[2][7] = new Horde('.', grid, 2, 7);
    grid[3][5] = new Horde('#', grid, 3, 5);
    grid[3][6] = new Negansmen('.', grid, 3, 6);
    grid[5][5] = new Horde('^', grid, 5, 5);
    grid[4][5] = new Hilltop('H',grid, 4, 5);
    grid[6][5] = new Negansmen('.', grid, 6, 5);
    grid[7][5] = new Horde('.', grid, 7, 5);
    grid[8][5] = new Negansmen('.', grid, 8, 5);
    grid[9][5] = new Horde('.', grid, 9, 5);
    grid[7][0] = new Armory('A', grid, 6, 0);
    grid[7][1] = new Negansmen('.', grid, 6, 1);
    grid[6][2] = new Horde('.', grid, 6, 2);
    grid[6][3] = new Negansmen('.', grid, 6, 3);
    grid[5][4] = new Horde('.', grid, 6, 4);
    grid[9][4] = new Negansmen('.', grid, 9, 4);
    grid[9][3] = new Horde('.', grid, 9, 3);
    grid[8][2] = new Horde('.', grid, 7, 2);
    
    // Randomly initialize remaining spaces to mix of Horde and Negansmen.
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
        {
            if(grid[row][col])
            {
                //    cout << "taken" << row << " " << col << endl; // for testing.
            }
            else
            {
                if(random%2 == 0)
                {
                    grid[row][col] = new Horde('#', grid, row, col);
                    random++;
                }
                else if(random%2 == 1)
                {
                    grid[row][col] = new Negansmen('#',grid,row, col);
                    random++;
                }
            }
        }
    }
    
    // Set top space pointers.
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
        {
            if(row == 0)
            {
                grid[row][col]->setTop(grid[row][col]);
            }
            else
            {
                grid[row][col]->setTop(grid[row-1][col]);
            }
        }
    }
    // Set bottom space pointers.
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
        {
            if(row < 9)
            {
                grid[row][col]->setBottom(grid[row+1][col]);
            }
            else if(row == 9)
            {
                grid[row][col]->setBottom(grid[row][col]);
            }
        }
    }
    // Set left space pointers.
    for(int row = 0; row < 10; row ++)
    {
        for(int col = 0; col < 10; col++)
        {
            if(col > 0)
            {
                grid[row][col]->setLeft(grid[row][col-1]);
            }
            else if(col == 0)
            {
                grid[row][col]->setLeft(grid[row][col]);
            }
        }
    }
    // Set right space pointers.
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            grid[row][col]->setRight(grid[row][col+1]);

        }
        grid[row][9]->setRight(grid[row][9]);
    }
}
/*********************************************************************
 ** Function: ~Grid
 ** Description: Deconstructor deletes grid.
 ** Parameters: N/a.
 ** Pre-Conditions: 2d array exists.
 ** Post-Conditions:  2d array deleted.
 ** Return: N/a.
 *********************************************************************/
Grid::~Grid()
{
    // First free spaces pointed to.
    for(int row = 0; row < gridSize; row++)
    {
        for(int col = 0; col < gridSize; col++)
        {
            if(grid[row][col])
            {
                grid[row][col]->free();
            }
        }
    }
    // Second delete array of pointers.
    for(int row = 0; row < gridSize; row++)
    {
        delete grid[row];
    }
    delete [] grid;
}