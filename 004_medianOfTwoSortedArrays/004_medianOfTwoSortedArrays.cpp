//
//  004_medianOfTwoSortedArrays.cpp
//  LeetCode
//
//  Created by Oak on 9/21/15.
//

#include <stdio.h>
#include <vector>
#include "../LeetCode/Common.h"

using std::vector;

class Solution {
public:
    // Merge two arrays and find the median
    // If odd number of elements, return the middle one.
    // If even number of elements, return the average of the two middle elements.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        
        while ((it1 != nums1.end()) && (it2 != nums2.end())) {
            int val = 0;
            if (*it1 < *it2) {
                val = *it1;
                ++it1;
            } else {
                val = *it2;
                ++it2;
            }
            nums3.push_back(val);
        }
        
        while (it1 != nums1.end()) {
            nums3.push_back(*it1);
            ++it1;
        }
        
        while (it2 != nums2.end()) {
            nums3.push_back(*it2);
            ++it2;
        }
        
        double median = 0;
        
        if ((nums3.size() % 2) == 1) { // odd number of elements
            median = nums3[nums3.size() / 2];
        } else { // even number of elements
            median = (nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2]) / 2.0;
        }
        
        return median;
    }
    
    
    // Second method. Using binary search
    #define MIN(a, b) (a < b? a : b)
    
    double findMedianSortedArraysHelper(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findMedianSortedArraysHelper(B, n, A, m, k);
        }
        
        if (m == 0) return B[k-1];
        if (k == 1) return MIN(A[0], B[0]);
        
        int pa = MIN(k/2, m);
        int pb = k - pa;
        
        if (A[pa-1] <= B[pb-1]) {
            return findMedianSortedArraysHelper(A+pa, m-pa, B, n, k-pa);
        }
        
        return findMedianSortedArraysHelper(A, m, B+pb, n-pb, k-pb);
    }
    
    
    double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
        int total = m + n;
        
        if (total % 2 == 1) {
            //If the size of the sequence N is odd: N/2+1th element is median.
            return findMedianSortedArraysHelper(nums1, m, nums2, n, total/2 + 1);
        } else {
            //If the size of the sequence N is even: average of the N/2th and N/2+1th element is median.
            return (findMedianSortedArraysHelper(nums1, m, nums2, n, total/2)
                    + findMedianSortedArraysHelper(nums1, m, nums2, n, total/2 + 1)) / 2.0;
        }
        
    }
};