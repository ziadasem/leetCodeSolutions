 /* Definition for singly-linked list. */
#include <stack>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       int size = 0 ;
        stack<int> nums ;
        
        //find length
        ListNode* temp = head; 
        while(temp != nullptr){
            temp = temp->next ;
            size ++ ;
        }
        
        temp = head; 
        for(int i = 0; i < size / 2 ; i++){
            nums.push(temp->val);
            temp = temp-> next ;
        }
        
        if (size %2 != 0){
            temp = temp-> next ;
        }
        
        while (!nums.empty()){
            int x = nums.top();
            nums.pop();
            if (x != temp->val){
                return false;
            }
            temp = temp->next;
        }
    
        
        return true;        
    }
};