# The 8-Queens
- This one is a classic in computer science. The goal is to assign eight queens to eight positions on an 8x8 chessboard so that no queen, according to the rules of 
  normal chess play, can attack any other queen on the board. 
- In pseudocode, our strategy will be:
```cpp
Start in the leftmost columm
IF all queens are placed, RETURN true
FOR (every possible choice among the rows in this column)
 IF the queen can be placed safely there,
    Make that choice and then recursively try to place the rest of the queens
    IF recursion successful, RETURN true
    IF !successful, remove queen and try another row in this column
IF all rows have been tried and nothing worked, RETURN false to trigger backtracking
```
![image](https://user-images.githubusercontent.com/72455881/135706535-b40ca277-8962-4ecd-9e06-1c44c0455362.png)

```cpp
/*
 * This program implements a graphical search for a solution to the N
 * N queens problem, utilizing a recursive backtracking approach. See
 * comments for Solve function for more details on the algorithm.
 */
#include "chessGraphics.h" // routines to draw chessboard & queens
const int NUM_QUEENS = 8;
bool Solve(Grid<bool> &board, int col);
void PlaceQueen(Grid<bool> &board, int row, int col);
void RemoveQueen(Grid<bool> &board, int row, int col);
bool RowIsClear(Grid<bool> &board, int queenRow, int queenCol);
bool UpperDiagIsClear(Grid<bool> &board, int queenRow, int queenCol);
bool LowerDiagIsClear(Grid<bool> &board, int queenRow, int queenCol);
bool IsSafe(Grid<bool> &board, int row, int col);
void ClearBoard(Grid<bool> &board);
int main() {
  Grid<bool> board(NUM_QUEENS, NUM_QUEENS);
  InitGraphics();
  ClearBoard(board); // Set all board positions to false
  DrawChessboard(board.numRows()); // Draw empty chessboard
  Solve(board,0); // Attempt to solve the puzzle
  return 0;
}



/*
 * Function: Solve
 * ---------------
 * This function is the main entry in solving the N queens problem. It takes
 * the partially filled board and the column we are trying to place queen in.
 * It will return a boolean value which indicates whether or not we found a
 * successful arrangement starting from this configuration.
 *
 * Base case: if there are no more queens to place, we have succeeded!
 *
 * Otherwise, we find a safe row in this column, place a queen at (row,col)
 * recursively call Solve starting at the next column using this new board
 * configuration. If that Solve call fails, we remove that queen from (row,col)
 * and try again with the next safe row within the column. If we have tried all
 * rows in this column and haven't found a solution, we return false from this
 * invocation, which will force backtracking from this unsolvable configuration.
 *
 * The starting call to Solve has an empty board and places a queen in col 0:
 * Solve(board, 0);
 */
bool Solve(Grid<bool> &board, int col)
{
  if (col >= board.numCols()) return true; // base case
  for (int rowToTry = 0; rowToTry < board.numRows(); rowToTry++) {
    if (IsSafe(board, rowToTry, col)) {
      PlaceQueen(board, rowToTry, col); // try queen here
      if (Solve(board, col + 1)) return true; // recur to place rest
      RemoveQueen(board, rowToTry, col); // failed, remove, try again
    }
  }
  return false;
}



/*
 * Function: PlaceQueen
 * --------------------
 * Places a queen in (row,col) of the board by setting value in
 * grid to true and drawing a 'Q' in that square on the displayed chessboard.
 */
void PlaceQueen(Grid<bool> &board, int row, int col)
{
board(row, col) = true;
DrawLetterAtPosition('Q', row, col, "Black");
}
/*
 * Function: RemoveQueen
 * ---------------------
 * Removes a queen from (row,col) of the board by setting value in grid to
 * false and erasing the 'Q' from that square on the displayed chessboard.
 */
void RemoveQueen(Grid<bool> &board, int row, int col)
{
   board(row, col) = false;
   EraseLetterAtPosition(row, col);
}



/*
 * Function: IsSafe
 * ----------------
 * Given a partially filled board and location (row,col), returns boolean
 * which indicates whether that position is safe (i.e. not threatened by
 * another queen already on the board.)
 */
bool IsSafe(Grid<bool> &board, int row, int col){
   return (LowerDiagIsClear(board, row, col) &&
   RowIsClear(board, row, col) &&
   UpperDiagIsClear(board, row, col));
}


/*
 * Function: RowIsClear
 * --------------------
 * Given a partially filled board and location (queenRow, queenCol), checks
 * that there is no queen in the row queenRow.
 */
bool RowIsClear(Grid<bool> &board, int queenRow, int queenCol){
  for (int col = 0; col < queenCol; col++) {
  if (board(queenRow, col)) // there is already a queen in this row!
  return false;
  }
  return true;
}


/*
 * Function: UpperDiagIsClear
 * --------------------------
 * Given a partially filled board and location (queenRow, queenCol), checks
 * there is no queen along northwest diagonal through (queenRow, queenCol).
 */
bool UpperDiagIsClear(Grid<bool> &board, int queenRow, int queenCol){
  int row, col;
  for (row = queenRow, col = queenCol; col >= 0 && row < board.numRows();
   row++, col--) {
  if (board(row, col)) // there is already a queen along this diagonal!
  return false;
  }
  return true;
}



/*
 * Function: LowerDiagIsClear
 * --------------------------
 * Given a partially filled board and (queenRow, queenCol), checks that there
 * is no queen along southwest diagonal through (queenRow, queenCol).
 */
bool LowerDiagIsClear(Grid<bool> &board, int queenRow, int queenCol)
{
  int row, col;
  for (row = queenRow, col = queenCol; row >= 0 && col >= 0; row--, col--) {
  if (board(row, col)) // there is already a queen along this diagonal!
    return false;
  }
  return true;
}


/*
 * Function: ClearBoard
 * ---------------------
 * Simply initializes the board to be empty, ie no queen on any square.
 */
void ClearBoard(Grid<bool> &board)
{
  for (int row = 0; row < board.numRows(); row++)
  for (int col = 0; col < board.numCols(); col++)
  board(row, col) = false;
}
```
