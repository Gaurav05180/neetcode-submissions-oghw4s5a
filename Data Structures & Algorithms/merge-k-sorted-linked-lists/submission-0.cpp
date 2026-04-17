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

    ListNode* mergeList(ListNode* list1, ListNode* list2){
        ListNode* newList = new ListNode(0);
        ListNode* tail = newList;

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail -> next = new ListNode(list1->val);                
                list1 = list1 -> next;
            }
            else {
                tail -> next = new ListNode(list2->val);
                list2 = list2 -> next;
            }

            tail = tail -> next;            
        }

        while(list1){
            tail -> next = new ListNode(list1->val);

            tail = tail -> next;
            list1 = list1 -> next;
        }
        while(list2){
            tail -> next = new ListNode(list2->val);

            tail = tail -> next;
            list2 = list2 -> next;
        }

        return newList -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return {};

        ListNode* mergedList = lists[0];

        for(int i=1; i<lists.size(); i++){
            mergedList = mergeList(mergedList, lists[i]);
        }

        return mergedList;
    }
};
