import java.util.HashMap;

public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode temp = head;
        
        // Corrected the HashMap declaration to use Boolean and follow Java syntax
        HashMap<ListNode, Boolean> mpp = new HashMap<>();

        while (temp != null) {
            // Use containsKey to check if the node already exists in the HashMap
            if (mpp.containsKey(temp)) {
                return true;
            }
            // Add the current node to the HashMap
            mpp.put(temp, true);

            // Move to the next node in the list
            temp = temp.next;
        }
        return false;
    }
}
