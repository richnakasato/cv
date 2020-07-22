/*
plan: dfs with backtracking, cant reuse!
time: quadratic
space: quadratic
 */

class Solution {
public:
    bool canMove(const vector<vector<char>>& board, 
                 const vector<vector<bool>>& used,
                 const tuple<int,int>& pos) {
        auto row = get<0>(pos);
        auto col = get<1>(pos);
        if (row < 0 || size(board) <= row || col < 0 || size(board[0]) <= col) 
            return false;
        return !used[row][col];
    }
    bool dfs(const vector<vector<char>>& board,
             vector<vector<bool>>& used,
             const string& word,
             const tuple<int,int> pos,
             int idx,
             string& curr) {
        auto row = get<0>(pos);
        auto col = get<1>(pos);
        curr.push_back(board[row][col]);
        used[row][col] = true;
        if (curr == word) return true;
        if (size(word) <= idx+1) {
            used[row][col] = false;
            curr.pop_back();
            return false;
        }
        auto moves = vector<tuple<int,int>>{{row-1,col},{row+1,col},{row,col-1},{row,col+1}};
        for (auto move : moves) {
            auto next_row = get<0>(move);
            auto next_col = get<1>(move);
            if (canMove(board, used, move)
                && board[next_row][next_col] == word[idx+1]) {
                auto result = dfs(board, used, word, move, idx+1, curr);
                if (result) {
                    return true;
                }
            }
        }
        used[row][col] = false;
        curr.pop_back();
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (!size(word)) return true;
        if (!size(board) || !size(board[0])) return false;
        auto used = vector<vector<bool>>(size(board), vector<bool>(size(board[0])));
        for (auto row=0; row<size(board); ++row) {
            for (auto col=0; col<size(board[0]); ++col) {
                auto pos = tuple<int,int>{row,col};
                auto idx = 0;
                auto curr = string{};
                if (canMove(board, used, pos) 
                    && board[row][col] == word[idx]) {
                    auto result = dfs(board, used, word, pos, idx, curr);
                    if (result) return true;
                }
            }
        }
        return false;
    }
};
