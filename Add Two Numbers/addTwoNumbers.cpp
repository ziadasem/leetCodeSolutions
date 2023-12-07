#include <iostream>
#include "LS.h"
using namespace std ;

#define retrunZeroIfNull(X) (X == NULL ? 0 : X->val)
#define moveAndSkipNull(X) (X == NULL ? NULL : X->next)

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* root  = new ListNode;
     int val = l1->val+ l2->val ;
     root->val = val%10 ;
     l1 = l1->next ;   l2 = l2->next ;
     ListNode* temp = root ;
     int carry = val /10 ;
     while(l1 != NULL || l2!= NULL){
        int compeleteVal = retrunZeroIfNull(l1) + retrunZeroIfNull(l2) + carry;

        int val = compeleteVal% 10 ;
        carry = compeleteVal/ 10 ;
        createNode(ListNode, newNode, val)
        temp->next = newNode ;
        temp = temp->next ;
        l1 = moveAndSkipNull(l1); l2 = moveAndSkipNull(l2);

     }
     if (carry != 0){
        createNode(ListNode, newNode, carry)
        temp->next = newNode ;
     }
     return root ;
}
int main(){

    int l1V[3] = {9,9,9};
    int l2V[3] = {9,0,9};

    int l11V[3] = {9,9,9};
    int l21V[2] = {1,2};

    int l12V[1] = {9};
    int l22V[3] = {1,2,3};

    int l13V[3] = {0,0,0};
    int l23V[1] = {0};

    int l14V[3] = {0,1,2};
    int l24V[3] = {3,1,0};

    int l15V[5] = {4,4,4,4,4};
    int l25V[3] = {2,2,1};

    int l16V[3] = {1,2,3};
    int l26V[1] = {0};

    int l18V[1] = {0};
    int l28V[3] = {1,2,3};

    int l17V[1] = {1};
    int l27V[2] = {1,9};

    ListNode* l1 = createList(l11V, 3);
    ListNode* l2 = createList(l21V, 2);

    ListNode* result = addTwoNumbers(l1, l2);
    printLS(result);
}
