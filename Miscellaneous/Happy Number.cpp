class Solution {
public:
    int getnext(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            sum += d*d;
            n = n/10; 
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);
        while(fast != 1 and slow != fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        return fast == 1;
    }
};
//n = 2
//slow = 2,4,16,37,58,89,145,42,
//fast = 4,16/37,58/89,145/42,20/4,16/37,58/89,145/42   Break