class Solution {
public:
    int BinarySearch(vector<int>& nums1, vector<int>& nums2){ // This function returns index + 1 of the element (nums1.size() + nums2.size() + 1) / 2
        int greater_median = (nums1.size() + nums2.size() + 2) / 2;
        if(nums1.size() == 0)
            return -1;
        if(nums2.size() == 0)
            return greater_median;
        int l = 1, r = nums1.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(mid > greater_median || (greater_median + 1 - mid <= nums2.size() && nums1[mid - 1] > nums2[greater_median + 1 - mid - 1])) { // mid is too big.
                r = mid - 1;
            }
            else if(greater_median - mid > nums2.size() || (greater_median - mid > 0 && nums1[mid - 1] < nums2[greater_median - mid - 1])) { // mid is too small.
                l = mid + 1;
            }
            else if((mid == greater_median || nums1[mid - 1] >= nums2[greater_median - mid -1]) && (greater_median + 1 - mid > nums2.size() || nums1[mid - 1] <= nums2[greater_median + 1 - mid -1])){

                return mid;
            }
            else
                return -1;
        }
        return -1;

    }
    double DeriveOtherMedianAndReturn(vector<int>& nums1, vector<int>& nums2, int greater_median_index){
        const int kVerySmallNumber = -1000 * 1000 * 1000;
        const int kGreaterMedian = (nums1.size() + nums2.size() + 2) / 2;
        if((nums1.size() + nums2.size()) % 2 == 1)
            return nums1[greater_median_index - 1];
        int val1 = (greater_median_index > 1) ? nums1[greater_median_index - 2] : kVerySmallNumber;
        int val2 = (kGreaterMedian != greater_median_index ) ? nums2[kGreaterMedian - greater_median_index -1] : kVerySmallNumber;
        return 0.5 * (nums1[greater_median_index - 1] + std::max(val1, val2));
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int greater_median_index = BinarySearch(nums1, nums2);
        if(greater_median_index != -1){
            return DeriveOtherMedianAndReturn(nums1, nums2, greater_median_index);
        }
        else{
            greater_median_index = BinarySearch(nums2, nums1);
            return DeriveOtherMedianAndReturn(nums2, nums1, greater_median_index);
        }
    }
};
