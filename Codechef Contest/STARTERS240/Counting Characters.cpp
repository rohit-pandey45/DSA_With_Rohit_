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
	    int cnta = 0;
	    int cntb = 0;
	    for(int i = 0; i<N; i++){
	        if(S[i] == 'a'){
	            cnta++;
	        }
	        else{
	            cntb++;
	        }
	    }
	    cout << cnta << " " << cntb << endl;	
	    
	}

}
