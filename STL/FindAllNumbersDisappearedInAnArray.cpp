// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> result;
//         unordered_map<int, int> isNumIn;
//         for (int index=0; index<nums.size(); index++){
//             isNumIn[nums[index]]=1;
//         }
//         for (int index=0; index<nums.size(); index++){
//             if (!isNumIn.count(index+1)){
//                 result.push_back(index+1);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int index=0; index<nums.size(); index++){
            nums[abs(nums[index])-1]=-1*abs(nums[abs(nums[index])-1]);
        }
        for (int index=0; index<nums.size(); index++){
            if (nums[index]>0){
                result.push_back(index+1);
            }
        }
        return result;
    }
};
