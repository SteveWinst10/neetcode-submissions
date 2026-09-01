

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        while (l1 != nullptr)
        {
            const int l2_val = (l2 != nullptr) ? l2->val : 0;
            const int sum = l1->val+l2_val;
            if (sum <10)
            {
                l1->val = sum;
            }
            else
            {
                l1->val = sum%10;
                if (l1->next != nullptr) l1->next->val += sum/10;
                else
                {
                    ListNode* newNode = new ListNode{sum/10, nullptr};
                    l1->next = newNode;
                }
            }
            if (l1->next == nullptr && l2 != nullptr && l2->next != nullptr) {
                l1->next = new ListNode(0);
            }
            l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return head;


    }
};
