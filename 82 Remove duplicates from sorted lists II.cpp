/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* c=head;
        ListNode* p=new ListNode(-1);
        ListNode* dummy=p;
        p->next=head;
        ListNode* n=head->next;
        while(n!=NULL){
            
            if(c->val==n->val){
                while(c->val==n->val){
                    ListNode* toFree=n;
                    n=n->next;
                    delete toFree;
                    if(n==NULL) break;
                }
                ListNode* freeStart=c;
                c=n;
                if(n!=NULL) n=n->next;
                delete freeStart;
                p->next=c;
            }
            else {
                p=c;
                c=n;
                n=n->next;
                
            }
        }
        return dummy->next;
    }
};
