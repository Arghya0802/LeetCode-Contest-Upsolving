// Weekly Contest 329
// Link: https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/

// The question is a pretty easy question - we need to sort the given 2D vector Score[][] on the basis of a Column Number K in the Descending Order
// We can use comparator class for this question as well
// But we can also use an extra 2D vector ans[][] and vector of pairs nums[] in which we will store the values of the scores[][] and sort them in descending order

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        int m = score.size() ;
        int n = score[0].size() ;

        vector<pair<int , int>> nums ; // Stores all the values of K-th Column along with their Row Numbers

        for(int row = 0 ; row < m ; row++)
        {
            int val = score[row][k] ;

            nums.push_back( {val , row}) ;
        }
        
        // We sort nums[] in Descending Order based on K-th Column Scores
        sort(nums.begin() , nums.end() ) ;
        reverse(nums.begin() , nums.end() ) ;
        
        vector<vector<int>> ans(m , vector<int> (n , 0) ) ; // Stores our Final Ans[][] vector
        int ind = 0 ;

        for(pair<int , int> &curr : nums)
        {
            int value = curr.first ;
            int rowNo = curr.second ;
          
            for(int col = 0 ; col < n ; col++) // We put all the vlaues of that particular rowNo into ans[ind] 
            {
                ans[ind][col] = score[rowNo][col] ;
            }
            
            ind++ ; // We increment ind by 1 as we move into the next row
        }

        return ans ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
