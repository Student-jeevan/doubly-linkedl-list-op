#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data , Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    
};
Node* arr2dll(vector<int> &ans){
    Node* head = new Node(ans[0]);
    Node* prev  = head;
    for(int i=1;i<ans.size();i++){
        Node* temp = new Node(ans[i],nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
//delete head of DDL
Node* DelHeadDLL(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    return head;
}
//delete tail of DDL
Node* DeltailDLL(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    return head;
}
//delete kth Node of ddl
Node* DelKNDLL(Node* head , int k){
    if(head==NULL || head->next == NULL) return NULL;
    int cnt =0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
         break;
        }
        temp = temp->next;
    }
    //delete head
    if(temp->back == NULL){
        head = DelHeadDLL(head);
        return head;
    }
    //delete tail
    if(temp->next == NULL){
        head = DeltailDLL(head);
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    return head;
}
//insertion in doubly linked list;
Node* insertNdll(Node* head , int val , int k){
    
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> ans  = {1,2,3,4,5};
    Node* head = arr2dll(ans);
    //head = DelHeadDLL(head);
    //print(head);
    //head = DeltailDLL(head);
    head = DelKNDLL(head , 5);
    print(head);
    return 0;
}