class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero_index=0;
        for (int index=0; index<nums.size(); index++){
            if (nums[index]!=0){
                nums[nonzero_index++]=nums[index];
            }
        }
        for (int index=nonzero_index; index<nums.size(); index++){
            nums[index]=0;
        }
    }
};
