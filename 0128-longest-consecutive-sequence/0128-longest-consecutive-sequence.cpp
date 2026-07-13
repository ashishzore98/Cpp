class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for (int n : nums)
        {
            s.insert(n);
        }
        int l = 0;
        for (int n : s)
        {
            if (s.find(n - 1) == s.end())
            {
                int cn = n;
                int lngt = 1;
                while (s.find(cn + 1) != s.end())
                {
                    cn++;
                    lngt++;
                }
                l = max(l, lngt);
            }
        }

        return l;
    }
};