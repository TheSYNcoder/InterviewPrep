#include<bits/stdc++.h>
using namespace std;

void binaryNumbersQueue(int n){
    queue<string> bin;
    bin.push("1");
    while(n != 0){
        string num = bin.front();
        bin.pop();
        cout << num << " ";
        n--;
        bin.push(num + "0");
        bin.push(num + "1");
    }
}
int main(){
    int size;
    cin >> size;
    binaryNumbersQueue(size);
}
