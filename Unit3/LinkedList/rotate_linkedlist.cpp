algo1
/*
 Node*  rotate_linkedlist(Node * header)
 {
    Node * pre_ptr = header, * next_ptr = header -> next,* curr_ptr;
	while(next_ptr != nullptr)
	{
	  curr_ptr = next_ptr -> next;
	  next_ptr -> next = pre_ptr;
	  pre_ptr = next_ptr;
	  next_ptr = curr_ptr;
	}
	header -> next = nullptr;
 }
 */
make the singly Linkedlist rotate


algo2
/*
public ListNode reverse(ListNode head) {
    ListNode prev = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
*/