#include <iostream>

using namespace std;

struct node
{
    int data;
    node * next;
};
node*  append(node * head,int data)
{
    node * originalHead = head;
    node * temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
        return head; // this will not update the local pointer , so we have to return this
    }
    else
    {
        while(head->next!=NULL)
            head= head->next;
          head->next =temp ;  // there is no need to update as  this is changing underlying linked list and not head pointer
        return originalHead;
    }

}
void printlist(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
// originalHead is used to maintain a good and uniform code structure
// Returning originalHead is not making any difference
node*  deleteByKey(node * head , int key)
{
    cout<<"TO DELETE key:"<<key<<"\n";
    node * orignalHead= head;
    if(head->data==key)
    {
        node* temp  = head;
        head = head->next;
        delete temp;
        return head;
    }
    else
    {
        while(head->next != NULL&&head->next->data!=key)
        {
            head = head->next;
        }
        // head is a node previous to be deleted node
        if(head->next==NULL)// key not found
        {
            cout<<"NO key\n";
            return orignalHead;
        }
        node * temp = head->next ; // to be deleted
        head ->next = temp->next;
        delete temp;
        return orignalHead;
        // no need of returning a head pointer , since it is changing the Linked list and not the head pointer
    }
}
//1 - based indexing
node* deleteByPosition(node * head , int position)
{
    cout<<"TO DELETE position : "<<position<<"\n";
    node * originalHead = head;
    if(position==1) // delete head node
    {
        node * temp = head;
        head= head->next;
        delete(temp);
        return head; // should be returned as head is changed now
    }
    else
    {
        int i;
        for(i=1;i<=position-2;i++)
            head=head->next;
        // head is a node previous to be deleted node
        node * temp =head->next; // to be deleted
        head->next = temp->next;
        delete temp;
        return originalHead; // Won't make a difference but to maintain uniformity
    }
}
int main()
{

    // Even when there is no need to update main() head pointer, we have to still update it as to maintain a good code structure

    node * head = NULL;
    head =append(head,1);  // Head pointer should be updated
    printlist(head);
    head = append(head,2);   // no need to update head pointer as discussed in append()
    printlist(head);
    head =append(head,3);
    head=append(head,4);
    head =append(head,5);
    head =append(head,6);
    head =append(head,7);
    head =append(head,8);
    head =append(head,9);

    printlist(head);

    // 1->2->3->4->5
    head  = deleteByKey(head,1);  // have to update head pointer , since 1 is the first node
    printlist(head);

    // 2->3->4->5
    head = deleteByKey(head,3); // no need to update
    printlist(head);

    head= deleteByKey(head,20);  // no need to update
    printlist(head);

    head = deleteByPosition(head,4);
    printlist(head);
    return 0;
}
