#include<bits/stdc++.h>
using namespace std;

class SortCriterion{
public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    bool compare(vector<int>& a, vector<int>& b){
        for(int i = 0; i < a.size(); i++)
            if(a[i] >= b[i]) return false;

        return true;
    }
};


int solution(vector<vector<int>>& boxes){
    int n = boxes.size();
    vector<int> lis(n, 1);

    SortCriterion check;

    sort(boxes.begin(), boxes.end(), check);


    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(check.compare(boxes[j], boxes[i]))
                lis[i] = max(lis[i], lis[j] + 1);

    return *max_element(lis.begin(), lis.end());
}

int32_t main(){
    vector<vector<int>> a = {{3,9,9}, {1,4,10}, {5,10,11}, {3,9,3}, {1,5,3}, {7, 12, 1}};
    
    cout << solution(a);
}
