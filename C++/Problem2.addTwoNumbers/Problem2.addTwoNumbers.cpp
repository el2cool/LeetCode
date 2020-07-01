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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //Completing this problem in one pass
        
        bool carry = false; //keep track of carry
        int i = l1->val + l2->val;
        
        
        if (i > 9) carry = true;
        
        l1 = l1->next;
        l2 = l2->next;
        
        //intial setup for ListNode, result to return later and prev/tmp to traverse
        ListNode* tmp = NULL;
        ListNode* result = new ListNode((i % 10), tmp);
        ListNode* prev = result;
        
        i = 0;
        
        
        
        while (l1 != NULL || l2 != NULL) { //three cases, one where both list are non null and two cases in which one is empty
            if (l1 == NULL) {
                i = l2->val + carry;
                carry = false;
                if (i > 9) carry = true;
                
                tmp = new ListNode(i % 10);
                l2 = l2->next;
                prev->next = tmp;
                prev = tmp;
                tmp = tmp->next;
                
            } else if (l2 == NULL) {
                i = l1->val + carry;
                carry = false;
                if (i > 9) carry = true;
                
                tmp = new ListNode(i % 10);
                l1 = l1->next;
                prev->next = tmp;
                prev = tmp;
                tmp = tmp->next;
            } else {
                i = l1->val + l2->val + carry;
                carry = false;
                if (i > 9) carry = true;
                
                tmp = new ListNode(i % 10);
                
                i = 0;
                l1 = l1->next;
                l2 = l2->next;
                prev->next = tmp;
                prev = tmp;
                tmp = tmp->next;
            }
        }
        
        
        if (carry) { //Make sure we didn't end with a carry, occurs with ListNodes of same size
            tmp = new ListNode(1);
            prev->next = tmp;
            prev = tmp;
            tmp = tmp->next;
        }
        
        return result;
    }
};