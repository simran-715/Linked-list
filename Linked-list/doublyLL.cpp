#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* back;
  Node *next;

  Node(int data1,Node* back1,Node* next1){
    data = data1;
    back=back1;
    next = next1;
  }

  Node(int data1){
    data=data1;
    back=nullptr;
    next = nullptr;
  }
};

// array to doubly LL
Node* CreateDoublyLL(vector<int> & arr){
  if(arr.size()==0)
    return nullptr;
  Node* head= new Node(arr[0]);
  Node* mover=head;
  for (int i = 1; i < arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    temp->back = mover;
    mover = temp;
  }
  return head;
}

// print all elements of Doubly LL
void print(Node* head){
  
  Node* temp=head;
  while(temp!=nullptr){
    cout << temp->data<<" ";
    temp = temp->next;
  }
  cout << endl;
}





int main(){
  vector<int> arr={1,3,5,9,6};
  Node* head = CreateDoublyLL(arr);
  print(head);
}