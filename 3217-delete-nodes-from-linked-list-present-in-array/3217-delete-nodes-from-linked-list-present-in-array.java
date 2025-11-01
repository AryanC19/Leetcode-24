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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> set=new HashSet<>();
        for(int i:nums) set.add(i);



        
        ListNode dummy=head;
        while(set.contains(dummy.val)) dummy=dummy.next;
        ListNode temp=dummy;
        ListNode prev=new ListNode(-1);
        prev.next=temp;
        while(temp!=null){

            while(temp!=null && set.contains(temp.val)){
                prev.next=temp.next;
                temp=temp.next;
            }
            prev=temp;
            if(temp!=null)
                temp=temp.next;
        }
        return dummy;

    }
}