#include <stack>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
       std::stack<ListNode*> reversedList ;
        int listSize = 0 ;
        ListNode* temp = head ;
        while(temp != nullptr){
            temp = temp->next ;
            listSize ++ ;
        }

        temp = head ;
        if (listSize %2 != 0){
            listSize ++ ;
        }
        int halfSize = listSize/2 ;

        for (int i = 0 ; i < listSize && temp != nullptr ; i++ ){
            if (i ==halfSize -1 ){ //cut the middle
                 ListNode* nex = temp->next ;
                 temp->next = nullptr ;
                 temp = nex ;
            }else if (i  >=halfSize ){ //cut the middle
                 ListNode* nex = temp->next ;
                 temp->next = nullptr ;
                 reversedList.push(temp);
                 temp = nex ;
            }else{
                temp = temp->next ;
            }
        }
        
        temp = head ;
        while (!reversedList.empty()){
            ListNode* lastNode = reversedList.top();

            ListNode* newTemp =  temp->next ;
            reversedList.pop();
            
            lastNode->next = temp->next ;
            temp->next = lastNode ;
            temp = newTemp ;
        }
    }
};