/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the
 board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will 
 be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col)
    {
        return row>=0 && row<board.size() && col>=0 && col<board[0].size() && board[row][col]=='O'  ;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return ;
       
        queue<pair<int,int> > q;
        
        for(int i=0;i<board.size();++i)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='B';
                    q.push({i,0});
            }
             if(board[i][board[0].size()-1]=='O')
            {
                board[i][board[0].size()-1]='B';
                    q.push({i,board[0].size()-1});
            }
        }
         for(int i=0;i<board[0].size();++i)
        {
            if(board[0][i]=='O')
            {
                board[0][i]='B';
                    q.push({0,i});
            }
             if(board[board.size()-1][i]=='O')
             {
                board[board.size()-1][i]='B';
                    q.push({board.size()-1,i});
            }
        }
      
        while(!q.empty())
        {
            pair<int, int> top=q.front();
            q.pop();
            
           
                static int index[]={-1,0,1,0,-1};
                
                for(int k=0;k<4;++k)
                    
                { 
                    if(isValid(board, top.first+index[k], top.second+index[k+1]))
                        {
                        
                      
                        
            board[top.first+index[k]][top.second+index[k+1]]='B';
        
         q.push({top.first+index[k], top.second+index[k+1]});
                    }
                }
                
        }
        
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='B')
                    board[i][j]='O';
            } 
        }
        
    }
};
