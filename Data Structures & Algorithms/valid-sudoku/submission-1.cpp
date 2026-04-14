class Solution {
public:

    bool find(vector<vector<char>>& board, int i, int j){
        cout<<"find called ! ("<<i<<", "<<j<<")"<<endl;
        // row check
        for(int k=0; k<9; k++){
            if(k!=j && board[i][k]!='.' && board[i][k]==board[i][j]) return false;
        }
        
        // column check
        for(int k=0; k<9; k++){
            if(k!=i && board[k][j]!='.' && board[k][j]==board[i][j]) return false;
        }

        // 3*3 sub-boxes check
        int x = (i/3)*3, y = (j/3)*3;
        for(int k=x; k<x+3; k++){
            for(int l=y; l<y+3; l++){
                if(k==i && l==j) continue;
                if(board[k][l]!='.' && board[k][l]==board[i][j]) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && !find(board, i, j)) return false;
            }
        }

        return true;
    }
};
