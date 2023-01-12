// Weekly Contest 321

// Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

// This question has been asked multiple times in Amazon OA's
// The idea is very simple - Count how many characters are common between S & T
// If we deduct the Number of Common Characters from T's Length, we get our desired result

class Solution {
public:
    int appendCharacters(string &s, string &t) 
    {
        int n = s.size() ;

        int index = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == t[index]) // We increment index only when we have got any common character between S & T
                index += 1 ;
        }

        int charsToAppend = t.size() - index ; // The Number of Characters to append is equal to T's Length - our Index variable

        return charsToAppend ;
    }
};

// Time Complexity:  O(N)
// Space Complextiy: O(1)
