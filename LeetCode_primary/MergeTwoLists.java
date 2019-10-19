/**
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode(-1);
        ListNode q = l3;
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                q.next = l1;
                l1 = l1.next;
            }
            else{
                q.next = l2;
                l2 = l2.next;
            }
            q = q.next;
        }
        if(l1 != null){
            q.next = l1;
        }
        if(l2 != null){
            q.next = l2;
        }
        return l3.next;
    }
}