class Solution {
    ListNode* mergeSort(ListNode* a, ListNode* b) {
        a = sortList(a);
        b = sortList(b);
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (a || b) {
            if (a == NULL) {
                tail->next = b;
                break;
            }
            else if (b == NULL) {
                tail->next = a;
                break;
            }
            else if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        return head->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        else if (head->next == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        // head -> ... -> prev -> slow -> ... -> ... -> fast
        prev->next = NULL;
        return mergeSort(head, slow);
    }
};