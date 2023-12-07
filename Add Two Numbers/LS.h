#ifndef _LS_H
  #define _LS_H
  #define createNode(Type, X, VAL) Type* X =  new Type ; \
        X->val =  VAL; \
        X->next = NULL ;

  //Take list and returns ptr to first element

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* createList(int arr[], int n);
  void printLS(ListNode* root);

#endif // _LS_H


