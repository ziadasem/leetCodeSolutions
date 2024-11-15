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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode c = head ;
        if (c == null){
            return head;
        }
        ListNode c2 = c.next ;
        while(c != null && c2 != null){
            if (c.val != c2.val){
                c = c.next ;
                c2 = c2.next;
            }else{
                c.next = c2.next ;
                c2 = c2.next;
            }
        }
        return head ;
    }
}