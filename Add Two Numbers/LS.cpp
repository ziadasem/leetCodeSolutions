#include "LS.h"
#include<iostream>
using namespace std ;

ListNode* createList(int arr[], int n){
    createNode(ListNode,root, arr[0] )
    ListNode* temp = root ;
    for (int i =1; i < n ; i ++){
        createNode(ListNode,newNode, arr[i] )
        temp->next = newNode ;
        temp =  temp->next;
    }
    return root ;
}
void printLS(ListNode* root){
    ListNode* temp = root ;
    while(temp != NULL){
        cout<<temp->val<<", " ;
        temp = temp->next ;
    }
    cout<<endl;
}
