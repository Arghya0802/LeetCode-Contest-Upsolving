// Link: https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/

// This is a classic 2-Pointer Problem
// As A[] and B[] both are sorted in ascending order, 2-pointer can be easily applied
// If we get to the end of either A[] or B[] and we haven't yet returned, it simply means we don't have any common value between the arrays. So we return -1

class Solution {
public:
    int getCommon(vector<int>& A , vector<int>& B) 
    {
        int m = A.size() ;
        int n = B.size() ;
        
        int i = 0 ; // Iterates over A[] vector
        int j = 0 ; // Iterates over B[] vector
        
        while(i < m && j < n) // We traverse over both the arrays simulataneously using 2-Pointer Algorithm
        {
            if(A[i] == B[j]) // If we find any common element, we return that element as it's the Minimum Common Element between the arrays
                return A[i] ;
            
            else if(A[i] < B[j]) // Otherwise, if A[i] < B[j], we increment i by 1
                i++ ;
            
            else // Else we increment j by 1
                j++ ;
            
        }
        
        return -1 ; // At the end, we return -1 indicating we haven't found any Common Element
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
