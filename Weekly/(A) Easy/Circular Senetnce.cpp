// Weekly Contest 322
// Link: https://leetcode.com/problems/circular-sentence/description/

// We can solve this problem by actually storing all the words and then comparing the Last Character of (i - 1)th word with First Character of i-th Word
// But I decided to do it without actually storing the words
// No need to handle any edge cases as the problem clearly states that we don't have Leading or Trailing Zeros and each character is seperated by a single space

class Solution {
public:
    bool isCircularSentence(string &sentence) 
    {
        char first = sentence[0] ; // We store the First Character seperately

        sentence += ' ' ; // To collect the last word from the sentence

        int n = sentence.size() ;

        char last = sentence[n - 2] ; // As we have added a space at the end, it means Last Character will techincally be at (n - 2)th Index

        int cnt = 0 ; // Number of Words we have encountered
        char curr = '$' ; // Stores Last Character of (i - 1)th word
        string wd = "" ; // To actually build and store every word

        for(int i = 0 ; i < n ; i++)
        {
            char ch = sentence[i] ;

            if(ch != ' ')
                wd += ch ;

            else
            {
                cnt++ ; // We increment cnt by 1 as we have encountered one complete word
                int len = wd.size() ;

                if( (cnt > 1) && (curr != wd[0] ) ) // We need to check from 2nd word till the Last Word so we put a extra check for cnt > 1
                    return false ;

                curr = wd[len - 1] ; // Curr is updated to store the Last Character of the Current Word

                wd = "" ;                
            }
        }
        
        return first == last ? true : false ; // Before returning we need to ensure that the First and Last Characters do match
    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
