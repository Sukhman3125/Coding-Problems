class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));

        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0], c = moves[i][1];
            char player = (i % 2 == 0) ? 'A' : 'B';
            board[r][c] = player;

            if (board[0][0] == player && board[0][1] == player && board[0][2] == player) return string(1, player);
            if (board[1][0] == player && board[1][1] == player && board[1][2] == player) return string(1, player);
            if (board[2][0] == player && board[2][1] == player && board[2][2] == player) return string(1, player);

            if (board[0][0] == player && board[1][0] == player && board[2][0] == player) return string(1, player);
            if (board[0][1] == player && board[1][1] == player && board[2][1] == player) return string(1, player);
            if (board[0][2] == player && board[1][2] == player && board[2][2] == player) return string(1, player);

            if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return string(1, player);
            if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return string(1, player);
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};