// Weekly Contest 325
// Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/


// If the problem statement didn't have Circular Array concept, then the probelm would have been very straightforward
// But with the introduction of Ciruclar Array, we are faced with a tricky question
// The Straight distance will always be equal to (CurrIndex - startIndex)
// The Circular distance will be equal to (startIndex - 0) + (n - CurrIndex) [If startIndex appears before CurrIndex, else we swap their positions]

class Solution {
public:
    int closetTarget(vector<string>& words, string &target, int startIndex) 
    {
        int n = words.size() ;

        int ans = INT_MAX ; // As we need to find the Minimum Distance, so we declare Ans with INT_MAX

        for(int i = 0 ; i < n ; i++)
        {
            if(words[i] == target) // We update only if we have found our target string
            {
                int straight = abs(startIndex - i) ; // Staright Distance is pretty simple abs(i - startIndex)

                int circular = (startIndex - 0) + (n - i) ; // We assume StartIndex appears before CurrIndex and calculate accordingly

                if(startIndex >= i) // If StartIndex appears after CurrIndex
                    circular = (i - 0) + (n - startIndex) ; // We update our Circular distance by swapping their places

                ans = min(ans , min(straight , circular) ) ; 
            }
        }

        return ans == INT_MAX ? -1 : ans ; // Before returning we need to check if the array really contains our Target string or not
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
