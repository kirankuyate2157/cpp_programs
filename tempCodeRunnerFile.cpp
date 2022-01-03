#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template<class T>
class LinkedList{
    private:
    Node<T>* head;
    int length;

    public:
    LinkedList(){
        head=NULL;
        length=0;
    }

    int size(){
        return length;
    }

    void insertHead(T data){
        Node<T>* ptr=new Node<T>(data);

        if(head == NULL){
            head=ptr;
        }else{
            ptr->next=head;
            head=ptr;
        }
        length++;
    }   

    void insertEnd(T data){
        Node<T>* ptr=new Node<T>(data);

        if(head==NULL){
            head=ptr;
        }else{
            Node<T>* temp=head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=ptr;
        }

        length++;
    }

    void display(){
        Node<T>* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" , ";
            temp=temp->next;
        }
        cout<<"\n";
    }

    T deleteHead(){
        T deletedData=NULL;

        if(head==NULL){
            cout<<"Nothing to Delete..\n";
            return NULL;
        }else if(head->next==NULL){
            deletedData=head->data;
            delete(head);
            head=NULL;
        }else{
            Node<T>* temp=head;
            head=head->next;
            deletedData=temp->data;
            delete(temp);
        }
        //length is reduced by 1
        length--;
        return deletedData;
    }

    T deleteEnd(){
        T deletedData=NULL;

        if(head==NULL){
            cout<<"Nothing to Delete..\n";
            return NULL;
        }else if(head->next==NULL){
            deletedData=head->data;
            delete(head);
            head=NULL;
        }else{
            Node<T>* temp=head;
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            deletedData=temp->next->data;
            delete(temp->next);
            temp->next=NULL;
        }
        //length is reduced by 1
        length--;
        return deletedData;
    }
};

int main(){
    LinkedList<int> ll;

    ll.insertEnd(4);
    ll.insertEnd(5);
    ll.insertEnd(6);
    ll.insertEnd(8);
    ll.insertEnd(10);
    ll.display();
    cout<<ll.deleteEnd()<<"\n";
    ll.display();
    cout<<ll.deleteEnd()<<"\n";
    ll.display();

    return 0;
}