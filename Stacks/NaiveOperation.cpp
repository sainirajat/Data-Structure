#include<iostream>
using namespace std;


bool isEmpty (int* arr,int head,int n){
    if((arr[head]==-3210) && (arr[(head-1)%n]==-3210)){
        return true;
    }
    else{
    return false;
    }
}

bool isFull(int* arr,int head){
    if(arr[head]!=-3210){
        return true;
    }
    else{
    return false;
    }
}

int* insertNumber(int* arr,int num,int head,int n){
    arr[head]=num;
    return arr;
}

int* deleteNumber(int* arr,int head,int n){
        arr[head] = -3210;
        return arr;
}

void displayStack(int* arr,int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]!=-3210){
        cout<<arr[i]<<"  ";
        }
        }
    cout<<endl;
}


int main(){
    int n,i;
    cout<<"Enter the max length of the stack"<<endl;
    cin>>n;
    int arr[n];
    //initialising the values of the array (not compulsary) ,help in checking if value is not set yet
    for(i=0;i<n;i++){
        arr[i]=-3210;
    }
    
    
    int head=0;
    //menu
    while(1){
        int choice;
        cout<<"choose what operation to do"<<endl;
        cout<<"1 --> insert number "<<endl;
        cout<<"2 --> delete number"<<endl;
        cout<<"3 --> display stack"<<endl;
        cout<<"0 --> exit"<<endl;
        cin>>choice;
        
        if(choice==1){
            int num;
            cout<<"enter number to be inserted"<<endl;
            cin>>num;
            if(isFull(arr,head)){
                cout<<"sorry stack is already full";
            }
            else{
                insertNumber(arr,num,head,n);
                head = ((head+1)%n);
            }
        }
        else if(choice==2){
            if(isEmpty (arr,head,n)){
                
                cout<<"sorry, stack is already empty"<<endl;
            }
            else{
                deleteNumber(arr,head,n);
                head = ((head-1)%n);
            }
            
        }
        
        else if(choice==3){
            displayStack(arr,n);
        }
        
        else{
            cout<<"here i go"<<endl;
            return 0;
        }
    }
        return 0;
}
