#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
private:
    void backtracking(int n, int k, int start, vector<bool> used){
        // end condition
        if (set.size()==k){
            results.push_back(set);
            return;
        }
        for (int i=start; i<n; ++i){
            if (used[i]==true) continue;
            // process node
            used[i]=true;
            set.push_back(i);
            // recursion
            backtracking(n, k, i, used);
            // backtracking
            used[i]=false;
            set.pop_back();
        }
    }
    vector<int> set;
    vector<vector<int>> results;

public:
    vector<vector<int>> combine(int n, int k) {
        // check input
        if (n==0) return {{}};
        // initialization
        vector<bool> used(n, false);
        // recursion
        backtracking(n, k, 0, used);
        return results;
    }
};


int main(int argc, char** argv){
    int n=4, k=2;
    Solution solution;
    vector<vector<int>> results;
    results = solution.combine(n, k);
    for (int i=0; i< results.size(); ++i){
        cout << "[";
        for (int j=0; j<results[0].size(); ++j){
            cout << results[i][j] << " ";
        }
        cout << "]" << endl;
    }
}
