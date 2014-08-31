
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode aux(0);
        aux.next = NULL;
        
        ListNode * iter;
        ListNode * prev;
		ListNode * next;
        ListNode * cur = head;
	
        while ( cur != NULL) {
			next = cur->next;	
		    prev = &aux;
            iter = aux.next;
            while(iter && cur->val > iter->val) {
                prev = iter;
                iter = iter->next;
            }
	
            prev->next = cur;
            cur->next = iter;
			
			cur = next;
		
        }  
    return aux.next;
    }
};

