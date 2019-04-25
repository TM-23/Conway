/*
    Author: Tino Mutano
    
*/

#include <iostream>
#include "logic.h"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main(){

    bool grid[GRIDSIZE + 1][GRIDSIZE + 1] = {};
    randGrid(grid);
   
    for(;;)
    {
        displayGrid(grid); //calling displayGrid function to output grid
        cellStatus(grid); //calling cellStatus to calculate cell state

        usleep(200000); //this suspends excution. Basically slows output
        system("clear");
    }



return 0;
}
