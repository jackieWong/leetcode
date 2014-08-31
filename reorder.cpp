#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        if(head->next == NULL) return;
        ListNode * slow, * fast;
        slow = head;
        fast = head;
        ListNode * iter = head;
        while(fast != NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newList = slow->next;
        slow->next = NULL;
        
        ListNode * backward = reverseList(newList);
		
        ListNode * list1 = head;
        ListNode * list2 = backward;
        while(list2){
            ListNode * tmp1 = list1->next;
            ListNode * tmp2 = list2->next;
            list2->next = list1->next;
            list1->next = list2;
            list1 = tmp1;
            list2 = tmp2;
        }
    }
    
    ListNode * reverseList(ListNode * head){
        if(head == NULL) return NULL;        if(head->next == NULL) return head;
        ListNode * prev = new ListNode(0);
        prev->next = NULL;
        ListNode * h = head;
        while(h != NULL){
            ListNode * next = h->next;
            h->next = prev->next;
            prev->next = h;
            h = next;
        }

        return prev->next;
    }
};

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	n1.next = &n2;
	n2.next = &n3;
	Solution sol;
	sol.reorderList(&n1);
	ListNode * p = &n1;
	while(p!= NULL){
		cout << p->val;
		p = p -> next;
	}
	return 0;
}
