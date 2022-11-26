#include<iostream>
#include<vector>
#include<map>


using namespace std;

// // Using in-place change
// class Solution{
// private:
//     void backtracking(vector<int>& nums, vector<int>& set){
//         // end conditions
//         if (set.size()==n){
//             results.push_back(set);
//             return;
//         }
//         // loop through all child nodes
//         int store; // store the value is about to be put in the set
//         for (int i=0; i<nums.size(); ++i){
//             // process this node
//             store = nums[i];
//             set.push_back(store);
//             nums.erase((nums.begin()+i));
//             // recursion
//             backtracking(nums, set);
//             // backtracking
//             set.pop_back();
//             nums.insert((nums.begin()+i), store);
//         }
//     }
//     vector<vector<int>> results;
//     int n;

// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if (nums.empty()) return {{}};
//         n = nums.size();
//         vector<int> set;
//         backtracking(nums, set);
//         return results;
//     }
// };

// Using memo to indicate used elements
class Solution{
private:
    void backtracking(vector<int>& nums, vector<bool>& used){
        // end conditions
        if (set.size()==n){
            results.push_back(set);
            return;
        }
        // loop through all child nodes
        int store; // store the value is about to be put in the set
        for (int i=0; i<n; ++i){
            if (used[i]==true) continue;
            // process this node
            set.push_back(nums[i]);
            used[i]=true;
            // recursion
            backtracking(nums, used);
            // backtracking
            set.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> results;
    vector<int> set;
    int n;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};
        n = nums.size();
        vector<bool> used(n, false);
        backtracking(nums, used);
        return results;
    }
};

int main(int argc, char** argv){
    vector<int> nums{1, 2, 3, 4, 5};
    Solution solution;
    vector<vector<int>> results;
    results = solution.permute(nums);
    for (int i=0; i< results.size(); ++i){
        cout << "[";
        for (int j=0; j<results[0].size(); ++j){
            cout << results[i][j] << " ";
        }
        cout << "]" << endl;
    }
}