// LeetCode Weekly Contest 2544
// Link: https://leetcode.com/problems/alternating-digit-sum/

// The logic is very simple - we convert it into a string and iterate over the string 
// For even indices- we add the the value into our ans
// For odd indices- we subtract that value from our ans

class Solution {
public:
    int alternateDigitSum(int n) 
    {
        string s = to_string(n) ;
        
        int sum = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            int val = (int) (s[i] - '0') ;
            
            if(i % 2 == 0)
                sum += val ;
            
            else
                sum -= val ;
            
        }
        
        return sum ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
