#include <bits/stdc++.h>   //Won't work on Dev c++, works on online compilers
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head,int data) //insertion at head
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print(Node* head) //printing Link list
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void inputElements(Node* head1,Node* head2,unordered_map<int,int> &map) //Put elements into map with their key
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1 !=NULL || temp2 != NULL)
    {
        if(temp1 != NULL)
        {
            map[temp1->data]++;
            temp1 = temp1->next;
        }
        if(temp2 != NULL)
        {
            map[temp2->data]++;
            temp2 = temp2->next;
        }
    }
}

Node* getIntersection(unordered_map<int,int>map)
{
    Node* Intersection = NULL;
    for(auto it = map.begin(); it!=map.end(); it++)
    {
        if(it->second == 2)
        {
            push(&Intersection, it->first);  //Push elements present in both lists into Intersection list
        }
    }
    return Intersection;
}

Node* getUnion(unordered_map<int,int>map)
{
    Node* Union = NULL;
    for(auto it = map.begin(); it != map.end(); it++)
    {
        push(&Union,it->first);  //Push all unique elements into Union List
    }
    return Union;
}

void getIntersectionUnion(Node* head1,Node* head2)
{
    unordered_map<int,int> map;
    inputElements(head1,head2,map); //Enter elements of both lists into map as key value pair
    Node* Intersection = getIntersection(map) ;
    Node* Union = getUnion(map);
    cout<<"List of Intersection: ";
    print(Intersection);
    cout<<"List of Union: ";
    print(Union);
}


int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    push(&head1,1);
    push(&head1,2);
    push(&head1,3);
    push(&head1,4);
    push(&head1,5);
    
    push(&head2,2);
    push(&head2,4);
    push(&head2,6);
    push(&head2,8);
    push(&head2,10);
    
    cout<<"Link list 1: ";
    print(head1);
    cout<<"Link list 2: ";
    print(head2);
    getIntersectionUnion(head1,head2);
    
}
