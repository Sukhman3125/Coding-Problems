class Solution {
  public:
    int solve(int n, string s)
    {
        // Stores customers currently using computers
        vector<char> occupiedCustomers;

        // true if the customer was rejected
        bool rejectedCustomer[26] = {false};

        int rejected = 0;

        for (char c : s)
        {
            int idx = c - 'A';

            // Check whether customer is using a computer
            auto it = find(occupiedCustomers.begin(), occupiedCustomers.end(), c);

            // Customer is using a computer
            if (it != occupiedCustomers.end())
            {
                // Customer leaves, so free the computer
                occupiedCustomers.erase(it);
            }
            else
            {
                // If the customer was already rejected,
                // this occurrence is their departure
                if (rejectedCustomer[idx])
                {
                    continue;
                }

                // Customer arrives
                if ((int)occupiedCustomers.size() < n)
                {
                    // Assign a computer
                    occupiedCustomers.push_back(c);
                }
                else
                {
                    // No computer is available
                    rejectedCustomer[idx] = true;
                    rejected++;
                }
            }
        }

        return rejected;
    }
};
