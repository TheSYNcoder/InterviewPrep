#include<bits/stdc++.h>

using namespace std;

class MinElemntStack{
    stack<int> st;
    int minElement;

public:
    void push(int x){
        if(st.empty()){
            minElement = x;
            st.push(x);
        }

        else{
            if(x >= minElement) 
                st.push(x);
            else{
                st.push(2*x - minElement);
                minElement = x;
            }
        }
    }

    bool empty() {
        return st.empty();
    }

    int getMin() {
        return minElement;
    }

    int top() {
        return (st.top() < minElement? minElement: st.top());
    }

    void pop(){
        if(st.top() > minElement) st.pop();

        else{
            int y = st.top();

            minElement = 2*minElement- y;

            st.pop();
        }
    }

};

int main(){
    MinElemntStack st;

    st.push(5); st.push(3); st.push(2); st.push(4); st.push(10);

    while(!st.empty()){
        
        cout << "Top : " << st.top() << " Min: " << st.getMin() << endl;

        st.pop();
    }
}