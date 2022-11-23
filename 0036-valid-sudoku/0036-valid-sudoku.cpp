class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> col(9);
    set<char> row;
    vector<set<char>> subbox(9);
    int i,j,sub;
    for(i=0;i<9;++i){
        for(j=0;j<9;++j)
            if(isalnum(board[i][j])){
                sub = ((i/3)*3) + (j/3);
                if(row.count(board[i][j]) or col[j].count(board[i][j]) or subbox[sub].count(board[i][j])) return false;
                row.insert(board[i][j]);
                col[j].insert(board[i][j]);
                subbox[sub].insert(board[i][j]);
            }
        row.clear();
    }
    return true;
    }
};