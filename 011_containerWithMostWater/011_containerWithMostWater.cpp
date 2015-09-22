//
//  011_containerWithMostWater.cpp
//  LeetCode
//
//  Created by Oak on 9/22/15.
//

#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)

// O(n) solution
int maxArea(int* height, int heightSize) {
    int max = 0;
    int l = 0;
    int r = heightSize - 1;
    
    while (l < r) {
        int area = (r - l) * MIN(height[l], height[r]);
        if (area > max) max = area;
        
        if (height[l] > height[r]) r--;
        else l++;
    }
    
    return max;
}


// O(n^2) solution with recursive calls
void maxAreaHelper(int sofar[], int si, int rest[], int ri, int size, int *max) {
    if (si == 2) {
        int area = MIN(rest[sofar[0]], rest[sofar[1]]) * (sofar[1] - sofar[0]);
        if (area > *max) *max = area;
        return;
    } else if (ri == size) {
        return;
    } else {
        sofar[si++] = ri++;
        maxAreaHelper(sofar, si, rest, ri, size, max);
        si--;
        maxAreaHelper(sofar, si, rest, ri, size, max);
    }
}

int maxArea2(int* height, int heightSize) {
    int twoPt[2];
    int max = 0;
    maxAreaHelper(twoPt, 0, height, 0, heightSize, &max);
    
    return max;
}



