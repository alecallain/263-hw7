#include<iostream>
#include<string>
#include<vector>

/**
 * This class simulates a backtracking 
 * method for a sudoku board
 *
 * @author Alec Allain
 * @version 4/15/18
 */   
class Back {
	
	public:

		/**
 		* This method implements a backtracking method
 		* to solve the sudoku board
 		*
 		* @param gameBoard[][] is the sudoku board
 		*/ 
		bool backTrack() {

			bool result;
		
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == 0) {
						for (int num = 1; num <=9; num++) {
							if (isLegal(i, j, num)) {
								board[i][j] = num;
								if (backTrack()) {
									result = true;
								}
								else {
									board[i][j] = 0;
								}
							}
						}
						result = false;
					}
				}
			}
			result = false;

			return result;
		}
		
		/**
 		* This method check to see if a number is
 		* in a certian row
 		*
 		* @param row is the row number
 		* @param num is the number we want to input
 		*/
		bool numberInRow(int row, int num) {
			for (int i = 0; i < 9; i++) {
				if (board[row][i] == num) {
					return true;
				}
				else {
					return false;
				}
			}
		}

		/**
 		* This method checks to see if a number is
 		* in a certian column
 		*
 		* @param col is the column number
 		* @param num is the number we want to input
 		*/ 
		bool numberInColumn (int col, int num) {
			for (int i = 0; i < 9; i++) {
				if (board[i][col] == num) {
					return true;
				}
				else {
					return false;
				}
			}
		}

		/**
 		* This method checks if a certian move
 		* is allowed
 		*
 		* @param 
 		*/
		bool isLegal(int row, int col, int num) {
			return !(numberInRow(row, num) || numberInColumn(col, num));
		}

	
		/**
 		* This method checks if game board is full
 		*
 		* @param board[][] is the sudoku board
 		*/
		bool boardFull(int board[int row][int col]) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (!board[i][j]) {
						return false;
					}
					else {
						return true;
					}
				}
			}
		}

		/**
 		* This method displays the game board
 		*
 		* @param board[][] is the sudoku board
 		*/
		void printBoard(int board[int row][int col]) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					std::cout << board[row][col] << " " << std::endl;
				}
			}
		}

	private:
		
		// instance variables
		int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                   		   { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                   		   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                   		   { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                   		   { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                   		   { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                   		   { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   		   { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                   		   { 0, 7, 0, 0, 0, 0, 0, 3, 0 }};

};

/**
 * Main method for class
 */
int main (int argc, char** argv) {
	
	board.backTrack();

	if (board.backTrack() == true && boardFull(board[9][9]) == true) {
		printBoard(board[9][9]);
	}
	else {
		std::cout << "There is no solution" << std::endl;
	}

}
