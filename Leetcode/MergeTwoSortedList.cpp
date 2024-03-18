// These lines define the structure for a singly-linked list node named ListNode. It contains an integer value (val) and a pointer to the next node (next). It provides three constructors: one with no arguments, one with an integer argument (x), and one with both an integer argument and a pointer to the next node.

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

// This declares a class named Solution. Inside this class, there's a public member function mergeTwoLists that takes two pointers to ListNode objects (list1 and list2) representing the heads of two sorted linked list
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // This creates a dummy ListNode object named dummy with value 0, which will serve as the head of the merged list. A pointer tail is initialized to point to the dummy node. This pointer will be used to append nodes to the merged list.
        ListNode dummy(0);
        ListNode *tail = &dummy;

        // This loop continues as long as both list1 and list2 are not null. Within the loop:
        // It compares the values of the current nodes pointed by list1 and list2.
        // If the value of list1 is smaller, it appends list1 to the merged list pointed by tail, and advances list1 to the next node.
        // Otherwise, it appends list2 to the merged list, and advances list2.
        // After appending a node, tail is updated to point to the newly appended node.
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // After the loop, if list1 is not null, it means there are remaining nodes in list1 that are not yet appended to the merged list.
        // In this case, tail is linked to the remaining nodes of list1.
        // If list1 is null, it means all nodes of list1 have been merged. In this case, tail is linked to the remaining nodes of list2.
        if (list1)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};
