// Weekly Contest 327

// Link: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

// The question is very straightforward. We need to return the Absolute Difference between totalSum of array elements and Sum of Digits of array elements
// All the Array Elemnts are positive integers, thus we don't need to handle any edge case

class Solution {
private:

int sumOfDigits(int num) // Calculates the SumOfDigits() for any number 
{
    int ans = 0 ;

    while(num != 0)
    {
        int r = num % 10 ;

        ans += r ;

        num /= 10 ;
    }

    return ans ;
}

public:
    int differenceOfSum(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        int total = 0 ;    
        int digits = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            int val = nums[i] ;
            
            total += val ;

            if(val <= 9)
                digits += val ;

            else
                digits += sumOfDigits(val) ;
        }

        int ans = abs(total - digits) ;

        return ans ;
    }
};

// Time Complexity:  O(N * Log K) [Average element has K digits base 10]
// Space Complexity: O(1)
