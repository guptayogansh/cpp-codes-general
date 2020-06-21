// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int T, N, B, value;

//     vector<int> A;

//     cin >> T;
//     for (int i = 1; i <= T; i++)
//     {
//         int sum = 0, count = 0;
//         cin >> N >> B;

//         while (N--)
//         {
//             cin >> value;
//             A.push_back(value);
//         }

//         sort(A.begin(), A.end());

//         if (A[0] > B)
//         {
//             sum = 0;
//             count = 0;
//         }
//         else
//         {
//             for (int i = 0; i < A.size(); i++)
//             {

//                 if (sum + A[i] <= B)
//                 {
//                     sum = sum + A[i];
//                     count++;
//                 }
//             }
//         }

//         cout << "Case #" << i << ":"
//              << " " << count << "\n";

//         A.clear();
//     }
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T,N,K,P;
    
    cin>>T;
    for(int i=1;i<=T;i++){
      
      cin>>N>>K>>P;
      vector<vector<int>> k_vec(N,(vector<int>K));

      for(int i=0;i<k_vec.size();i++){
        for(int j=0;j<K[i].size();k++){
          cin>> k_vec[i][j];
        }
      } 

  

    }
        cout << "Case #" << i << ":"
             << " " << count << "\n";
    }
    return 0;
}