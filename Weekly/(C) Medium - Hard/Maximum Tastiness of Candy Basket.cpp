// Weekly Contest 325
// Link: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/


// This question is exactly same as Aggressive Cows question [Binary Search on Answer]
// We need to think of Binary Search because we need to Maximise the Minimum Tastiness [Max of Min / Min of Max]
// To apply Binary Search, we need to sort the given Prices[] array
// While calculating the Minimum Tastiness, we will always pick the First Index Price because that's always minimum in the array
// We also don't need to check for all possible subsets, we can do it with (N - 1) comparisions because we sort the given array prices[]

class Solution {
private:

// isPossible() will tell us if we can get K elements out of the Price[] array such that their Min-Tastiness >= Mid [Atleast Mid is what we are loking for]
  
bool isPossible(int tasty , int k , vector<int> &prices)
{
    int n = prices.size() ;

    int cnt = 1 , last = 0 ;

    for(int i = 1 ; i < n ; i++)
    {
        if(prices[i] - prices[last] >= tasty)
        {
            cnt += 1 ; // Whenever we get one, we increment our counter by 1

            last = i ; // We update our Last Index by i
        }
    }

    return cnt >= k ? true : false ;
}

public:
    int maximumTastiness(vector<int>& price, int k) 
    {
        sort(price.begin() , price.end() ) ;

        long long int low  = 1 ;
        long long int high = 1000000000 ;

        int ans = 0 ;

        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;

            if(isPossible(mid , k , price) == true)
            {
                ans = mid ;

                low = mid + 1 ;
            }

            else
                high = mid - 1 ;
        }

        return ans ;
            
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
