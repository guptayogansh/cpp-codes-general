#include <bits/stdc++.h>

using namespace std;

int main()
{

    int T, N, M, Q, P, R;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {

        cin >> N >> M >> Q;
        vector<int> helper(N + 1, 0);
        int temp = M;
        while (M--)
        {
            cin >> P;
            int i = 1;
            for (; i < floor(P / 2); i++)
            {
                if (P % i == 0)
                {
                    helper[i]--;
                    helper[P / i]--;
                }
            }

            // if (i * i == P)
            //     helper[i]--;
        }

        for (auto it : helper)
        {
            cout << it << " ";
        }
        cout << "\n";
        long long int sum = 0;
        while (Q--)
        {
            cin >> R;
            sum += N / R + helper[R];
        }

        if (N == temp)
            sum = 0;
        cout << "Case #" << i << ":"
             << " " << sum << "\n";
    }
    return 0;
}