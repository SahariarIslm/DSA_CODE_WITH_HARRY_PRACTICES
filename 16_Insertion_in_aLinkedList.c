#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
// insertAtFirst Node
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    return ptr;
}
struct Node * insertAtIndex(struct Node *head,int data,int index){
    // new pointer/node in HEAP memory
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;//previous LinkedList

    int i = 0;
    // getting node location of the previous node of the indexed node
    while(i!=index-1){
        // get desired p Node
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node * insertAtEnd(struct Node *head,int data){
    // new pointer/node in HEAP memory
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;//previous LinkedList
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterANode(struct Node *head,struct Node *prevNode,int data){
    // new pointer/node in HEAP memory
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;//previous LinkedList
    ptr->data = data;
    // point new nodes address to previous nodes address
    ptr->next=prevNode->next;
    // point previous nodes address to new nodes address
    prevNode->next=ptr;

    return head;
}


int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    // Allocate  memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // link first and second nodes
    head->data =7;
    head->next = second;
    // link second and third nodes
    second->data =11;
    second->next = third;
    // link third and fourth nodes
    third->data =41;
    third->next = fourth;

    // terminate the list at fourth node
    fourth->data =68;
    fourth->next = NULL;
    printf("Linked List Before Insertion\n");
    linkedListTraversal(head);
    //head = insertAtFirst(head,56);
    //head = insertAtIndex(head,56,2);
    //head = insertAtEnd(head,77);
    head = insertAfterANode(head,third,45);
    printf("Linked List after Insertion\n");
    linkedListTraversal(head);
    return 0;
}
