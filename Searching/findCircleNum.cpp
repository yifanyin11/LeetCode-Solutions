#include<iostream>
#include<vector>
#include<map>

using namespace std; 

class Solution{
private:
    void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited){
        visited[i]=true;
        for (int k=0; k<friends.size(); ++k){
            if (friends[i][k]==1 && !visited[k]){
                dfs(friends, k, visited);             
            }   
        }
    }

public:
    int findCircleNum(vector<vector<int>>& friends){
        if (friends.size()==0 || friends[0].size()==0) return 0;
        int n = friends.size();
        int count=0;
        vector<bool> visited(n, false);
        for (int i=0; i<friends.size(); ++i){
            if (!visited[i]){
                dfs(friends, i, visited);
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char**argv){
    vector<vector<int>> friends{{1,1,0},{1,1,0},{0,0,1}};
    Solution solution;
    int result = solution.findCircleNum(friends);
    cout << "Result: " << result << endl;
}