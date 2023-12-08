#include <bits/stdc++.h>
using namespace std;

void heapify(int *a, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && a[largest] < a[left])
    {
        largest = left;
    }
    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    int size = n;
    while (size > 1)
    {
        swap(a[size], a[1]);
        size--;
        heapify(a, size, 1);
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // Heapify
    for (int i = n / 2; i > 0; i--)
    {
        heapify(a, n, i);
    }

    // Heap Sort
    heapSort(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}