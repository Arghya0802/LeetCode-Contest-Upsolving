// LeetCode Bi-Weekly 96
// Link: https://leetcode.com/problems/maximum-subsequence-score/description/

// We need to select a Subsequence of Size K from A and B such that the sum of elements of the subsequence of A and the Minimum Element of that same subsequence of B is maximum
// Initally, I thought about DP but later from discussion section came to know about the fact that it is solvable using Priority Queue + Sorting
// Our approach is very simple - we will create a vector of pairs nums[] and store elements in the form of {B[i] , A[i]}
// This is done because we will sort nums[] based on the value of B in Descending Order
// We will also maintain a MinHeap to remove the Minimum Element from our Subsequence of Size K whenever we exceed K
// We will maintain a Sum to track the SumTillNow and a ans variale to store the (Sum * minVal) we have encountered till now
// To maintain order of elements from A and B, we initally push it into a nums[] such that their relative ordering remains same
// We get te Minimum Element everytime from nums[i].first

class Solution {
public:
    long long maxScore(vector<int>& A , vector<int>& B , int k) 
    {
        int n = A.size() ;

        vector<pair<int , int>> nums ;

        for(int i = 0 ; i < n ; i++)
            nums.push_back( {B[i] , A[i]} ) ; // Order is (B[i] , A[i])
        
        // We sort nums[] in descending order
      
        sort(nums.begin() , nums.end() ) ;
        reverse(nums.begin() , nums.end() ) ;

        priority_queue<int , vector<int> , greater<int>> pq ; // We also declare a minHeap

        long long int sum = 0 ; // Calculates the CurrentSum of A 
        long long int ans = 0 ; // Stores the MaxSum we have encountered till now

        for(int i = 0 ; i < n ; i++)
        { 
            // We always include every element of A[] into our sum and push it into our minHeap
            sum += nums[i].second ;
            pq.push(nums[i].second) ;

            if(pq.size() > k) // If our size exceeds K
            {
                sum -= pq.top() ; // We deduct the Sum of the MinElemnt from A that is, pq.top()
                pq.pop() ; // We also pop it out from the queue
            }

            if(pq.size() == k) // If size of Priority Queue becomes exactly equal K
            {
                long long int minVal = nums[i].first ;
                long long int currSum = minVal * sum ; // We calculate the Sum 

                ans = max(ans , currSum) ; // And store the maximum into Sum
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(N * LogN)
// Space Complexity: O(N)
