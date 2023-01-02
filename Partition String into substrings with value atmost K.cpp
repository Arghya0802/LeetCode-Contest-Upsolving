// LeetCode Weekly contest 326
// Link: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

// On the outlook this problem looks like a Sliding Window problem
// But this can be solved using Greedy appraoch as we have to return the Minimum Number of Substrings

class Solution {
public:
    int minimumPartition(string &s , int k) 
    {
        int n = s.size() ;

        string ans = "" ; // Stores the SubString we have encountered till now
        int cnt = 0 ; // Stores the count of the SubStrings we have calculated till now

        for(int i = 0 ; i < n ; i++)
        {
            ans += s[i] ; 

            if(stol(ans) <= k) // We take the Integer Value and check if it's less than K or not
                continue ;

            else // else we have encountered a invalid substring
            {
                ans.pop_back() ; // We take the last inserted character from ans
              
                if(ans.size() > 0) // We increment cnt if and only if ans.size() is Non-Zero
                    cnt += 1 ;

                ans = "" ;

                int val = (int) (s[i] - '0') ;

                if(val <= k) // We check if the Current Integer Value is less than or equal to K or not 
                    ans += s[i] ; // If yes, we include it inside our ans string

                else // Otherwise, we can't divide the given string into contingious substrings so we return -1
                    return -1 ;

            }
        }

        if(ans.size() > 0) // If ans contains the entire S string, we handle the edge case seperately
            cnt += 1 ;

        return cnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [Our ans string can store the entire S string in worst case]
