class Solution {
public:
bool isValid(vector<vector<char>> &b,int r,int c,char ch)
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
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                if(b[i][j]!='.' && !isValid(b,i,j,b[i][j]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
