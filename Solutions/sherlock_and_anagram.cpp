#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n=s.size();
    int ans=0;
    for(int sz=1;sz<=n;sz++){
        for(int p=0; p<n-sz+1; p++){
            int occ1[26];
            memset(occ1,0,sizeof(26));
            for(int i=p;i<p+sz;i++)
                occ1[s[i]-'a']++;
            int occ2[26];
            for(int k=0;k<26;k++)
                occ2[k]=occ1[k];
            for(int j=p+sz;j<n;j++){
                occ2[s[j]-'a']++;
                occ2[s[j-sz]-'a']--;
                int flag=0;
                for(int k=0;k<26;k++)
                    if(occ1[k]!=occ2[k])
                        {flag=1; break;}
                if(flag==0){
                    ans++;
                    
                }
            }
        }
        
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
