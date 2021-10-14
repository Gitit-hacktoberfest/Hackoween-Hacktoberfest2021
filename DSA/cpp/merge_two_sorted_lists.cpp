/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result=NULL;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        if(l1->val<=l2->val)  //l1's first value<l2's first value
        {
            result=l1;
            result->next=mergeTwoLists(l1->next,l2);
        }
        else    //l1's first value>l2's first value
        {
            result=l2;
            result->next=mergeTwoLists(l1,l2->next);
        }
        return result;
        //Time Complexity will be O(size of linked list 1+size of linked list 2) i.e o(n)
        //We are not using any extra space hence space complexity will be O(1)
    }
};
