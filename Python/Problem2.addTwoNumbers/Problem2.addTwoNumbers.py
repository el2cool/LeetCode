# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0;
        i = l1.val + l2.val
        if i > 9:
            carry = 1
        
        tmp = None
        result = ListNode(i%10, tmp)
        prev = result
        
        i = 0;
        l1 = l1.next
        l2 = l2.next
        
        while l1 is not None or l2 is not None:
            if l1 == None:
                i = l2.val + carry
                carry = 0
                if i > 9:
                    carry = 1
                
                tmp = ListNode(i%10)
                prev.next = tmp
                prev = tmp
                tmp = tmp.next
                l2 = l2.next
            elif l2 == None:
                i = l1.val + carry
                carry = 0
                if i > 9:
                    carry = 1
                
                tmp = ListNode(i%10)
                prev.next = tmp
                prev = tmp
                tmp = tmp.next
                l1 = l1.next
            else:
                i = l1.val + l2.val + carry
                carry = 0
                if i > 9:
                    carry = 1
                
                tmp = ListNode(i%10)
                prev.next = tmp
                prev = tmp
                tmp = tmp.next
                l1 = l1.next
                l2 = l2.next
                
            
        if carry == 1:
            tmp = ListNode(1)
            prev.next = tmp
        
        return result