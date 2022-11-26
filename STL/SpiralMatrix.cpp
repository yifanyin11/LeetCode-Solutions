class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i=0, j=0;
        int ii, jj;
        int dir=0;
        int count=0, total_count=0;
        const int m=matrix.size();
        const int n=matrix[0].size();
        const int length = m*n;
        // cout << m << ' ' << n << endl;
        bool passed=false, out=false;
        while(total_count<length){
            ii = i;
            jj = j;
            nextIdx(ii, jj, dir);
            out = (ii<0||ii>m-1||jj<0||jj>n-1);
            if (! out){
                passed = (matrix[ii][jj]==101);
            }
            if (out || passed){
                count++;
                dir = count%4;
            }
            switch (dir){
                case 0:
                    ans.push_back(matrix[i][j]);
                    matrix[i][j++]=101;
                    break;
                case 1:
                    ans.push_back(matrix[i][j]);
                    matrix[i++][j]=101;
                    break;
                case 2:
                    ans.push_back(matrix[i][j]);
                    matrix[i][j--]=101;
                    break;
                case 3:
                    ans.push_back(matrix[i][j]);
                    matrix[i--][j]=101;
                    break;
                default:
                    break;                                 
            }
            total_count++;
        }
        return ans;
    }
    
    void nextIdx(int &i, int &j, int dir){
        switch (dir){
            case 0:
                j++;
                break;
            case 1:
                i++;
                break;
            case 2:
                j--;
                break;
            case 3:
                i--;
                break;
            default:
                break;   
        }
    }
};
