/*
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links.
Swapping data of nodes may be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.
*/
#include <iostream>

using namespace std;


struct node
{
    int data;
    node * next;
};
node* insertAtBegining(node * head,int data)
{
    node * temp = new node();
    temp->data=data;
    temp->next = head;
    head = temp;
    return head;
}
void printList(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<" -> ";
        head=head->next;
    }
    cout<<"\n";
}
node* swapTwoNodes(node * head,int x,int y)
{

    node * originalHead = head;
    node * temp;  // temporary element used for swapping
    node * prevx=NULL,* prevy=NULL,* nodex=NULL,* nodey=NULL;
    if(x==y)
    {
        cout<<"Same Element\n";
        return originalHead;
    }
    while(head->next!=NULL)
    {
        if(head->next->data==x)
            prevx=head;
        if(head->next->data==y)
            prevy=head;
        head=head->next;
    }

    if(originalHead->data==x  && prevy!=NULL)  // swapping with head pointer
    {
        nodey = prevy->next;
        prevy->next = originalHead;

        temp =originalHead->next;
        originalHead->next = nodey->next;
        nodey->next = temp;

        return nodey;
    }
    if(originalHead->data==y   && prevx!=NULL)  // swapping with head pointer
    {
        nodex = prevx->next;
        prevx->next = originalHead;

        temp =originalHead->next;
        originalHead->next = nodex->next;
        nodex->next = temp;

        return nodex;
    }
    if(prevx==NULL)
    {
        cout<<x<<" is not present in Linked List\n";
        return originalHead;
    }
    if(prevy== NULL)
    {
        cout<<y<<" is not present in Linked List\n";
        return originalHead;
    }

    nodex=prevx->next;
    nodey=prevy->next;

    // swap the prevx->next with prevy->next
    temp =prevx->next;
    prevx->next = prevy->next;
    prevy->next = temp;

    // swap the nodex->next with nodey->next
    temp =nodex->next;
    nodex->next = nodey->next;
    nodey->next = temp;

    return originalHead;
}
int main()
{
    node * head = NULL;
    head = insertAtBegining(head,12);
    head = insertAtBegining(head,1);
    head = insertAtBegining(head,22);
    head = insertAtBegining(head,21);
    head = insertAtBegining(head,42);
    head = insertAtBegining(head,14);
    head = insertAtBegining(head,52);
    head = insertAtBegining(head,2);
    head = insertAtBegining(head,5);
    printList(head);

    head = swapTwoNodes(head,1,2);   // general case
    printList(head);

    head = swapTwoNodes(head,1,100);  // Not Present
    printList(head);

    head = swapTwoNodes(head,2,12);  // swapping with an end node
    printList(head);

    head = swapTwoNodes(head,12,12);  // swapping same node
    printList(head);

    head =swapTwoNodes(head,5,12);  // swapping with a head node
    printList(head);

    head =swapTwoNodes(head,12,2);  // swapping end nodes
    printList(head);

    return 0;

}
