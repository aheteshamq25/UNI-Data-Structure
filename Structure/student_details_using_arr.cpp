#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

typedef struct student{
    int roll;
    int marks;
    string name;

}st ;


void enterDetails(st stu[] , int n){
    // Open file in append mode so new entries are added
    ofstream hout("students.txt", ios::app);  // ios::app --> it adds the new entries at the end while preserving the current ones.
    if(!hout){
        cout<<"Unable to open students.txt for writing."<<endl;
        return;
    }

    for(int i=0; i<n; i++){
        cout<<"Student no "<<i+1<<endl;
        cout<<"Roll number: ";
        cin>>stu[i].roll;
        cout<<"Name: ";
        cin>>stu[i].name;
        cout<<"Marks: ";
        cin>>stu[i].marks;

        // write the collected data to the file.
        hout<<"Student no "<<i+1<<"\n";
        hout<<"Roll number: "<<stu[i].roll<<"\n";
        hout<<"Name: "<<stu[i].name<<"\n";
        hout<<"Marks: "<<stu[i].marks<<"\n";
        hout<<"-----------------------"<<"\n";

        cout<<endl;
    }

    hout.close();
}

// Read and display all student records from the file
void displayFromFile(){
    ifstream fin("students.txt");
    if(!fin){
        cout<<"No records found (students.txt missing)."<<endl;
        return;
    }

    cout<<"\n---STUDENTS FROM DATABASE---"<<endl;
    string line;
    while(getline(fin, line)){
        cout<<line<<endl;
    }
    fin.close();
}



void displayStu(st stu[], int n){
    cout<<"\n---DISPLAYING STUDENT DETAILS---"<<endl;
    for(int i= 0;i<n;i++){
        cout<<"Student "<<i+1<<" is:"<<endl;
        cout<<"Roll number: "<<stu[i].roll<<endl;
        cout<<"Name: "<<stu[i].name<<endl;
        cout<<"marks: "<<stu[i].marks<<endl;
        cout<<endl;

    }
   
}

int searchByRollNum(st stu[], int n){
    int rn;
    cout<<"Enter the Roll number: ";
    cin>>rn;
    bool found = false;
    for(int i=0; i<n;i++){
        if(rn == stu[i].roll){
            cout<<"\n---Student\'s detail---"<<endl;
            cout<<"Roll number: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;
            cout<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"\n---NO DETAILS AVAILABLE OF THE STUDENT---"<<endl;
    }
    
    return 0;
}

int searchByName(st stu[], int n){
    string nm;
    cout<<"Enter the Student name: ";
    cin>>nm;
    bool found = false;
    for(int i=0; i<n;i++){
        if(nm == stu[i].name){
            cout<<"\n---Student\'s detail---"<<endl;
            cout<<"Roll number: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;
            cout<<endl;
            
            found = true;
        }
    }
    if(!found){
        cout<<"\n---NO DETAILS AVAILABLE OF THE STUDENT---"<<endl;
    }

  
    return 0;
}

int giveToppersDetail(st stu[], int n){
    int max_marks= 0;
    bool found = false;
    for(int i=0; i<n;i++){
        if(max_marks<stu[i].marks){
            max_marks = stu[i].marks;
        }
    }
    for(int i=0; i<n;i++){
        if(max_marks == stu[i].marks){
            cout<<"\n---Student\'s detail---"<<endl;
            cout<<"Roll number: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;
            cout<<endl;
            
            found = true;
        }
    }

    if(!found){
        cout<<"\nNO DETAILS AVAILABLE OF THE STUDENT"<<endl;
    }

    return 0;

}


int main(){
    int count;
    cout<<"How many student do you wanna register: ";
    cin>>count;
    st *student = new st[count];
    int option;
    

    while(true){
    cout<<"\n---Welcome to Student details--- "<<endl;
    cout<<"1) Fill Student details"<<endl;
    cout<<"2) Display Student details recently registered"<<endl;
    cout<<"3) Search Student by Roll number"<<endl;
    cout<<"4) Search Student by Name"<<endl;
    cout<<"5) Search for Topper student"<<endl;
    cout<<"6) Display all students from Database"<<endl;
    cout<<"7) Exit"<<endl;
    cout<<"Enter your choice(1-7): ";
    cin>>option;

    switch (option)
        {
            case 1:
                enterDetails(student , count);
                break;
            
            case 2:
                displayStu(student, count);
                break;
            
            case 3:
            searchByRollNum(student, count);
                
                break;
            
            case 4:
            searchByName(student , count);
                
                break;
            
            case 5:
            giveToppersDetail(student, count);
                
                break;

            case 6:
                // display contents saved in file
                displayFromFile();
                break;

            case 7:
                cout<<"Exiting the Programme.."<<endl;
                delete[] student;
                return 0;
            
            default:
                cout<<"---PLEASE ENTER THE GIVEN OPTION---"<<endl;
                cout<<"Try again...."<<endl;
                return 0;
        }
    }

    
    return 0;
}
