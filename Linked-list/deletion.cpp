#include <bits/stdc++.h>
using namespace std;

struct Node{
  public:
  int data;
  Node* next;

  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }
  Node(int data1){
    data=data1;
    next = nullptr;
  }
};

Node* Convert2LL(vector<int>& arr){
  Node* head =new Node(arr[0]);
  Node *mover = head;
  int n = arr.size();

  for (int i = 1; i < n;i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover = temp;
  }
  return head;
}

Node* DeleteHead(Node* head){
  if(head==NULL)
    return head;
  Node* temp=head;
  head=head->next;
  free(temp);
  return head;
}

Node* DeleteL(Node* head){
  if((head==NULL)||(head->next==NULL))
    return NULL;
  Node *temp = head;
  while(temp->next->next!=nullptr){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = nullptr;
  return head;
}



Node* removeK(Node* head,int k){
  if(head==NULL) return head;
  if(k==1)
    DeleteHead(head);
  Node *temp = head;
  Node* prev = NULL;
  int cnt=0;
  while(temp){
    cnt++;
    if(cnt==k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp = temp->next;
  }
  return head;
}


Node* DeleteValue(Node* head, int val){
  if(head==NULL) return head;
  if(head->data==val) DeleteHead(head);
  Node *temp = head;
  while(temp->next->data!=val){
    temp = temp->next;
  }
  Node *mover = temp->next;
  temp->next = temp->next->next;
  free(mover);
  return head;
}

void print(Node* head){
  Node* temp=head;
  while(temp){
    cout << temp->data<<" ";
    temp = temp->next;
  }

}



int main(){
  vector<int> arr={18,62,33,45,25};
  Node* head=Convert2LL(arr);
  // Node *deleteH = DeleteHead(head);
  // Node *deletelast = DeleteL(head);
  Node *deleteK = removeK(head, 3);
  Node *deleteval = DeleteValue(head, 45);
  print(head);

  return 0;
}