class Solution {
public:
    bool poss(vector<vector<char>> &b,int r,int c,char ch)
    {
        for(int i = 0; i < 9; i++) {

            if (b[i][c] == ch && i!=r)
            {
                return false;
            }

            if (b[r][i] == ch && i!=c)
            {
            
                return false;
            }

            
        }
        int row=3*(r/3);
        int col=3*(c/3);
        for(int i=row;i<=row+2;i++)
        {
            for(int j=col;j<=col+2;j++)
            {
                if(b[i][j]==ch && i!=r && j!=c)
                {
                    return false;
                }
            }
        }
        return true;        
    }
 
    bool solve(vector<vector<char>> &board)
    {
       for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(poss(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         bool ans=solve(board);
    }
};
