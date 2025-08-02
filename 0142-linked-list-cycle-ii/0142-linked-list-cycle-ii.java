/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode curr = head;
        HashSet<ListNode> visited = new HashSet<>();
        while (curr != null) {
            if (visited.contains(curr)) 
                return curr;          // start of cycle
            visited.add(curr);
            curr = curr.next;
        }
        return null;
    }

}