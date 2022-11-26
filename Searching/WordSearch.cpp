#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
private:
    int n, m, l;
    vector<int> directions{1, 0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, string word, int row, int col, int curidx, bool &found){
        // end conditions
        if (found==true || board[row][col]!=word[curidx]) return;
        if (curidx==l-1){
            found = true;
            return;
        }
        // process this node
        int ix, iy;
        char store = board[row][col];
        board[row][col]=' ';
        // loop through child nodes
        for (int i=0; i<4; ++i){
            ix = row+directions[i], iy=col+directions[i+1];
            // check indices
            if (ix>=0 && ix<n && iy>=0 && iy<m){
                // dfs
                dfs(board, word, ix, iy, curidx+1, found);
            }
        }
        // backtracking
        board[row][col]=store;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
            // check input
            if (board.empty()) return false;
            if (word.empty()) return true;
            // loop through possible roots
            n = board.size();
            m = board[0].size();
            l = word.size();
            bool result = false;
            for (int i=0; i<n; ++i){
                for (int j=0; j<m; ++j){
                    dfs(board, word, i, j, 0, result);
                    if (result==true) return true;
                }
            }
            return result;
        }
};


int main(int argc, char** argv){
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCESCFSADEEF";
    Solution solution;
    bool result = solution.exist(board, word);
    cout << result << endl;
}
