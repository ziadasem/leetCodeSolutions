
  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        std::set<void *> pointers ;
        while (temp != nullptr) {
            if (pointers.find(temp) != pointers.end()){ //found
                return true;
            }
            pointers.insert(temp);
            temp = temp->next ;
        }
        return false;
    }
};