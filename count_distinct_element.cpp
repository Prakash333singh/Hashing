// C++ program to count distinct
// elements in every window of size K

// brute force apporeach

#include <bits/stdc++.h>
using namespace std;

// // Counts distinct elements in window of size K
// int countWindowDistinct(int win[], int K)
// {
//     int dist_count = 0;

//     // Traverse the window
//     for (int i = 0; i < K; i++)
//     {
//         // Check if element arr[i] exists in arr[0..i-1]
//         int j;
//         for (j = 0; j < i; j++)
//             if (win[i] == win[j])
//                 break;
//         if (j == i)
//             dist_count++;
//     }
//     return dist_count;
// }

// // Counts distinct elements in all windows of size k
// void countDistinct(int arr[], int N, int K)
// {
//     // Traverse through every window
//     for (int i = 0; i <= N - K; i++)
//         cout << countWindowDistinct(arr + i, K) << endl;
// }

// // Driver's code
// int main()
// {
//     int arr[] = {1, 2, 1, 3, 4, 2, 3}, K = 4;
//     int N = sizeof(arr) / sizeof(arr[0]);

//     // Function call
//     countDistinct(arr, N, K);
//     return 0;
// }
void countDistinct(int arr[], int K, int N)
{
    // Creates an empty hashmap hm
    unordered_map<int, int> hm;

    // initialize distinct element count for current window
    int dist_count = 0;

    // Traverse the first window and store count
    // of every element in hash map        0   1  2  3
    for (int i = 0; i < K; i++) //{1, 2, 4, 4}, K = 2
    {
        if (hm[arr[i]] == 0)
        {
            dist_count++;
        }

        hm[arr[i]] += 1; //<1,1>   <2,1>
    }

    // Print count of first window
    cout << dist_count << " ";

    // Traverse through the remaining array
    for (int i = K; i < N; i++)
    {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (hm[arr[i - K]] == 1)
        {
            dist_count--;
        }
        // reduce count of the removed element
        hm[arr[i - K]] -= 1;

        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count

        if (hm[arr[i]] == 0)
        {
            dist_count++;
        }
        hm[arr[i]] += 1;

        // Print count of current window
        cout << dist_count << " ";
    }
}

// Driver's code
int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;

    // Function call
    countDistinct(arr, K, N);

    return 0;
}
// This solution is contributed by Adity