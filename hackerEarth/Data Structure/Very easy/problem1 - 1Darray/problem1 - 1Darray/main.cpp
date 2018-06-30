//
//  main.cpp
//  problem1 - 1Darray
//
//  Created by RAJAT SAINI on 07/06/18.
//  Copyright © 2018 RAJAT SAINI. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int T,N,K;
    std::cin>>T;
    int i;
    For (i=0;i<T;i++)
    {
        cin>>N;
        cin>>K;
        int arr[N];
        cin>>arr[0];
        int smallest = arr[0];
        for (int j=1;j<N;j++){
            cin>>arr[j];
            if(arr[j] <= smallest){
                arr[j] = smallest;
            }
        }
        if(smallest < K){
            cout << K-smallest;
        }else{
            cout<<"0";
        }
    }
    return 0;
}
