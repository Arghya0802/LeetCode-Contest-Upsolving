// LeetCode Bi-Weekly Contest 94
// Link: https://leetcode.com/problems/reward-top-k-students/description/

// This is a classic question of Sorting + Comparator Function or Class
// Please remember that to sort vectors we only need static cmp() function from public scope

class Solution {
 
// We explicitly have to define cmp() function as Public and Static otherwise we will face compiler error
public:
static bool cmp(pair<int , int> &A , pair<int , int> &B)
{
    if(A.first > B.first) // Descending Order - Sort in Descending order on the basis of First Value
        return true ;

    else if(A.first == B.first) // If First Values are equal
    {
        if(A.second < B.second) // Ascending Order -  Sort in Ascending order on the basis of Second Value
            return true ;
    }

    return false ;
}

public:
    vector<int> topStudents(vector<string>& positive, vector<string>& negative, vector<string>& report, vector<int>& student, int k) 
    {
        unordered_map<string , int> good , bad ; // To Keep track of the Positive & Negative remarks

        for(string &word: positive)
            good[word] = 3 ; // Every Positive Remark weighs 3

        for(string &word : negative)
            bad[word] = -1 ; // Every Negative Remark weighs -1

        vector<pair<int , int>> result ; // Stores our pairs whom we will sort later on

        int n = report.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            string word = report[i] ;
            word += ' ' ; // In order to get the last word from report[i], we need to add space at the end

            int marks = 0 ; // Stores the Final Marks of i-th Student
            string wd = "" ;

            for(int ind = 0 ; ind < word.size() ; ind++)
            {
                char ch = word[ind] ;

                if(ch != ' ')
                    wd += ch ;

                else
                {
                    if(good.find(wd) != good.end() ) // If it's a good remark, we increment marks by +3 
                        marks += good[wd] ;

                    else if(bad.find(wd) != bad.end() ) // If it's a bad remark, we decrement marks by -1
                        marks += bad[wd] ;

                    wd = "" ;
                }
            }

            result.push_back( {marks , student[i]} ) ; // We push them inside our result[] vector
            
        }


        sort(result.begin() , result.end() , cmp) ; // We sort the vector using our Comparator Function
        
        vector<int> ans ;

        for(int i = 0 ; i < k ; i++) // We then insert the First K elements into our ans[] vector
            ans.push_back(result[i].second) ;

        return ans ;

    }
};

// Time Complexity:  O(N * Log N) [ Due to sorting ]
// Space Complexity: O(N) [ As we are storing all the pairs inside result[] array]
