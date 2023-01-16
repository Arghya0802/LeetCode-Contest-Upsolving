// Weekly Contest 328
// Link: https://leetcode.com/problems/increment-submatrices-by-one/description/

// This question is an extension of ScanLine Algorithm
// Instead of marking in a 1D array, we need to mark in a 2D vector
// Idea remains same, only difference is that we need to use mark every row from (startRow , endRow) using (startCol, endCol) 

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> ans(n , vector<int> (n , 0) ) ; // Stores our final ans[][] vector
        vector<vector<int>> prefix(n , vector<int> (n , 0) ) ; // Stores the 2D PrefixSum[][] vector

        for(vector<int> &query: queries)
        {
            int rStart = query[0] ;
            int cStart = query[1] ;
            
            int rEnd = query[2] ;
            int cEnd = query[3] ;
            
            for(int i = rStart ; i <= rEnd ; i++) // We iterate for every row from (startRow , endRow)
            {
                prefix[i][cStart] += 1 ; // We increment (ith Row, startCol) by 1 indicating the beginning of PrefixSum in this Row

                if(cEnd + 1 != n) // We need to ensure we don't travel outside the matrix
                    prefix[i][cEnd + 1] -= 1 ; // Similarly, we decrement (ith Row , endCol + 1) with -1 signifying the End of PrefixSum in this Row
            }

        }
        
        for(int row = 0 ; row < n ; row++)
        {
            int sum = 0 ; 

            for(int col = 0 ; col < n ; col++)
            {
                sum += prefix[row][col] ; // We add the Sum into our totalSum from prefixSum[row][col]
                
                ans[row][col] += sum ;  // We update the same cell with our totalSum
            }
        }
        
        return ans ;
    }
};

// Time Complexity:  O(Q * N) [Q is the number of Queries and N is the Number of Rows]
// Space Complexity: O(N ^ 2) [PrefixSum and Ans are both 2D vectors] 
