class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //Loop errases elements until both vectors combined have 1 or 2 left
        while(nums1.size() + nums2.size() > 2) {
            
            if (nums1.size() > 0 && nums2.size() > 0) {
                (nums1.front() <= nums2.front()) ? nums1.erase(nums1.begin()) : nums2.erase(nums2.begin());
                if (nums1.size() == 0) nums2.pop_back();
                else if (nums2.size() == 0) nums1.pop_back();
                else (nums1.back() > nums2.back()) ? nums1.pop_back() : nums2.pop_back(); 
            } else if (nums1.size() == 0) {
                nums2.erase(nums2.begin());
                nums2.pop_back();
            } else {
                nums1.erase(nums1.begin());
                nums1.pop_back();
            }
            
        }
        
        double total = 0.0;
        
        if (nums1.size() > 1) {
            total = (accumulate(nums1.begin(),nums1.end(),0) / 2.0);
        } else if (nums2.size() > 1) {
            total = (accumulate(nums2.begin(),nums2.end(),0) / 2.0);
        } else if (nums1.size() == nums2.size()) {
            total = (nums1.front() + nums2.front()) / 2.0;
        } else if (nums1.size() == 1) {
            total = nums1.front();
        } else if (nums2.size() == 1) {
            total = nums2.front();
        }
    return total;
    }
};