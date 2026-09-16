#include<iostream>

using namespace std;
struct Node{
    int num;
    Node * next;

}*front = NULL , *ptr, *rear, q;



int isFull(){

}
int isEmpty(){

}
int enqueue(){
    int item;
    cout<<"Enter item: ";
    cin>>item;

    ptr = new Node();

    if(ptr == nullptr){
        cout<<"OverFlow Condition!!!"<<endl;
    }
    else{
        if(front== nullptr){
            front = ptr;
            rear = ptr;
        }else{
            rear->next = ptr;
            rear = ptr;
        }
        ptr->num = item;
        ptr->next = NULL;
    }

}

int dequeue(){
    if(front==NULL){
        cout<<"UnderFlow Condition!!!"<<endl;

    }else{
        cout<<"Deleting the front value: "<<front->num;
        front = front->next;
    }

}
int display(){
    ptr = front;
    if(ptr==NULL){
        cout<<"Queue is Empty: "<<endl;

    }else{
        while (ptr!= NULL)
        {
            cout<<ptr->num <<" |";
            ptr = ptr->next;
        }
    }

}


int main(){
    int choice;

    while (true)
    {

        cout << "\nSelect an option bellow:-" << endl;
        cout << "1. Enqueue operation" << endl;
        cout << "2. Dequeue operation" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        enqueue();
            break;
        case 2:
        dequeue();
            break;
        case 3:
        display();
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