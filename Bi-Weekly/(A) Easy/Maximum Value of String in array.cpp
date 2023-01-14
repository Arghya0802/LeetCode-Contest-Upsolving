// Bi-Weekly Contest 93
// Link: https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/

// The question is very straightforward. We need to do what is directed in the question
// We have been given a vector of strings. We need to return it's Maximum Value
// Maximum Value is defined as:
// a) If the string is entire numeric, we use it's numeric value
// b) Otherwise we use it's length and return the Maximum Value possible

class Solution {
private:

int stringToInteger(string &s) // We can write our own atoi() function instead of using the C++ STL function
{
    int ans = 0 ;

    for(char ch : s)
    {
        int val = (int) (ch - '0') ;

        ans = (ans * 10) + val ;
    }

    return ans ;
}

bool isAllDigits(string &word) // isAllDigits() check if we have an entire Numeric String or not
{
    int n = word.size() ;

    for(int i = 0 ; i < n ; i++)
    {
        char ch = word[i] ;

        if(ch >= '0' && ch <= '9') // If we encounter digits, we simply continue
            continue ;

        return false ; // Otherwise we return false
    }

    return true ; // At the end, if we come out of the For Loop we return true
}
public:
    int maximumValue(vector<string>& strs) 
    {
        int ans = 0 ;

        for(string &word : strs)
        {
            int n = word.size() ;

            bool digitsCheck = isAllDigits(word) ;

            // if(digitsCheck == false)
            //     ans = max(ans , n) ;

            if(!digitsCheck) // If our string is not a Pure Numeric String
                ans = max(ans , n) ; // We use it's length to calculate the Maximum Value
                
            else // Otherwise we will use it's Integer Value
            {
                int val = stringToInteger(word) ;

                ans = max(ans , val) ;
            }

        }

        return ans ;    
    }
};

// Time Complexity:  O(N * K) [K is the average length of words present in strs[] ]
// Space Complexity: O(1)
