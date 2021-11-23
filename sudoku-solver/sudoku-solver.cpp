class Solution {
public:
//     void solveSudoku(vector<vector<char>>& board) {
        
//     }
    
    bool isSafe(vector<vector<char>>& board ,int x, int y, int choice){
        for(int i=0;i<9;i++){
            if(board[i][y]==choice || board[x][i]==choice){
                return false;
            }
            if(board[3*(x/3)+i/3][3*(y/3)+i%3]==choice){  //3*3 block check
                return false;
            }
        }
        return true;
    }
    
    // bool solveSudoku(vector<vector<char>>& board)  { 
    //     for(int i=0;i<9;i++){
    //         for(int j=0;j<9;j++){
    //             if(board[i][j]==0){
    //                 for(int choice=1;choice<=9;choice++){
    //                     if(isSafe(board,i,j,choice)==true){
    //                         board[i][j]=choice;
    //                         if(solveSudoku(board)==true){
    //                             return true;
    //                         }
    //                         board[i][j]=0;
    //                     }
    //                 }
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    //Function to print grids of the Sudoku.
    // void printGrid (vector<vector<char>>& board) {
    //     for(int i=0;i<9;i++){
    //         for(int j=0;j<9;j++){
    //             cout<<board[i][j]<<" ";
    //         }
    //     }
    // }
    
    
    bool solve(vector<vector<char>>& board){
        // Looking in the whole board, trying to fill in the '.'
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                // If a '.' is found, we will try to fill it in
                if(board[i][j] == '.'){            
                    // Iterate over all the integers from 1 to 9 to get it filled 
                    // (trick used since it's actually a char ('1'+k to convert it to get the char)
                    for(int k=0;k<9;k++){
                        // If this is a valid placement 
                        if(isSafe(board, i, j, k+'1')){
                            // Place it and then try to solve further ...
                            board[i][j] = '1'+k;
                            if(solve(board))
                                // Try to solve futher, once everything is filled, this func will 
                                // return true (see at end) and this is when we will realize we have solved it!!
                                return true;
                            else
                                // If it is not solvable then we know that the choice we made(k) was 
                                // wrong, so we place a '.' back and then try to place some other 'k' here
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
 };