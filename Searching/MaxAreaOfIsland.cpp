#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> direction{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid);

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m=grid.size(), n=m? grid[0].size():0, local_area, area=0, x, y;
    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            if (grid[i][j]){
                grid[i][j]=0;
                local_area=1;
                stack<pair<int, int>> island;
                island.push({i,j});
                while(!island.empty()){
                    auto [cx, cy] = island.top();
                    island.pop();
                    for (int k=0; k<4; ++k){
                        x = cx+direction[k];
                        y = cy+direction[k+1];
                        if (x>=0 && x<m && y>=0 && y<n && grid[x][y]){
                            local_area+=1;
                            grid[x][y]=0;
                            island.push({x,y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}


int main(){
    vector<vector<int>> grid{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
    int area = maxAreaOfIsland(grid);
    cout << "Output is " area << endl;
}
