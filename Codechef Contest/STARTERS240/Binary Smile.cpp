#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    string A, B;
	    cin >> A >> B;
	    
	    vector<int> cntA, cntB;
	    for(int i = 0; i<N; i++){
	        if(A[i] == '1'){
	            cntA.push_back(i);
	        }
	        if(B[i] == '1'){
	            cntB.push_back(i);
	        }
	    }
	    
	    if(cntA.size() != cntB.size()){
	        cout << -1 << endl;
	        continue;
	    }
	    
	    int cntminreverse = 0;
	    for(int i = 0; i<cntA.size(); i++){
	        if(cntA[i] != cntB[i]){
	            cntminreverse++;
	        }
	    }
	    cout << cntminreverse << endl;
	}

}
