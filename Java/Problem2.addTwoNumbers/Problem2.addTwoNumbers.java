/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int i = l1.val + l2.val;
        if (i > 9) carry++;
        
        ListNode tmp = null;
        ListNode result = new ListNode(i%10, tmp);
        ListNode prev = result;
        
        i = 0;
        l1 = l1.next;
        l2 = l2.next;
        
        while(l1 != null || l2 != null) {
            if (l1 == null) {
                i = l2.val + carry;
                carry = 0;
                if (i > 9) carry++;
                tmp = new ListNode(i%10);
                prev.next = tmp;
                prev = tmp;
                tmp = tmp.next;
                i = 0;
                l2 = l2.next;
            }else if(l2 == null) {
                i = l1.val + carry;
                carry = 0;
                if (i > 9) carry++;
                tmp = new ListNode(i%10);
                prev.next = tmp;
                prev = tmp;
                tmp = tmp.next;
                i = 0;
                l1 = l1.next;
            }else {
                i = l1.val + l2.val + carry;
                carry = 0;
                if (i > 9) carry++;
                tmp = new ListNode(i%10);
                prev.next = tmp;
                prev = tmp;
                tmp = tmp.next;
                i = 0;
                l1 = l1.next;
                l2 = l2.next;
            }
        }
        
        if (carry == 1) {
            tmp = new ListNode(1);
            prev.next = tmp;
        }
        
        return result;
    }
}