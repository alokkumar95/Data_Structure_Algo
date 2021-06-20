#include <bits/stdc++.h>

using namespace std;

vector<int> merge(const vector<int> &left, const vector<int> &right)
{
    int a = left.size();
    int b = right.size();
    vector<int> merged(a + b);
    int i = 0, j = 0, k = 0;

    while (i < a && j < b)
    {
        if (left[i] <= right[j])
        {
            merged[k] = left[i];
            i++;
        }
        else
        {
            merged[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < a)
    {
        merged[k] = left[i];
        i++;
        k++;
    }

    while(j<b){
        merged[k]=right[j];
        j++;
        k++;
    }

    return merged;
}

vector<int> mergeSort(const vector<int> &arr)
{
    // base case single elem
    if (arr.size() <= 1)
        return arr;

    int middleIndex = arr.size() / 2;
    const vector<int> left(arr.begin(), arr.begin() + middleIndex);
    const vector<int> right(arr.begin() + middleIndex, arr.end());

    vector<int> leftSorted = mergeSort(left);
    vector<int> rightSorted = mergeSort(right);
    return merge(leftSorted, rightSorted);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    vector<int> res=mergeSort(arr);
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}