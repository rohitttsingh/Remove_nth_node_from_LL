#include<c++/v1/bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};

 ListNode* create(ListNode **head,int data){
    ListNode *newnode = new ListNode;
    newnode->val=data;
    newnode->next=*head;
    *head=newnode;
    
    return newnode;
}

void printingNode(ListNode * head){
    
        if(head==NULL) return;
        
        printingNode(head->next);
            cout<<head->val<<" ";
        
}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head==NULL) return NULL;
            ListNode *first = head;
            ListNode *second = head;
            
            for(int i=0;i<n;i++){
                first=first->next;
                
            }
                
                if(first==NULL){
                    ListNode *temp = head->next;
                    head->next = NULL;
                    free(head);
                    return temp;
                
            }
        while(first->next){
            first=first->next;
            second=second->next;
        }
        
        ListNode *temp = second->next;
        second->next = temp->next;
        free(temp);
        return head;

        }
    
    int main(){
        ListNode *head =NULL;
        int a[]={23,12,2,34};
        
        for(auto i:a){
            head = create(&head,i);
        }
        int n = 1;
        cout<<"[";
        printingNode(head);
        cout<<"]\n";
        ListNode * one = removeNthFromEnd(head,n);
        
        cout<<"[";
        printingNode(head);
        cout<<"]";
    }
