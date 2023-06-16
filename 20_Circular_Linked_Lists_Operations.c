#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node *head){
    struct Node *ptr=head;
    do{
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    //do{}while(); is used to start from head and travel all the way through head again
}
struct Node* insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while(p->next != head){
        p=p->next;
    }
    // At this point p is pointing to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate  memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data =4;
    head->next = second;

    // link second and third nodes
    second->data = 3;
    second->next = third;

    //link third node with fourth node
    third->data = 6;
    third->next = fourth;

    //link fourth node to head
    fourth->data = 1;
    fourth->next = head;

    // Traversal
    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);

    // Insertion
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}
