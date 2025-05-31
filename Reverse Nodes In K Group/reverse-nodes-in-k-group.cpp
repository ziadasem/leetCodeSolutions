#include <stack>
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail        = nullptr;
        ListNode* iterator    = head;
        ListNode* lastPointerNonReversed;
        int       counter;
        std::stack<ListNode*> reversingStack;
        int length = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next)
        {
            length ++;
        }
        bool allNodesAreReversed = true;
        if (length % k != 0)
        {
            allNodesAreReversed = false;
        }
        while(1)
        {
            lastPointerNonReversed = iterator;
            for (counter = k; 
                counter > 0 && iterator != nullptr; 
                counter --, iterator = iterator->next
                )
            {
                reversingStack.push(iterator);
            }
            if (iterator != nullptr || (iterator == nullptr && allNodesAreReversed) )
            {
                //reverse
                while(!reversingStack.empty())
                {
                    ListNode* temp = reversingStack.top();
                    reversingStack.pop();
                    temp->next = nullptr;
                    if (tail == nullptr)
                    {
                        head = temp;
                        tail = head;
                    }else
                    {

                        tail->next = temp;
                        tail = tail->next;
                    }
                }
            }else
            {
                tail->next = lastPointerNonReversed;
            }
            if (iterator == nullptr)
            {
                break;
            }
        }
        return head;
    }
};