```c++
#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtTail(node *&head,int d){
    node *n=new node(d);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

void buildList(node *&head){
    int n;
    cin>>n;
    while(n!=-1){
        insertAtTail(head,n);
        cin>>n;
    }
}

node* merge(node*head1, node*head2){
    node* sorted=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            insertAtTail(sorted,head1->data);
            head1=head1->next;
        }else{
            insertAtTail(sorted,head2->data);
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        insertAtTail(sorted, head1->data);
        head1=head1->next;
    }
    while(head2!=NULL){
        insertAtTail(sorted, head2->data);
        head2=head2->next;
    }
    return sorted;
}


int main() {
    node *head1=NULL;
    buildList(head1);
    node*head2=NULL;
    buildList(head2);
    
    print(head1);
    cout<<endl;
    print(head2);
    
    node *mergedSorted=merge(head1,head2);
    cout<<endl;
    print(mergedSorted);
}
```
