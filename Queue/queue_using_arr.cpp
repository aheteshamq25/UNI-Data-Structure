#include<iostream>

using namespace std;
#define Max 5
int queue[Max] , f= -1, r = -1;

int isFull(){

}
int isEmpty(){

}
int enqueue(){
    int item;
    cout<<"Enter the value: ";
    cin>>item;

    if(f==0 && r == Max -1){
        cout<<"\n!!!!Queue overflow............"<<endl;
    }
    else if(r == -1){
        f = 0;
        r=0;
        queue[r] = item;
    }else{
        r++;
        queue[r] = item;
    }

}

int dequeue(){
    if(f==-1 || f>r){
        cout<<"\n!!!Queue Underflow.........."<<endl;

    }else if(f==r){
        cout<<"Deleting the element from front: "<<queue[f]<<endl;
        f=-1;r=-1;
    }else{
        cout<<"Deleting the element from front: "<<queue[f++]<<endl;

    }

}
int display(){
    if(f==-1){
        cout<<"Queue is Empty............."<<endl;
    }else{
        cout<<"Displaying Queue: ";
        for(int i = f; i<=r; i++){
            cout<<queue[i]<<" ";
        }

    }

    cout<<"\nFront: "<<f<< " Rear: "<<r<<endl;

}


int main(){
    int choice;

    while (true)
    {

        cout << "Select an option bellow:-" << endl;
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