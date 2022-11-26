// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         for (int i=0; i<nums.size(); i++)
//         {
//             for (int j=i; j<nums.size();j++)
//             {
//                 if (nums[i]+nums[j]==target)
//                 {
//                     result = {i, j};
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdx;
        for (int i=0;i<nums.size();i++)
        {
            if (numToIdx.count(target-nums[i]))
            {
                return {numToIdx[target-nums[i]], i};
            }
            numToIdx[nums[i]] = i;
        }
        
        throw;
    }
};
