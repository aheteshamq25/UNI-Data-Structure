#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct student{
    int roll;
    int marks;
    string name;

}st ;



void enterDetails(vector<st> &stu){
    st s;
    int count;
    cout<<"Number of student\'s detail to fill: ";
    cin>>count;
    for(int i=0;i<count;i++){
        cout<<"Enter details of Student "<<i+1<<endl;
        cout<<"Roll no.: ";
        cin>>s.roll;
        cout<<"Name: ";
        cin>>s.name;
        cout<<"Marks: ";
        cin>>s.marks;

        stu.push_back(s);
    }
    
   
}



void displayStu(vector<st> &stu){
   
    for(int i=0;i<stu.size();i++){
        cout<<"\nStudent "<<i+1<<endl;
        cout<<"Roll no.: "<<stu[i].roll<<endl;
        cout<<"Name: "<<stu[i].name<<endl;
        cout<<"Marks: "<<stu[i].marks<<endl;
    }
    
    
}

int searchByRollNum(vector<st> &stu){
    int rn;
    cout<<"Enter the roll number of student: ";
    cin>>rn;
    if(stu.empty()){
            cout<<"No Student Found!!."<<endl;
        }
    for(int i=0; i<stu.size(); i++){
        if(rn == stu[i].roll){
            cout<<"-:Student detail:-"<<endl;
            cout<<"Roll no.: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;

            break;
        }
        
    }
    return 0;
}

int searchByName(vector<st>&stu){
    string nam;
    cout<<"Enter Name of the student: ";
    cin>>nam;
    if(stu.empty()){
            cout<<"No Student Found!!."<<endl;
        }
    for(int i=0; i<stu.size(); i++){
        if(nam == stu[i].name){
            cout<<"-:Student detail:-"<<endl;
            cout<<"Roll no.: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;

            break;
        }
        
    }
    return 0;
}

int giveToppersDetail(vector<st> &stu){

    int mrks =stu[0].marks;

    if(stu.empty()){
            cout<<"No Student Record Found!!."<<endl;
    }
    
    for(int i= 0; i<stu.size(); i++){
        if(mrks< stu[i].marks){
            mrks = stu[i].marks;
        }
    }
    for(int i=0; i<stu.size(); i++){
        if(stu[i].marks== mrks){
            cout<<"\nTopper\'s detail"<<endl;
            cout<<"Roll no.: "<<stu[i].roll<<endl;
            cout<<"Name: "<<stu[i].name<<endl;
            cout<<"marks: "<<stu[i].marks<<endl;
        }
    }
    return 0;

}







int main(){
    vector<st> student;
    int option;
    

    while(true){
    cout<<"\n---Welcome to Student details--- "<<endl;
    cout<<"1) Fill Student details"<<endl;
    cout<<"2) Display Student details"<<endl;
    cout<<"3) Search Student by Roll number"<<endl;
    cout<<"4) Search Student by Name"<<endl;
    cout<<"5) Search for Topper student"<<endl;
    cout<<"6) Exit"<<endl;
        cout<<"Enter your choice(1/2/3/4/5/6)"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            enterDetails(student);
            break;
        
        case 2:
            displayStu(student);
            break;
        
        case 3:
        searchByRollNum(student);
            
            break;
        
        case 4:
        searchByName(student);
            
            break;
        
        case 5:
        giveToppersDetail(student);
            
            break;
        
        case 6:
            cout<<"Exiting the Programme..";
            return 0;
        
        default:
            cout<<"---PLEASE ENTER THE GIVEN OPTION---"<<endl;
            cout<<"Try again...."<<endl;
            return 0;
        }
    }

    
    return 0;
}
