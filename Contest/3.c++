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
	    
	    //Edge Case
	    set<int> st;
	    for(int i = 0; i<N; i++){
	        st.insert(A[i]);
	    }
	    if(st.size() == N){
	        cout << -1 << endl;
	        continue;
	    }
	    
	    //Edge Case
	    if(A[0] == A[N-1]){
	        cout << 0 << endl;
	        continue;
	    }
	    
	    //Logic to find no of swaps
	    int ans = INT_MAX;
	    for(int i = 0; i<N; i++){
	        for(int j = 0; j<N; j++){
	            if(A[i] == A[j]){
	                int noofmoves = i + (N-j-1);
	                ans = min(ans, noofmoves);
	            }
	        }
	    }
	    cout << ans << endl;
	    
	}

}
