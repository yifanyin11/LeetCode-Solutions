class Solution {
public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int k = m+n;
//         vector<int> temp(m+n);
//         int index1=0; 
//         int index2=0;
//         for (int index=0; index<k; index++){
//             if (index1>=m){
//                 temp[index] = nums2[index2++];
//             }
//             else if (index2>=n){
//                 temp[index] = nums1[index1++];
//             }
//             else if (nums1[index1]>nums2[index2]){
//                 temp[index] = nums2[index2++];
//             }
//             else{
//                 temp[index] = nums1[index1++];
//             }
//         }
//         for (int index=0; index<k; index++){
//             nums1[index] = temp[index];
//         }
//     }
// };

        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int k=m+n;
            int index1=m-1, index2=n-1;
            for (int index=k-1; index>=0; index--){
                if (index1<0){
                    nums1[index] = nums2[index2--];
                }
                else if (index2<0){
                    nums1[index] = nums1[index1--];
                }
                else if (nums1[index1]>nums2[index2]){
                    nums1[index] = nums1[index1--];
                }
                else{
                    nums1[index] = nums2[index2--];
                }
            }
    }
};
