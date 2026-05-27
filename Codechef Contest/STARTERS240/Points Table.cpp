#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, Y, A, B;
	cin >> X >> Y >> A >> B;
	if(X > A){
	    cout << "Alice";
	}
	else if (X < A){
	    cout << "Bob";
	}
	else{
	    if(Y > B){
	        cout << "Alice";
	    }
	    else if(Y < B){
	        cout << "Bob";
	    }
	    else{
	        cout << "Alice";
	    }
	}

}
