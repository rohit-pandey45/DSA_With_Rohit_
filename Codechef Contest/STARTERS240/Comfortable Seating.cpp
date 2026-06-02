#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    vector<int> A(N);
	    for(int i = 0; i<N; i++){
	        cin >> A[i];
	    }
	    int mini = INT_MAX;
	    for(int i = 0; i<N; i++){
	        mini = min(mini,A[i]);
	    }
	    int cntmini = 0;
	    for(int i = 0; i<N; i++){
	        if(A[i] == mini){
	            cntmini++;
	        }
	    }
	    if(cntmini > 1){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	   
	}

}
