#include <iostream>

const int GRIDSIZE = 40; // make it so user can determine board size


//This function loops through grid, stores a random value
//in randNum. If the value in randNum is divided and
// has no remainder, grid[i][j] will be initialized with
//either 1 or 0
void randGrid(bool grid[GRIDSIZE + 1][GRIDSIZE + 1])
{
    for(int i = 0; i < GRIDSIZE + 1; i++)
    {
        for(int j = 0; j < GRIDSIZE + 1; j++)
        {
            int randNum = rand() % 101;
            if((randNum % 5) == 0)
            {
                grid[i][j] = rand() % 2;
            }
            
        }
    }
}


//this function loops through the matrix and outputs
// " X " if the element being evaluated is == true
// it outputs " - " if the element being evaluated is == false
void displayGrid(bool grid[GRIDSIZE + 1][GRIDSIZE + 1])
{

    for(int i = 1; i < GRIDSIZE; i++)
    {
        for(int j = 1; j < GRIDSIZE; j++)
        {

            if(grid[i][j])
            {
                std::cout << " # ";
            }else
            {
                std::cout << "  ";
            }
            if(j == GRIDSIZE - 1)
            {
                std::cout << "\n";
            }
        }
    }
}


//this functions copies the contents of grid into grid2 in order to compare value
//withought messing up the intergrity of grid's values.
void cloneBoard(bool grid[GRIDSIZE + 1][GRIDSIZE + 1], bool grid2[GRIDSIZE + 1][GRIDSIZE + 1])  
{
    for(int i = 0; i < GRIDSIZE; i++)
    {
        for(int j = 0; j < GRIDSIZE; j++)
        {
            grid2[i][j] = grid[i][j];
        }
    }
}


//This function creates grid2, calls on cloneboard and checks the boolean
//state of grid in order to determine if the cell is alive or dead
void cellStatus(bool grid[GRIDSIZE + 1][GRIDSIZE + 1])
{
    bool grid2[GRIDSIZE + 1][GRIDSIZE + 1] = {}; // creating 2nd board
    cloneBoard(grid, grid2);
    

    for(int i = 1; i < GRIDSIZE; i++) //looping through matrix
    {
        for(int j = 1; j < GRIDSIZE; j++)
        {
            int cellAlive = 0;
            for(int x = -1; x <= 1; x++)
            {
                for(int y = -1; y <= 1; y++)
                {
        
                    if(grid[i+x][j+y]) //Determining if element is true /or false and incrementing alive if true
                    {
                        //usleep(100); 
                        ++cellAlive;
                    }

                }

            }

            cellAlive -= grid[i][j]; // subtracting cells that have been iterated over and are alse

                // cell dies due to under-population
            if((grid2[i][j] == 1) && (cellAlive < 2))
            {
                    grid[i][j] = 0;
            }

                // dies due to over-population
            else if((grid2[i][j] == 1) && (cellAlive > 3))
            {
                    grid[i][j] = 0;
            }

                // cell becomes alive due to reproduction
            else if((grid2[i][j] == 0) && (cellAlive == 3))
            {
                    grid[i][j] = 1;
            }
                // cell lives to next generation
            else
            {
                grid[i][j] = grid2[i][j];
            }
            
        }
    }

}