#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;

NODE getNode(int d)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //printf("Enter a number : ");
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, int d)
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE rotate(NODE head)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = head;
    head->prev = cur;
    head = head->next;
    head->prev->next = NULL;
    head->prev = NULL;
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("%d\n", -1);
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head = NULL;
    int t, k;
    signed int d;
    scanf("%d", &t);
    while(1)
    {
        scanf("%d", &d);
        if(d==-1)
            break;
        head = insert_end(head, d);
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++)
        head = rotate(head);
    display(head);
    return 0;
}

