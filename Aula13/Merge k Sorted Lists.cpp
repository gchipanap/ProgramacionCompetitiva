class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head=new ListNode(0);
        if (lists.size()==0){return NULL;}
        head->next = lists[0];
        ListNode *p;
        ListNode *q;
        for (int i=1;i<lists.size();i++){
            p = head;
            q = lists[i];
            while (q){
                if (!p->next){
                    p->next = q;
                    break;
                }
                if (p->next->val<q->val){
                    p=p->next;
                }else{
                    ListNode *l = p->next;
                    p->next = q;
                    q=q->next;
                    p->next->next = l;
                    p=p->next;
                }
            }
        }
        return head->next;
    }
};