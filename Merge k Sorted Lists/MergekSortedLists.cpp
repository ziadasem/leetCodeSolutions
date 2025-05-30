#include <iostream>
#include<vector>

// Definition for singly-linked list.
struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        //create the List
        ListNode* head          = nullptr;
        ListNode* lastNodePtr   = nullptr;
        //handle edge case of empty list
        if (lists.size() == 0)
        {
            return head;
        }

        //init the minimum value pointers list
        std::vector<ListNode*> minimumValueInListPointers(lists.size());
        for (int i{0}; i < minimumValueInListPointers.size(); ++i)
        {
            minimumValueInListPointers[i] = lists[i];
        }

        //prepare the loop
        bool stop = false;
        int minimumIndex = 0;
        int minimumValue;
        
        //execute the loop
        while(true)
        {
            minimumValue = INT_MAX;
            stop = true;
            for (int i{0}; i<minimumValueInListPointers.size(); ++i)
            {
                if (minimumValueInListPointers[i] != nullptr)
                {
                    stop = false;
                    if (minimumValueInListPointers[i]->val < minimumValue)
                    {
                        minimumValue = minimumValueInListPointers[i]->val;
                        minimumIndex = i;
                    }
                }
            }
            if (stop == true)
            {
                break;
            }
            //append the minimum value to the list
            ListNode* newNode = new ListNode(minimumValue);
            if (head == nullptr)
            {
                head = newNode;
                lastNodePtr = head;
            }else{
                lastNodePtr->next = newNode;
                lastNodePtr = lastNodePtr->next; //advance the pointer to point to the tail
            }
            //Move the pointer to its next value
            minimumValueInListPointers[minimumIndex] =  minimumValueInListPointers[minimumIndex]->next;

        }
    
        return head;
    }


};