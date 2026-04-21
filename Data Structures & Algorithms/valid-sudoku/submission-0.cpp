class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        

        int n = 9;

        // for(int i=0;i<9;i++)
        // {
        //     for(int j = 0;j<9;j ++)
        //     {
        //         if(board[i][j]>='1' && board[i][j]<='9')
        //         {
        //             if(isValid(i,j,board))
        //         }
        //     }
        // }

        // validate ecah row 9 
        for(int i=0;i<9;i++)
        {
            set<int>s;
            for(int j =0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                if(s.find(board[i][j]-'0')!=s.end()) {
                   // cout<<" fail at i "<<i<<endl;
                    //cout<<" repeat " <<board[i][j]<<endl;
                    return false;
                }
                s.insert(board[i][j]-'0');
            }
        }
        // validate each col 9


        for(int j=0;j<9;j++)
        {
            set<int>s;
            for(int i =0;i<9;i++)
            {

                if(board[i][j]=='.') continue;
                if(s.find(board[i][j]-'0')!=s.end()) {
                    //cout<<" fail at "<<j<<endl;
                    return false;
                }
                s.insert(board[i][j]-'0');
            }
        }
        // validate each square
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                set<int>s;

                for(int x=0;x<3;x++)
                {
                    for(int y=0;y<3;y++)
                    {

                if(board[i+x][j+y]=='.') continue;
                         if(s.find(board[x+i][y+j]-'0')!=s.end()) {
                            cout<<" fail at "<<i<<" and "<<j<<endl;
                            return false;
                         }
                        s.insert(board[x+i][y+j]-'0');
                    }
                }
            }
        }

        return true;
    }
};
