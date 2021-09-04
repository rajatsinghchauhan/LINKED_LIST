#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
};
node *head=NULL;
void append (node **head,int x){

    node *temp,*ptr;
    if(*head==NULL){
        temp= new node();
        temp->data=x;
        temp->next=NULL;
        *head=temp;

    }
    else{

        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        ptr=new node();
        ptr->data=x;
        ptr->next=NULL;

        temp->next=ptr;
    }
}

void showdata(node *head){
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<"\n "<<temp->data<<endl;
        temp=temp->next;
    }
}
void firstpos(node **head,int x){
    node *ptr;
    ptr=new node();
    ptr->data=x;
    ptr->next=NULL;
    
    if(*head==NULL){
        *head=ptr;
    }
    else{
        ptr->next=*head;
        *head=ptr;
    }
}

void givenpos(node **head,int key,int x){
    node *temp,*ptr;
    ptr=new node();
    ptr->data=x;
    ptr->next=NULL;

    while(temp->next!=NULL){
        if(temp->data==key){
            ptr->next=temp->next;
            temp->next=ptr;
            break;
        }
        else
        temp=temp->next;
    }


}

void deletelist(node **head,int key){
    node *temp, *prev;
    temp=*head;
    if(temp==NULL)
    cout<<"\n list is empty ";
    else if(temp != NULL && temp->data==key){
        cout<<"\n head is the key ";
        cout<<"\n deleting "<<temp->data;
        *head=temp->next;
        delete temp;
    
        
    }
    else{
        while(temp!=NULL&&temp->data!=key){
            prev=temp;
            temp=temp->next;

        }
        if(temp==NULL){
            cout<<"\n element not found";
            return ;
        }
        prev->next=temp->next;
        cout<<"\n deleting     "<<temp->data;
        delete temp;
    }
} 

 void deletepos(node **head, int pos){

     node *temp,*ptr;
     temp=*head;
     if(pos==0){
         *head=temp->next;
         free(temp);

     }
     else{
         for(int i=0;i<pos-1 && temp->next!=NULL ;i++){
             temp=temp->next;
         }
         if(temp->next==NULL||temp==NULL){
             cout<<"\n position is greater then the list limit"<<endl;
             return;

         }
         ptr=temp->next;
         temp->next=ptr->next;
         cout<<"\n deleted element "<<ptr->data<<endl;
         free(ptr);

     }
 }

 int findlength(node *head){
     node *temp;
     temp=head;
     int count=0;
     while(temp!=NULL){
         count++;
         temp=temp->next;
     }
     return count;
 }

 bool search_ele_recur(node * head, int key){
     if(head ==NULL)
     return false;
     else if(head->data==key){
         cout<<"\n found the key at "<<head<<"  with value "<<head->data<<endl;
         return true;
     }
     else 
         return search_ele_recur(head->next, key);

 }
 
int main(){


int x;
 // apending few nodes to make hings working 
  append(&head,5);
  append(&head,8);
  append(&head,19);
  firstpos(&head,17);
  givenpos(&head,8,11);


  showdata(head);

  deletelist(&head,17);
  showdata(head);

  deletepos(&head,7);
  showdata(head);

  cout<<"\n length of the list is  "<<findlength(head)<<endl;

  cout<<search_ele_recur(head,19)<<endl;


    return 0;
}
