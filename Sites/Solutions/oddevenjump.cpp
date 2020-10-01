#include<bits/stdc++.h>
using namespace std;
int oddEvenJumps(vector<int>& A) {
        stack<int> left;
        stack<int> right;
        unordered_map<int, int> nextBigger;
        unordered_map<int, int> nextSmaller;
        map<int, int> index;
        map<int, int> negetiveindex;
        int len = A.size();
        for(int i = len - 1 ; i >= 0 ; i--){
            if(index.find(A[i]) == index.end())
            {
            auto nb = index.upper_bound(A[i]);
            auto ns = negetiveindex.upper_bound(-A[i]);
            if(nb != index.end()){
                nextBigger.insert({i, nb->second});
            }
            else{
                nextBigger.insert({i, -1});
            }
            if(ns != index.end()){
                nextSmaller.insert({i, ns->second});
            }
            else{
                nextSmaller.insert({i, -1});
            }
            index.insert({A[i], i});
            negetiveindex.insert({-A[i], i});
            }
            else{
                nextBigger.insert({i, index[A[i]]});
                nextSmaller.insert({i, index[A[i]]});
                index[A[i]] = i;
                negetiveindex[-A[i]] = i;
            }
        } 
        vector<bool> odd_start(len, false);
        vector<bool> even_start(len, false);
        int res = 0;
        odd_start[len - 1] = true;
        even_start[len - 1] = true;
        for(int i = len - 2 ; i >= 0 ; i--){
            int next = nextBigger[i];
            
            if(next != -1 && even_start[next] == true){
                res++;
                odd_start[i] = true;
            }
            if(odd_start[nextSmaller[i]] == true){
                even_start[i] = true;
            }
        }
           
        return   (res + 1);
    }

int main(){
    int size;
    cin >> size;
    vector<int> A(size);
    for(int i = 0 ; i < size ; i++){
        cin >> A[i];
    }
    cout << oddEvenJumps(A);

}