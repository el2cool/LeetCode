class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        while (len(nums1) + len(nums2) > 2):
            if (len(nums1) > 0 and len(nums2) > 0):
                if (nums1[0] < nums2[0]):
                    nums1.pop(0)
                else:
                    nums2.pop(0)
                
                if (len(nums1) > 0 and len(nums2) > 0):
                    if (nums2[-1] > nums1[-1]):
                        nums2.pop(-1)
                    else:
                        nums1.pop(-1)
                elif (len(nums1) == 0):
                    nums2.pop(-1)
                else:
                    nums1.pop(-1)
            elif (len(nums1) == 0):
                nums2.pop(0)
                nums2.pop(-1)
            else:
                nums1.pop(0)
                nums1.pop(-1)
                
        if (len(nums1) + len(nums2) == 1):
            if (len(nums1) == 1):
                result = nums1[0]
            else:
                result = nums2[0]
        elif (len(nums1) == 2):
            result = (nums1[0] + nums1[1]) / 2.0
        elif (len(nums2) == 2):
            result = (nums2[0] + nums2[1]) / 2.0
        else:
            result = (nums1[0] + nums2[0]) / 2.0
        
        return result