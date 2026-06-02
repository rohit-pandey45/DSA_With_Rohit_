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
	    int total = A[0] + A[N-1];
	    bool flag = true;
	    
	    for(int i = 0; i<N/2; i++){
	        if(A[i] + A[N-i-1] != total){
	            flag = false;
	        }
	    }
	    if(flag){
	        cout << "Yes" << endl;
	    }
	    else{
	        cout << "No" << endl;
	    }
	}

}
