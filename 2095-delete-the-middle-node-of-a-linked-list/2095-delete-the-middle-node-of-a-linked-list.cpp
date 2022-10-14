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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowest = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slowest = slow;
            slow= slow->next;
            fast = fast->next->next;
        }

        if(fast->val == slow->val && slow->next == NULL)
        {
            head = NULL;
        }

        else
        {
            if(fast->next != NULL)
            {
                slowest = slow;
                slow = slow->next;
            }

            if(slow->next == NULL)
            {
                slowest->next = NULL;
            }
            else
            {
                slowest->next = slow->next;
                slow->next = NULL;
            }
        }
        return head;
    }
};