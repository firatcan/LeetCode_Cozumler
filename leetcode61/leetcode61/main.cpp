#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

int getListSize(ListNode* head) {
    if (!head) return 0;
    int size = 0;
    while (head != nullptr) {
        size++;
        head = head->next;
    }

    return size;
}

ListNode* rotateRight(ListNode* head, int k) {
    int size = getListSize(head);
    if (size <= 1) return head;
    k = k % size;
    if (k == 0 || k == size) return head;


    ListNode* tempHead = head;
    for (int i = 0; i < size - k - 1; i++) {
        if (tempHead->next != nullptr) tempHead = tempHead->next;
    }

    ListNode* right = tempHead->next;
    tempHead->next = nullptr;
    ListNode* tempRight = right;
    while (tempRight->next != nullptr) {
        tempRight = tempRight->next;
    }

    tempRight->next = head;
    return right;
}
void main() 
{
    ListNode* root = new ListNode(0);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    
    ListNode* res = rotateRight(root, 4);

	system("pause");
}