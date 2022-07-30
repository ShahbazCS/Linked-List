
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        vector<int>v;
        for(int i=0;i<k;i++){
            ListNode* head=lists[i];
            while(head){
                v.push_back(head->val);
                head=head->next;
            }
        }
        
        int n=v.size();
        sort(v.begin(),v.end());
        
    //dummy
        ListNode *temp=new ListNode();
        ListNode *head=temp;
        for(int i=0;i<n;i++){
            ListNode *temp1=new ListNode(v[i]); 
            temp->next=temp1;
            temp=temp1;
        }
        return head->next;
    }
};
