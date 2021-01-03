2) Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode *head1, *head2, *res, *curr;
        head1 = list1;
        head2 = list2;
        int len1 = 0, len2 = 0;
        while(head1 != NULL)
        {
            head1 = head1 -> next;
            len1++;
        }
        while(head2 != NULL)
        {
            head2 = head2 -> next;
            len2++;
        }
        head1 = list1, head2 = list2;
        if(len1 >= len2)
        {
            int currNode1, currNode2, carry = 0;
            while(head1 != NULL) 
            {
                currNode1 = head1 -> val;
                int sum;
                if(head2 != NULL)
                {
                    currNode2 = head2 -> val;
                    sum = currNode1 + currNode2 + carry;
                    head2 = head2 -> next;
                }
                else sum = currNode1 + carry;
                head1 -> val = sum % 10;
                carry = sum / 10;
                curr = head1;
                head1 = head1 -> next;
            }
            if(carry != 0) 
            {
                head1 = new ListNode(carry);
                curr -> next = head1;
                head1 -> next = NULL;
                head1 = head1 -> next;
            }
            res = list1;
        }
        else
        {
            int currNode1, currNode2, carry = 0;
            while(head2 != NULL) 
            {
                currNode2 = head2 -> val;
                int sum;
                if(head1 != NULL)
                {
                    currNode1 = head1 -> val;
                    sum = currNode1 + currNode2 + carry;
                    head1 = head1 -> next;
                }
                else sum = currNode2 + carry;
                head2 -> val = sum % 10;
                carry = sum / 10;
                curr = head2;
                head2 = head2 -> next;
            }
            if(carry != 0) 
            {
                head2 = new ListNode(carry);
                curr -> next = head2;
                head2 -> next = NULL;
            }
            res = list2;
        }
        return res;
    }
};