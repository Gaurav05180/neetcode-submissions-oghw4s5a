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

    ListNode* reverseList(ListNode* node){
        ListNode* prev = nullptr;
        ListNode* curr = node;
        ListNode* front = node;

        while(curr){
            front = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* tail1 = head;
        ListNode* tail2 = reverseList(slow->next);
        slow -> next = nullptr;

        ListNode* tail = new ListNode(-1);

        while(tail2){
            tail -> next = tail1;
            tail = tail1;
            tail1 = tail1 -> next;

            tail -> next = tail2;
            tail = tail2;
            tail2 = tail2 -> next;

            tail -> next = nullptr;
        }

        tail -> next = tail1;

        return;
    }
};
