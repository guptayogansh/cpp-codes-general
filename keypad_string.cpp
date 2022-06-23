#include<bits/stdc++.h>
using namespace std;



string keypad[10] = {"", "", "abc","def","ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};

void print_keypad(int num, string output){
    
    if(num==0){
        cout<<output<<"\n";
        return;
    }
    
    int last_digit = num%10;
    num = num/10;
    
    for(auto ch:keypad[last_digit])
        print_keypad(num,ch+output);
}

int main(){
    int num;
    string output;
    cin>>num;
    print_keypad(num, output);
    
}
