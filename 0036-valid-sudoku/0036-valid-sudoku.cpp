class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        unordered_set<char> r[9];
        unordered_set<char> c[9];
        unordered_set<char> b[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                char n = board[i][j];
                int bs = (i / 3) * 3 + (j / 3);
                if (r[i].count(n))
                    return false;
                if (c[j].count(n))
                    return false;
                if (b[bs].count(n))
                    return false;
                r[i].insert(n);
                c[j].insert(n);
                b[bs].insert(n);
            }
        }

        return true;
    }
};