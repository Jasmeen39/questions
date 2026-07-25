/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //vector<ListNode*> pointers;
    bool hasCycle(ListNode *head) {
            //SC=O(N) and TC=O(n^2)
        // ListNode *current= head;
        // if(current == NULL) return false;
        // if(find(pointers.begin(),pointers.end(),current)!=pointers.end()) return true;
        // else pointers.push_back(current);
        // return hasCycle(current->next);
        // return false;
           //Tortoise and hare SC(1) TC(N)
           if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            //if(fast->next) fast->next;
            //else return false;
            if(fast==slow) return true;
        }
        return false;
    }
};