// Weekly Contest 321
// Link: https://leetcode.com/problems/find-the-pivot-integer/description/

// This is a classic question of PrefixSum and Suffix Sum
// Although I just calculated using leftSum and rightSum but the idea remains same

class Solution {
public:
    int pivotInteger(int n) 
    {
        int totalSum = (n * (n + 1) ) / 2 ; 
        
        int rightSum = totalSum ; // RightSum will always start from TotalSum
        int leftSum = 0 ; // LeftSum will always start from 0
        
        for(int i = 1 ; i <= n ; i++)
        {
            leftSum += i ; // We include i-th element into our LeftSum
            
            rightSum -= (i - 1) ; // We exclude (i - 1) element from rightSum or totalSum
            
            if(leftSum == rightSum) // If they still remain equal, it means we have found out our Pivot Integer
                return i ;
            
        }
        
        return -1 ; // Else we return -1
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
