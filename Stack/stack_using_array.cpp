#include <iostream>

using namespace std;

void push(int arr[], int size, int &top)
{
    int item;
    cout << "Enter the item: ";
    cin >> item;
    if (top == size - 1)
    {
        cout << "stack overflow!" << endl;
        return;
    }
    else
    {
        arr[++top] = item;
    }
}
void pop(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "stack underflow!!" << endl;
        return;
    }
    else
    {
        cout << "delete element = " << arr[top];
        top--;
    }
}
void display(int arr[], int &top)
{
    for (int i = top; i>0; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size = 5;
    int top = -1;
    int arr[5];
    int choice;

    while (true)
    {

        cout << "Select an option bellow:-" << endl;
        cout << "1. Push an Element in the stack" << endl;
        cout << "2. Delete an element from the stack" << endl;
        cout << "3. Display the elements of the stack" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push(arr, size, top);
            break;
        case 2:
            pop(arr, top);
            break;
        case 3:
            display(arr, top);
            break;
        case 4:
            exit(0);
            return 0;

        default:
            cout << "Invalid choice!!!" << endl;
            return 0;
        }
    }

    return 0;
}