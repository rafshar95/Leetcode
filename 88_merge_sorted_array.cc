class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = nums1.size() - nums2.size() - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];
        int i = n, j = 0, pos = 0;
        for(int pos = 0, i = n, j = 0; pos < nums1.size(); pos++){
            if(i == nums1.size()){
                nums1[pos] = nums2[j];
                j++;
            }
            else if(j == nums2.size()){
                nums1[pos] = nums1[i];
                i++;
            }
            else if(i != nums1.size() && j != nums2.size()){
                if(nums1[i] < nums2[j]){
                    nums1[pos] = nums1[i];
                    i++;
                }
                else{
                    nums1[pos] = nums2[j];
                    j++;
                }
            }
        }

    }
};
