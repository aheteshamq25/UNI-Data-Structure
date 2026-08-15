#include <iostream>

using namespace std;

struct abc{
    int a;
    struct abc* next;
};

struct abc* top = nullptr, *ptr;

void push() {
    int item;
    ptr = new abc();
    cout<<"Enter the Element: "<<endl;
    cin>>item;

    ptr->a = item; ptr->next = nullptr;
    if(ptr == NULL){
        cout<<"Stack overflow!!"<<endl;
    }
    
    if(top == NULL){
        top = ptr;
    }
    else{
        ptr->next = top;
        top = ptr;
    }
   
}
void pop() {
    if(top==NULL){
        cout<<"stack already empty!!"<<endl;
    }else{
        abc* s = top;
        top = top->next;
        delete(s);
    }
   
}
void display() {
    ptr = top;
    cout<<"\n---Displaying Stack---"<<endl;
    while(ptr!= NULL){
        cout<<ptr->a<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
int isEmpty() {}
int isFull() {}

int main(){
    int ch;

    while (true){

        cout << "Select an option bellow:-" << endl;
        cout << "1. Push an Element in the stack" << endl;
        cout << "2. Delete an element from the stack" << endl;
        cout << "3. Display the elements of the stack" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter Your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Exiting...."<<endl;
            cout<<"exited!!!!"<<endl;
            exit(0);
            return 0;
        default:
            cout << "Invalid option!!!";
            return 0;
        }
    }
    return 0;
}