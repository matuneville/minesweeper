# Minesweeper 💣💥  
Starting from a group [practice project](https://github.com/matuneville/uba-algo1-TPs) for university in which we had to program the structural base of the minesweeper game, mainly coded with arrays (vectors) and matrices, 
I managed to program this simple graphical interface to play the game in the console, so that anyone can try it. Everithing is coded in C++ with CLion IDE. Group members are mentioned at the bottom.

## Game working
At first, you need to select the size of the square board and the amount of bombs for the game, which will determine the difficulty of the match.  

<img src="https://github.com/matuneville/minesweeper/blob/main/gamepics/ingame1.jpg"  width="370" height="370">  

Once the board is created, you have to select whether (1) you want to uncover a new square of the board, or (2) place a flag where you know or suspect there might be a bomb. Then the coordinates of the cell must be introduced (row and column).  
  
  
<img src="https://github.com/matuneville/minesweeper/blob/main/gamepics/ingame2.jpg"  width="370" height="370"> <img src="https://github.com/matuneville/minesweeper/blob/main/gamepics/ingame3.jpg"  width="370" height="370">   
  
  
And thus, you can win or lose the match.  
  
  
<img src="https://github.com/matuneville/minesweeper/blob/main/gamepics/won1.jpg"  width="370" height="370"> <img src="https://github.com/matuneville/minesweeper/blob/main/gamepics/lost1.jpg"  width="370" height="370">   

## Testing
The Test folder includes test suites made using the Google Test libraries. All cases of game situations has been put to the test to check the correctness of the algorithms. There is an extra algorithm that wasn't incorporated in the game, which recommends the player an empty cell to be played when a straight pattern of 1-2-1 is displayed on the board. 

## Authors
- [@matuneville](https://www.github.com/matuneville)
- [@Matteeo8](https://www.github.com/Matteeo8)
- [@ivan-22001](https://www.github.com/ivan-22001)
- [@ivox248](https://www.github.com/ivox248)
