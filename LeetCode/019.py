# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return None

        it = head
        er = head
        while n > 0:
            it = it.next
            n -= 1
        
        if not it:
            head = head.next
            return head

        while it.next:
            it = it.next
            er = er.next

        assert er.next
        er.next = er.next.next

        return head
