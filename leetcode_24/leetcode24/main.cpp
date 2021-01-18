#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
int countList(ListNode* head)
{
    ListNode* curr = new ListNode();
    curr = head;
    int counter = 0;
    while (curr != NULL)
    {
        counter++;
        curr = curr->next;
    }
    return counter;
}
ListNode* swapPairs(ListNode* head)
{   
    int len = countList(head);
    if (len == 0)
        return head;
    if (len == 1)
        return head;
    ListNode* temp = head;
    int counter = 0;
    while (temp != NULL && (len - counter) / 2 >= 1)
    {
        int val1 = temp->val;
        counter++;
        int val2 = temp->next->val;
        counter++;
        temp->val = val2;
        temp->next->val = val1;
        temp = temp->next->next;
    }
    return head;
}
void showList(ListNode* head)
{
    ListNode* curr = new ListNode();
    curr = head;
    while (curr != NULL)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
    cout << "------------------------" << endl;
}
void main()
{
    ListNode* head = new ListNode();
    //ListNode* head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    ListNode* ret = new ListNode();
    showList(head);
    ret = swapPairs(head);
    showList(ret);

    system("pause");
}
