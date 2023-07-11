// C++ program to count distinct
// elements in every window of size K

#include <bits/stdc++.h>
using namespace std;

// Counts distinct elements in window of size K
int countWindowDistinct(int win[], int K)
{
    int dist_count = 0;

    // Traverse the window
    for (int i = 0; i < K; i++)
    {
        // Check if element arr[i] exists in arr[0..i-1]
        int j;
        for (j = 0; j < i; j++)
            if (win[i] == win[j])
                break;
        if (j == i)
            dist_count++;
    }
    return dist_count;
}

// Counts distinct elements in all windows of size k
void countDistinct(int arr[], int N, int K)
{
    // Traverse through every window
    for (int i = 0; i <= N - K; i++)
        cout << countWindowDistinct(arr + i, K) << endl;
}

// Driver's code
int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3}, K = 4;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    countDistinct(arr, N, K);
    return 0;
}
