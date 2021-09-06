#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size();
        int l = 0, r = nums1.size();
        
        while (l <= r) {
            int mX = (l + r + 1)/2;
            int mY = (nums1.size() + nums2.size() + 1)/2 - mX;
            
            int minX = (mX == 0) ? INT_MIN : nums1[mX-1];
            int minY = (mY == 0) ? INT_MIN : nums2[mY-1];
            
            int maxX = (mX == nums1.size()) ? INT_MAX : nums1[mX];
            int maxY = (mY == nums2.size()) ? INT_MAX : nums2[mY];
            
            if (minX <= maxY && minY <= maxX) {
                if ((nums1.size() + nums2.size()) % 2)
                    return (double)(max(minX, minY));
                else
                    return (double)(max(minX, minY) + min(maxX, maxY))/2;
            }
            else if (minX > maxY)
                r = mX-1;
            else
                l = mX;
        }
        
        return 0;
    }
};