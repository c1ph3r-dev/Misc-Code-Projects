#include <iostream>
#include <vector>
#include <cassert>

int n_highest(int n, std::vector<int> vec)
{
    int m = vec.size();
    assert(n <= m);
    std::vector<int> ans(n);

    for (int i = 0; i < m; i++)
    {
        if (i < n)
        {
            ans[i] = vec[i];
            for (int j = 0; j < i; j++)
            {
                if (ans[i] > ans[j])
                {
                    for (int k = n - 1; k > j; k--)
                    {
                        ans[k] = ans[k - 1];
                    }
                    ans[j] = vec[i];
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (vec[i] > ans[j])
                {
                    for (int k = n - 1; k > j; k--)
                    {
                        ans[k] = ans[k - 1];
                    }
                    ans[j] = vec[i];
                    break;
                }
            }

        }
    }

    return ans[n - 1];
}

int main() {
    std::vector<int> vec{ 3, 10, 2, -3, 6 };
    int ans = n_highest(2, vec);

    std::cout << ans << std::endl;

    return 0;
}