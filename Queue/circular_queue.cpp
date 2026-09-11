#include<iostream>

using namespace std;
#define Max 5
int queue[Max] , f= -1, r = -1;

int enqueue(){
    int item;
    cout<<"Enter the value: ";
    cin>>item;

    if(f==-1 && r==-1){
        
        f=0;
        r=0;
        queue[r] = item;
    }else if((r+1)%Max == f){
        cout<<"\nQueue ovflow"<<endl;
    }else{
        r = (r+1)%Max ;
        queue[r] = item;
    }
}

int dequeue(){
    if(f==-1 && r==-1){
        cout<<"\nQueue underflow...."<<endl;
    }else if(f == r){
        cout<<"Deleting the element: "<<queue[f]<<endl;
        queue[f] = 0;
        f = -1; r = -1;
    }else{
        cout<<"Deleting the element: "<<queue[f]<<endl;
        queue[f] = 0;
        f = (f+1)%Max;
    }
}
int display(){
    if(f==-1 && r==-1){
        cout<<"------Queue is Empty------"<<endl;
    }else{
        cout<<"The elements in Queue: ";
        for (int i = f; i <= r; i++)
        {
            if(queue[f]==0){
            cout<<" - |";
            }else{
            cout<<" | "<<queue[i];
            }
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