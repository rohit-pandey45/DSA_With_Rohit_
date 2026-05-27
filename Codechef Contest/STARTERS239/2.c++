#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    string S;
	    cin >> S;
	    int cnt = 0;
	    int maxcnt = 0;
	    for(int i = 0; i<N; i++){
	        if(S[i] != 'a'  && S[i] != 'e'  && S[i] != 'i'  && S[i] != 'o'  && S[i] != 'u'){
	            cnt++;
	            maxcnt = max(cnt,maxcnt);
	        }
	        else{
	            cnt = 0;
	        }
	    }
	    if(maxcnt >= 4){
	        cout << "Yes" << endl;
	    }
	    else{
	        cout << "No" << endl;
	    }
	}

}
