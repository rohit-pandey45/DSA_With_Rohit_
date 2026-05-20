#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long M, K;
        cin >> N >> M >> K;
        vector < long long > A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            //A[i] = A[i]/K;
        }

        sort(A.rbegin(), A.rend());
        M += 1;
        long long totalrose = 0;
        //long long totalspace = 0;
        for (int i = 0; i < N; i++) {
            if (M <= 1) break;
            //long long roseofonecolor = A[i]*K;
            long long blocks = A[i] / K;
            long long remaining = A[i] % K;
            long long spaceleft = blocks * (K + 1) + (remaining > 0 ? remaining + 1 : 0);

            if (M >= spaceleft) {
                totalrose = totalrose + A[i];
                M = M - spaceleft;
            }
            else {
                long long fitblocks = M / (K + 1);
                totalrose = totalrose + fitblocks * K;
                M = M - fitblocks * (K + 1);
                if (M > 1) {
                    long long rosesleft = A[i] - fitblocks * K;
                    long long rose = min(rosesleft, M - 1);
                    totalrose = totalrose + rose;
                    M = M - (rose + 1);
                }
                break;
            }


        }
        cout << totalrose << endl;

    }

}