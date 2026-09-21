#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int a;
    Node *next;

    Node(int a1, Node *next1)
    {
        a = a1;
        next = next1;
    }
    Node(int a1)
    {
        a = a1;
        next = nullptr;
    }
};

Node *insertValue(vector<int> &arr, int newData)
{
    Node *head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    
    Node *newNode = new Node(newData, head);

    return newNode;
}


int main()
{
    vector<int> arr = {1, 3, 4, 5, 7};
    Node *head = new Node(arr[0]);

    Node *temp = insertValue(arr, 9);
    
    while (temp != nullptr)
    {
        cout << temp->a << " ";
        temp = temp->next;
    }
}