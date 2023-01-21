// LeetCode Bi-Weekly Contest 96
// Link: https://leetcode.com/contest/biweekly-contest-96/problems/minimum-operations-to-make-array-equal-ii/

// This is more of a observation kind of question rather than any standard algorithm
// We can make vector A[] equal to vector B[] only if the differences between the arrays can be equalized by K
// More formally, we need to check if the PositiveSum and NegativeSum of the differences between A[i] and B[i] are equal or not
// Even if they are equal, they need to be divisible by K otherwise we will always have some part left behind
// For any index i, A[i] - B[i] indicates how much more or less the value of A[i] is with respect to B[i]
// And since we can increment a value by K and simulatenously decrement another value from A by K, we keep track of the differences using PositiveSum and NegativeSum

class Solution {
public:
    long long minOperations(vector<int>& A , vector<int>& B , int k) 
    {
        int n = A.size() ;
        
        if(k == 0) // K can be 0, so we handle the EdgeCase seperately
        {
            if(A == B) // If A and B are already Equal then we return 0
                return 0 ;
            
            return -1 ; // Otherwise we always return -1 if K is 0
        }
        
        long long int positiveSum = 0 ; // Stores Sum of Positive Differences of A[i] - B[i]
        long long int negativeSum = 0 ; // Stores Sum of Negative Differences of A[i] - B[j]
        
        
        for(int i = 0 ; i < n ; i++)
        {
            int diff = A[i] - B[i] ; // We calculate the difference A[i] - B[i]
            
            if(diff >= 0) // If differnce is positive, we add it into PositiveSum
                positiveSum += diff ;
            
            else // Otherwise we add it into NegativeSum
                negativeSum += diff ;
        }
        
        negativeSum = abs(negativeSum) ; // We take the Absolte Value of NegativeSum to compare
        
        if(positiveSum != negativeSum) // If Positive and Negative Sums are not equal, then we cannot make A[] and B[] same
            return -1 ;
        
        if(positiveSum % k != 0) // Similarly, if PositiveSum is not divisible by K, we will have some remainder and they will not be same
            return -1 ;
        
        return positiveSum / k ; // Otherwise we can equalize A[] and B[] in PositiveSum / K operations
        
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
