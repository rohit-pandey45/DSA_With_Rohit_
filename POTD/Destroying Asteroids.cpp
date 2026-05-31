class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        int maxi = *max_element(asteroids.begin(),asteroids.end());
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(asteroids[i] != maxi){
                sum += asteroids[i];
            }
        }
        if((mass+sum) < maxi)   return false;
        sort(asteroids.begin(),asteroids.end());
        long long runmass = mass;
        for(int i = 0; i<n; i++){
            if(runmass >= asteroids[i]){
                runmass += asteroids[i];
            }
            else{
                break;
            }
        }
        long long arrsum = accumulate(asteroids.begin(),asteroids.end(),0LL);
        if(runmass == (mass + arrsum)){
            return true;
        }
        return false;

    }
};