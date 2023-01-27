// LeetCode Weekly Contest 311
// Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
// The following approach is pretty simple - we first use BFS() and store all the Nodes into ans[][] levelwise
// Again, we use another BFS() and this time we just put the values accordingly so that Node Values at Odd Levels are reversed

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

vector<vector<int>> bfs(TreeNode *root)  // This BFS() returns ans[][] such that Odd Level values are reversed
{
    vector<vector<int>> ans ;

    queue<TreeNode *> q ;

    q.push(root) ;

    int levels = 0 ;

    while(!q.empty() )
    {
        int size = q.size() ;

        vector<int> curr ;

        while(size--)
        {
            TreeNode *node = q.front() ;
            q.pop() ;
            
            curr.push_back(node -> val) ;

            if(node -> left != NULL)
                q.push(node -> left) ;

            if(node -> right != NULL)
                q.push(node -> right) ;
        }

        if(levels % 2 == 1)
            reverse(curr.begin() , curr.end() ) ;

        ans.push_back(curr) ;

        levels++ ;        
    }

    return ans ;
}

void bfs(TreeNode *root , vector<vector<int>> &ans) // This bfs() just puts the value in the place in the exisiting Tree Structure such that Odd Level values are reversed
{
    int cnt = 0 ;

    queue<TreeNode *> q ;

    q.push(root) ;

    while(!q.empty() ) 
    {
        int size = q.size() ;
        
        for(int i = 0 ; i < size ; i++)
        {
            TreeNode *node = q.front() ;
            q.pop() ;

            node -> val = ans[cnt][i] ;

            if(node -> left != NULL)
                q.push(node -> left) ;

            if(node -> right != NULL)
                q.push(node -> right) ;
        }

        cnt++ ;
    }

    return ;
}

public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(root -> left == NULL && root -> right == NULL)
            return root ;

        TreeNode *p = root ;
        vector<vector<int>> ans ;

        ans = bfs(p) ; // First BFS() returns a 2D vector with the Nodes levelwise

        bfs(p , ans) ; // Next BFS() is used to put the values in their places such that Nodes at Odd Level has their values reversed

        return root ;   
    }
};

// Time Complexity:  O(2 * N) [2 times BFS is run]
// Space Complexity: O(N) [We store all the Nodes into our ans[][] vector]

