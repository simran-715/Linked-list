#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;

  Node(int data1){
    data=data1;
    next=nullptr;

  }
  Node(int data1,Node* next1){
    data=data1;
    next=next1;

  }
};

// convert array to linkedlist

Node* Convert2LL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for (int i = 1; i<arr.size();i++){
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = mover->next;
  }
  return head;
}


// insert element at head

Node* InsertHead(Node* head,int el){
  
    Node *temp = new Node(el);

    if(head==NULL) {
      head = temp;
      return head;
    }

    temp->next = head;
    head = temp;
    return head;
}

// insert at last element

Node* InsertLast(Node* head,int el){
  Node* temp=new Node(el);
  if(head==NULL){
    head = temp;
    return head;
  }
  Node *mover = head;
  while(mover->next!=NULL){
    mover = mover->next;
  }
  mover->next = temp;
  return head;
}


// insert at kth element
Node* InsertK(Node* head, int el, int k){
  if(head==NULL){
  if(k==1) return new Node(el);

  }
  if(k==1) return new Node(el,head);
  int cnt = 0;
  Node *temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt==k-1){
      Node* newNode=new Node(el);
      newNode->next = temp->next;
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}

// print elements of linked list
void print(Node* head){
  Node* temp=head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main(){
  vector<int> arr = {12, 34, 23, 67, 23};
  Node* head=Convert2LL(arr);
  print(head);
  Node* insertHead = InsertHead(head, 45);
  print(insertHead);
  Node *insertLast = InsertLast(insertHead, 66);
  print(insertLast);
  Node *insertk = InsertK(insertLast, 88, 2);
  print(insertk);
  return 0;
}