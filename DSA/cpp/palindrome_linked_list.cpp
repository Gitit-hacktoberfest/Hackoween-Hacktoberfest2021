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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode *temp=head;
        int l=0;
        while(temp!=0) //to find the length of linked list
        {
            l++;
            temp=temp->next;
        }
        temp=head;
        int mid=(l-1)/2;
        int i=1;
        while(i<=mid)
        {
            temp=temp->next;
            i++;
        }
        ListNode*head2=temp->next;
        temp->next=NULL;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        ListNode* curr=head2;
        while(curr!=NULL) //reverse the second part of linked list
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head2=prev;
        temp=head;
        curr=head2;
        int flag=0;
        while(curr!=NULL && temp!=NULL) //to check if list is palindrome or not
        {
            if(curr->val!=temp->val)
            {
                flag=1;
                break;
            }
            curr=curr->next;
            temp=temp->next;
        }
        if(flag)
            return false;
        else
            return true;

    }
    //Time complexity will be O(n)
    //WE are not using any extra space hence space complexity will be O(1)
};
