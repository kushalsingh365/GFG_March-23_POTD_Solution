class Solution
{
public:
    int noConseBits(int n)
    {
        string s = bitset<32>(n).to_string();
        for (int i = 0; i < 32; i++)
        {
            if (s[i] == '1')
            {
                int j = i;
                while (i + 1 < 32 and s[i + 1] == '1')
                    i++;

                int len = i - j + 1;
                if (len >= 3)
                {
                    while (j < i)
                    {
                        j += 2;
                        s[j] = '0';
                        j++;
                    }
                }
            }
        }
        return bitset<32>(s).to_ullong();
    }
};
