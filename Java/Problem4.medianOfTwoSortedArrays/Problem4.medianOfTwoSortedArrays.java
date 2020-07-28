class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        while (nums1.length + nums2.length > 2) {
            if (nums1.length > 0 && nums2.length > 0) {
                
                //Check left side of arrays
                if (nums1[0] < nums2[0]) {
                    nums1 = eraseElement(nums1, 0);
                } else {
                    nums2 = eraseElement(nums2,0);
                }
                
                //Check right side of arrays, need to check if either are of length 0
                if (nums1.length > 0 && nums2.length >0) {
                    if (nums2[nums2.length-1] > nums1[nums1.length-1]) {
                        nums2 = eraseElement(nums2, nums2.length-1);
                    } else {
                        nums1 = eraseElement(nums1, nums1.length-1);
                    }
                } else if (nums1.length == 0) {
                    nums2 = eraseElement(nums2, nums2.length-1);
                } else {
                    nums1 = eraseElement(nums1, nums1.length-1);
                }
                
            } else if (nums1.length == 0) {
                nums2 = eraseElement(nums2,0);
                nums2 = eraseElement(nums2, nums2.length-1);
            } else {
                nums1 = eraseElement(nums1, 0);
                nums1 = eraseElement(nums1, nums1.length-1);
            }
        }
        
        //There is either 1 or two elements at this point
        //If there is one, just return that element
        //If two, take the average of them
        
        double result;
        
        if (nums1.length + nums2.length == 1) {
            if (nums1.length == 1) {
                result = nums1[0];
            } else {
                result = nums2[0];
            }
        } else if (nums1.length == 2) {
            result = (nums1[0] + nums1[1]) / 2.0;
        } else if (nums2.length == 2) {
            result = (nums2[0] + nums2[1]) / 2.0;
        } else {
            result = (nums1[0] + nums2[0]) / 2.0;
        }
        
        
        return result;
    }
    
    public static int[] eraseElement(int[] nums, int index) {
        int[] result = new int[nums.length-1];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i != index) result[j++] = nums[i];
        }
        return result;
    }
}