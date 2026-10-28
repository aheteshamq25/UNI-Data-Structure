#include<iostream>

using namespace std;

#define ROLL "25BCS007"
#define STUDENT_NAME "Ahetesham Qureshi"

#define Max 5
int queue[Max] , f= -1, r = -1;


int isFull(){
    if(r==Max){
        cout<<"Queue is Full............."<<endl;
    }else{
        int space = Max - r;
        cout<<"Space Available: "<<space*4<<" bits"<<endl;
    }

}
int isEmpty(){
    if(f==-1){
        cout<<"Queue is Empty............."<<endl;
    }else{
        int space = r;
        cout<<"Space Occupied: "<<space*4<<" bits"<<endl;
    }

}

int insertFront(){
    int value;
    cout<<"Roll: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;
    

    if(r==Max){
        cout<<"Queue is Full............."<<endl;
    }
    cout<<"Enter value: ";
    cin>>value;


    if (f == -1) {
        f =0;
        r = 0;
    }
    else if (f== 0) f = Max - 1;
    else f--;
    queue[f] = value;
    cout<<"Inserted at front.";
}

/* InsertRear: reads an integer; returns nothing. Checks capacity, initializes
   an empty deque or advances rear circularly, then stores the value. */
int insertRear(){
    int value;
    cout<<"Roll: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if(r==Max){
        cout<<"Queue is Full............."<<endl;
    }
    cout<<"Enter value: ";
    cin>>value;

    if (f == -1) {
        f =0;
        r = 0;
    }
    else if (r == Max - 1) f = 0;
    else r++;
    queue[r] = value;
    cout<<"Inserted at rear.";
}


int deleteFront(){
    cout<<"Roll: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if (isEmpty()) { cout<<"Queue is empty."<<endl; }
    cout<<"Deleted:  "<<queue[f]<<endl;
    if (f == r) f = r = -1;
    else if (f == Max - 1) f = 0;
    else f++;
}
int deleteRear(){

    cout<<"Roll: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;
    if (isEmpty()) { cout<<"Deque is empty."<<endl; }
    cout<<"Deleted:  "<<queue[r]<<endl;
    if (f == r) f = r = -1;
    else if (r == 0) r = Max - 1;
    else r--;
}

void getFront(){


    /* no parameters require for this Function and it checks empty state, then prints the
   front element without deleting it. */

    
    cout<<"Roll: "<< ROLL<< "Name: "<<STUDENT_NAME<<endl;
    if (isEmpty()) cout<<"Queque is empty."; 
    else cout<<"Front:"<< f << "Value: "<<queue[f]<<endl;

}
void getRear(){

    /* This function checks empty state, then prints the
   rear element without deleting it. */
    
    cout<<"Roll: "<< ROLL<< "Name: "<<STUDENT_NAME<<endl;
    if (isEmpty()) cout<<"Queque is empty."; 
    else cout<<"Rear:"<< r << "Value: "<<queue[r]<<endl;
}




int display(){
    /* no parameters required or return value. Traverses from front through rear,
   and prints every stored element. */
    
    cout<<"Roll: "<< ROLL<< "Name: "<<STUDENT_NAME<<endl;
    if(f==-1){
        cout<<"Queue is Empty............."<<endl;
    }else{
        cout<<"Displaying Queue: ";
        for (int i = f; ; i = (i + 1) % Max) {
        printf("%d ", queue[i]);
        if (i == r) break;
    }

    }

    cout<<"\nFront: "<<f<< " Rear: "<<r<<endl;

}


int main(){

    /* no parameters required; returns 0 after Exit. Prints student identity, repeats
   the menu, dispatches operations, and handles invalid choices. */
    int choice;
    
    while (true)
    {
        cout<<endl;
        cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;


        cout << "Select an option bellow:-" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Deletion at Front" << endl;
        cout << "4. Deletion at Rear" << endl;
        cout << "5. Get front value" << endl;
        cout << "6. Get rear value" << endl;
        cout << "7. Display queue" << endl;
        cout << "8. Check isFull"<< endl;
        cout << "9. Check isEmpty"<< endl;
        cout << "10. Exit The Program" << endl;
        
        cout << "\nEnter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        insertFront();
            break;
        case 2:
        insertRear();
            break;
        case 3:deleteFront();
            break;
        case 4:deleteRear();
            break;
        case 5:getFront();
            break;
        case 6:getRear();
            break;
        case 7:display();
            break;
        case 8:isFull();
            break;
        case 9:isEmpty();
            break;
        case 10:cout<<"Exiting the program...";
            return 0;

        default:
            cout << "Invalid choice!!!" << endl;
            return 0;
        }
    }
    return 0;
}