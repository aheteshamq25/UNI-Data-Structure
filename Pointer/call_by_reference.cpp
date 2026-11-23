#include<iostream>

using namespace std;

void doubleNum(int *num);
int main(){
    int val = 5;
    doubleNum(&val);
    cout<<"The value is "<<val;

}

void doubleNum(int *num){
    *num = 2*(*num);
}