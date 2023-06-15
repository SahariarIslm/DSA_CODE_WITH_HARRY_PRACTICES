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
// Case 1: delete first element from the linked list(O(1))
struct Node * deleteFirst(struct Node* head){
    struct Node * ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
// Case 2: delete element at a given index from the linked list(O(n))
struct Node * deleteIndex(struct Node*head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    int i = 0;
    for(int i=0; i<index-1;i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Case 3: delete element at a last Node from the linked list(O(n))
struct Node * deleteLast(struct Node*head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};
// Case 4: delete element at a given VALUE from the linked list(O(n))
struct Node * deleteValue(struct Node*head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
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
    head->data =4;
    head->next = second;
    // link second and third nodes
    second->data =3;
    second->next = third;
    // link third and fourth nodes
    third->data =8;
    third->next = fourth;
    // terminate the list at fourth node
    fourth->data =1;
    fourth->next = NULL;

    // Traversal
    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    //head = deleteFirst(head); // delete first element from the linked list
    //head = deleteIndex(head,1); // delete element at a given index from the linked list(O(n))
    //head = deleteLast(head);
    head = deleteValue(head,80); //delete element at a given VALUE from the linked list(O(n))
    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    return 0;
}
