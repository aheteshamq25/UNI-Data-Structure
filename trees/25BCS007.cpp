#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define ROLL "25BCS007"
#define STUDENT_NAME "Ahetesham Qureshi"

vector<int> tree;
int n = 0;


// CreateTree: Takes N integers from the user and stores them
// in an array representation of a Complete Binary Tree.
// No parameters and no return value.
// Each new element is inserted level by level.
void createTree(){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    cout<<"Enter number of nodes: ";
    cin>>n;

    tree.clear();

    if(n<=0){
        cout<<"Invalid number of nodes."<<endl;
        n=0;
        return;
    }

    cout<<"Enter "<<n<<" integers:"<<endl;

    for(int i=0; i<n; i++){
        int value;
        cout<<"Enter value "<<i+1<<": ";
        cin>>value;

        tree.push_back(value);
    }

    cout<<"Complete Binary Tree created successfully."<<endl;

}


// Inorder: Traverses the tree in Left, Root, Right order.
// Takes a constant reference to the tree and returns nothing.
// Uses a stack to visit the left subtree before the root
// and then the right subtree.
void inorder(const vector<int>& tree){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if(tree.empty()){
        cout<<"Tree is Empty............."<<endl;
        return;
    }

    stack<int> s;
    int i=0;

    cout<<"Inorder Traversal: ";

    while(i<tree.size() || !s.empty()){

        while(i<tree.size()){
            s.push(i);
            i=2*i+1;
        }

        i=s.top();
        s.pop();

        cout<<tree[i]<<" ";

        i=2*i+2;
    }

    cout<<endl;

}


// Preorder: Traverses the tree in Root, Left, Right order.
// Takes a constant reference to the tree and returns nothing.
// Uses a stack to visit the root first, then its left
// and right children.
void preorder(const vector<int>& tree){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if(tree.empty()){
        cout<<"Tree is Empty............."<<endl;
        return;
    }

    stack<int> s;

    s.push(0);

    cout<<"Preorder Traversal: ";

    while(!s.empty()){

        int i=s.top();
        s.pop();

        cout<<tree[i]<<" ";

        if(2*i+2<tree.size()){
            s.push(2*i+2);
        }

        if(2*i+1<tree.size()){
            s.push(2*i+1);
        }

    }

    cout<<endl;

}


// Postorder: Traverses the tree in Left, Right, Root order.
// Takes a constant reference to the tree and returns nothing.
// Uses two stacks to reverse the Root, Right, Left order
// into Left, Right, Root.
void postorder(const vector<int>& tree){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if(tree.empty()){
        cout<<"Tree is Empty............."<<endl;
        return;
    }

    stack<int> s1,s2;

    s1.push(0);

    cout<<"Postorder Traversal: ";

    while(!s1.empty()){

        int i=s1.top();
        s1.pop();

        s2.push(i);

        if(2*i+1<tree.size()){
            s1.push(2*i+1);
        }

        if(2*i+2<tree.size()){
            s1.push(2*i+2);
        }

    }

    while(!s2.empty()){

        cout<<tree[s2.top()]<<" ";
        s2.pop();

    }

    cout<<endl;

}


// LevelOrder: Traverses the tree level by level.
// Takes a constant reference to the tree and returns nothing.
// Since the tree is stored in array form, printing elements
// from index 0 to N-1 gives level order traversal.
void levelOrder(const vector<int>& tree){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    if(tree.empty()){
        cout<<"Tree is Empty............."<<endl;
        return;
    }

    cout<<"Level Order Traversal: ";

    for(int i=0; i<tree.size(); i++){
        cout<<tree[i]<<" ";
    }

    cout<<endl;

}


// Main: Controls the complete program using a menu.
// Takes no parameters and returns 0 after successful exit.
// Displays the menu repeatedly and calls the selected
// function using a switch statement.
int main(){

    cout<<"Roll no: "<< ROLL<< " Name: "<<STUDENT_NAME<<endl;

    int choice;

    while(true){

        cout<<endl;

        cout<<"Select an option below:-"<<endl;
        cout<<"1. Create Complete Binary Tree"<<endl;
        cout<<"2. Inorder Traversal"<<endl;
        cout<<"3. Preorder Traversal"<<endl;
        cout<<"4. Postorder Traversal"<<endl;
        cout<<"5. Level Order Traversal"<<endl;
        cout<<"6. Exit The Program"<<endl;

        cout<<"\nEnter Your choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                createTree();
                break;

            case 2:
                inorder(tree);
                break;

            case 3:
                preorder(tree);
                break;

            case 4:
                postorder(tree);
                break;

            case 5:
                levelOrder(tree);
                break;

            case 6:
                cout<<"Exiting the program...";
                return 0;

            default:
                cout<<"Invalid choice!!!"<<endl;

        }

    }

    return 0;
}

