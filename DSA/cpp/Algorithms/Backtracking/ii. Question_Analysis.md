# Question 1: Modular Expression

Implement `pow(A, B) % C`.

In other words, given `A`, `B` and `C`,
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2
2^3 % 3 = 8 % 3 = 2

## Solution:

![](https://miro.medium.com/max/1050/1*gtsIphHYBo61bnHhN1bngw.png)

![](https://miro.medium.com/max/1050/1*RW6TrC9cFET5xqe16fQnBQ.png)

Time Complexity: O(log n)

![](https://miro.medium.com/max/764/1*3OdX_ord1Fvf5X4s15Xwrg.png)

# Question 2: Reverse Link List Recursion

Reverse a linked list using recursion.

## Example :
Given `1->2->3->4->5->NULL`,

return `5->4->3->2->1->NULL`.

## Solution:

![](https://miro.medium.com/max/1050/1*tkEbHav7IVF07hUlWdPumQ.png)

```cpp
ListNode* Solution::reverseList(ListNode* A) {\
    if(A->next==NULL){\
        return A;\
    }

    ListNode *rev=reverseList(A->next);\
    A->next->next=A;\
    A->next=NULL;\
    return rev;\
}
```
