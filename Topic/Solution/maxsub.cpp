class Solution {
public:
    string lastSubstring(string str) {
        int i = 0, j = 1, k = 0;
        while((j + k) < str.length()){
            if(str[j + k] == str[i + k])
                k++;
            else if(str[j + k] < str[i + k]){
                j += k + 1;
                k = 0;
            }
            else{
                i = j ;
                j++;
                k = 0;
            }
        }
        return str.substr(i);
    }
};