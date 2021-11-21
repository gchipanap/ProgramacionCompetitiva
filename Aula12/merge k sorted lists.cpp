#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <= 0)
		return NULL;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : lists){
        ListNode *tmp = i;
        while(tmp != NULL){
            pq.push(tmp->val);
            tmp = tmp->next;
        }
    }
    
    if(pq.empty())
        return NULL;
    
    ListNode *aux2 = new ListNode(pq.top());
    pq.pop();
    ListNode *aux3 = aux2;
    while(!pq.empty()){
        ListNode *n = new ListNode(pq.top());
        aux3->next = n;
        pq.pop();
        aux3 = aux3->next;
    }
    
    aux3->next = NULL;
    
    return aux2;
    }
};
