bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();

        // Check if existing arrangement is valid
        for (int i = 1; i < n; i++) {
            if (seats[i] == 1 && seats[i - 1] == 1)
                return false;
        }

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                bool left  = (i == 0 || seats[i - 1] == 0);
                bool right = (i == n - 1 || seats[i + 1] == 0);

                if (left && right) {
                    seats[i] = 1;
                    k--;
                    if (k <= 0) return true;
                }
            }
        }

        return k <= 0;
    }