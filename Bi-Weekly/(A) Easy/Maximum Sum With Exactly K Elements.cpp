// Link:  https://leetcode.com/contest/biweekly-contest-103/problems/maximum-sum-with-exactly-k-elements/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        int n = nums.size() ;
        
        sort(nums.begin() , nums.end() ) ;
        
        int maxVal = nums.back() ;
        
        int maxSum = 0 ;
        
        for(int i = 0 ; i < k ; i++) 
        {
            maxSum += maxVal ;
            maxVal++ ;
        }
        
        return maxSum ;
    }
};

// Time Complexity:  O(N * LogN + K)
// Space Complexity: O(1)
