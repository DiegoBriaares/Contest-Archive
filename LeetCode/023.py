import heapq
import copy
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        H = [(node.val, i, node) for i, node in enumerate(lists) if node]
        heapq.heapify(H)
        N = len(H)

        if N == 0:
            return None
        
        head = ListNode()
        curr = head
        prev = None
        id = N + 1
        while H:
            '''
             Invariants are: 
              - curr is a fresh node
              - prev is None or the tail
            '''
            top = heapq.heappop(H)
            curr.val = top[0]
            curr.next = None

            if top[2].next:
                nxt = top[2].next
                heapq.heappush(H, (nxt.val, id, nxt))
                id += 1

            if prev:
                prev.next = curr
            prev = curr
            curr = ListNode()

        return head
