// Weekly Contest 322
// Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

// Classic question of Two-Pointers + Sorting
// Even if I didn't get the question right in one go, I looked at the Test Cases to get the intuition
// As we need to form a team with pairs such that the Sum of Skill of Every Team remains same, we go for Sorting
// And to make such divisions possible, we need to pair the Weakest Skilled Player with the Strongest Skilled Player

class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size() ;

        sort(skill.begin() , skill.end() ) ;

        long long int ans = 0 ;    

        int cnt = 0 ; // Helps us to keep a track of the number of pairs we have accquired
        int equal = 0 ; // Keeps track of the Sum of SkillSet we have accquired till now

        int low = 0 ;
        int high = n - 1 ;

        while(low < high) // Simple Two Pointer Algorithm
        {
            cnt++ ;

            if(cnt == 1) // If we are the very first team, we just need to update equal as the Sum of Skill[low] and Skill[high]
            {
                equal = skill[low] + skill[high] ;
            }

            else // If not, we need to check if such division is possible or not
            {
                int curr = skill[low] + skill[high] ;

                if(equal != curr) // If CurrentSum  is not equal to EqualSum, we return -1 indicating teams cannot be formed
                    return -1 ;
            }

            ans += (skill[low] * skill[high]) ; // Otherwise, we store the product into our ans vairable [chemistry]

            low += 1 ;
            high -= 1 ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
