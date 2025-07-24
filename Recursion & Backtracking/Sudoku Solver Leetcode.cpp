class Solution {
public:
     bool isValid(vector<vector<char>>& mat, int row, int col, char n ){
      for(int i = 0; i<9; i++){
          //Checking that the number exists in that column or not
          if(mat[i][col] == n){
              return false;
          }
          //Checking that the number exists in that row or not
          if(mat[row][i] == n){
              return false;
          }
          //Check that the number exists in any 3x3 matrix or not
          if(mat[3 * (row/3) + i/3][3 * (col/3) + i%3] == n){
              return false;
          }
      }
      return true;
    }
    bool solve(vector<vector<char>>& mat){
      //Traversing Throught the Matrix
      for(int i = 0; i<mat.size(); i++){
          for(int j = 0; j<mat[0].size(); j++){
              //We check for the empty spaces
              if(mat[i][j] == '.'){       //Empty Space Found
                  for(char k = '1'; k<='9'; k++){        //Passing the numbers that can be filled
                      if(isValid(mat, i, j, k)){   //Checking if the number satisfies the position
                          mat[i][j] = k;       //If yes then place the number in that position
                          
                          if(solve(mat) == true){   //Recursive Call for the next empty space in the space row
                            return true;  //If it satisfies then do not backtrack and return true
                        }
                        else{     //Otherwise backtrack to the prvious place that was empty
                            mat[i][j] = '.';   //Change it back to 0 and again search for the number that can be placed there
                        }
                      }
                      
                  }
                  return false;
              }
          }
      }
      return true;  //If no empty space i.e. all numbers are already placed in proper position so return true
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};