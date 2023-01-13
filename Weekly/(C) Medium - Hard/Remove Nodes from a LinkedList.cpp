// Weekly Contest 321
// Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

// The concept of the question is very simple, we need to remove all such Nodes to the right of any node, whose value is strictly greater than the Current Node
// To solve it in Linear Time Complexity, I have taken help of the hints
// Using hints, the question becomes a cakewalk
// We need to reverse the given linked-list, keep track of the maxVal we have encountered till now
// If any new node has a value greater than or equal to the maxVal, we include it in our New Linked-List [ because we are traversing in reversed manneer]
// Otherwise, we don't include it
// Lastly, we again reverse our new Linked-List and return the head

class Solution {
private:

// Reverses our Linked-List
ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head ;
    ListNode *prev = NULL ;
    ListNode *last = NULL ;

    while(curr != NULL)
    {
        last = prev ;
        prev = curr ;
        curr = curr -> next ;

        prev -> next = last ;
    }

    return prev ;
}

public:
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode *p = head ;
        ListNode *newHead = reverseList(p) ; // We store the Reversed LinkedList into newHead

        ListNode *dummy = new ListNode(-1) ; // We declare a Dummy Head

        dummy -> next = newHead ; // We include Dummy-Head into the Reversed Linked-List

        ListNode *tail = dummy ; // We use tail pointer to build our new Linked-List
        
        int maxVal = INT_MIN ; // Keeps track of the Max-Val we have encountered till now

        p = newHead ;

        while(p != NULL)
        {
            if(p -> val >= maxVal) // If our Current Node Value is greater than or equal to MaxVal, we have a Valid Node
            {
                maxVal = p -> val ;

                ListNode *node = new ListNode(p -> val) ; // We create a new node with Current Node Value
                
                // We include it into our LinkedList
              
                tail -> next = node ;

                tail = node ;
            }

            p = p -> next ;

        }

        ListNode *actualHead = reverseList(dummy -> next) ; // We again reverse our Linked-List

        return actualHead ; // We return the Head after reversing 
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
