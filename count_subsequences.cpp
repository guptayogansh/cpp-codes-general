#include<bits/stdc++.h>
using namespace std;


int print_subs_count(string input, string output){
    
    int count=0;
    if(input.empty()){
        return 1;
    }
    int left = print_subs(input.substr(1), output);
    int right = print_subs(input.substr(1), output+input[0]);
    count = count+left+right;
    return count;
}

int main(){
    string output, input;
    cin>>input;
    cout<<print_subs_count(input, output);
    
}
