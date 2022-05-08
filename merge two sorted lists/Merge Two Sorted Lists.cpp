ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

            ListNode * list1Temp;
            ListNode * list2Temp;
            ListNode* temp ;
            ListNode* head;

            if (list1 == NULL && list2 ==NULL){
                return NULL;
            }else if (list1 != NULL && list2 !=NULL){

                temp= new ListNode  ;
                head = temp  ;

                list1Temp = list1;
                list2Temp = list2;

                if (list1Temp->val > list2Temp->val ){
                        temp->val = list2Temp->val;
                        list2Temp = list2Temp->next ;
                }else{
                       temp->val = list1Temp->val;
                       list1Temp = list1Temp->next ;
                }

                while(list1Temp != NULL && list2Temp != NULL){
                    temp->next = new ListNode ;
                    temp= temp->next;

                    if (list1Temp-> val > list2Temp->val ){
                        temp->val = list2Temp->val;
                        list2Temp = list2Temp->next ;
                   }else{
                       temp->val = list1Temp->val;
                       list1Temp = list1Temp->next ;
                   }
                }

                if (list1Temp !=  NULL){
                    temp->next = list1Temp ;
                }

                if (list2Temp != NULL){
                    temp->next = list2Temp ;
                }

        }else{

            if (list1 !=  NULL){
                temp = list1 ;
            }

            if (list2 != NULL){
                temp = list2 ;
            }
            return temp;
        }
        return head;
    }
