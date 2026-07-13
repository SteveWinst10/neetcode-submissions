class Solution {
    boolean rowDup(final char[] row){
        HashSet<Character> set = new HashSet<>();
        for (char c : row) {
            if(c != '.' && !set.add(c))
                return true;
        }
        return false;
    }
    boolean colDup(int colNum,final char[][] col){
        HashSet<Character> set = new HashSet<>();
        for(int i=0; i<9; ++i){
            if(col[i][colNum] != '.' && !set.add(col[i][colNum]))
                return true;
        }
        return false;
    }
    boolean boxDup(char[][] box){
        int row = 0;
        int col = 0;
        for(int m=0; m<3; ++m){
            for (int n=0; n<3; ++n){
                HashSet<Character> set = new HashSet<>();
                for(int i=row;i<row+3;++i){
                    for(int j=col; j<col+3;++j){
                        if(box[i][j] != '.' && !set.add(box[i][j]))
                            return true;
                    }
                }
                col +=3;
            }
            col=0;
            row += 3;
        }
        return false;
    }
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character> set = new HashSet<>();
        for(int i=0; i<9; ++i){
            if(rowDup(board[i])){
                return false;
            }
        }
        for(int i=0; i<9; ++i){
            if(colDup(i,board)){
                return false;
            }
        }
        if(boxDup(board)){
            return false;
        }
        return true;
    }
}
