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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        if(nums.size()==1)
        {
            TreeNode*t=new TreeNode(nums[0]);
            return t;
        }
        int mid=nums.size()/2; //Mid element of array will be root
        TreeNode*root=new TreeNode(nums[mid]);
        vector<int>leftAns(nums.begin(),nums.begin()+mid);
        vector<int>rightAns(nums.begin()+mid+1,nums.end());
        root->left=sortedArrayToBST(leftAns); //left part of array before middle element will be left child
        root->right=sortedArrayToBST(rightAns); //right part of array before middle element will be right child
        return root;
    }
    //Time Complexity will be O(n)
    //We are making two new arrays,hence space complexity will be O(n)
};
