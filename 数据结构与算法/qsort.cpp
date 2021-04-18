#include <iostream>
#include <vector>
using namespace std;

int paritition(vector<int>& arr, int low, int high)
{
    int value = arr[low];
    while (low < high)
    {
        while (arr[high] > value && low < high)
            high--;
        arr[low] = arr[high];
        while (arr[low] < value && low < high)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = value;
    return low;
}

void qsort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int par = paritition(arr, low, high);
        qsort(arr, low, par - 1);
        qsort(arr, par + 1, high);
    }
}
int main()
{
    vector<int> arr = {4,5,6,9,8,7,2,1,3};
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    qsort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

