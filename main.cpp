#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::swap;

void print(int arr[], int s);

// quick sort sorting algorithm
// {7, 9, 3, 2, 6}
int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[e], arr[pIndex]);
    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p - 1)); // recursive QS call for left partition
        QuickSort(arr, (p + 1), e); // recursive QS call for right partition
    }
}


int main()
{
    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;
    int myarray[16];


    cout << "Enter " << size << " integers in any order: ";
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }

    cout << "Before sorting"<< endl;
    print(myarray, size);

    QuickSort(myarray, 0, (size - 1));  // quick sort called

    cout << "After sorting" << endl;
    
    print(myarray, size);

    system("pause");
}

void print(int arr[], int s)
{

    for (int i = 0; i < s; i++)
        cout << arr[i] << "   ";
    cout << endl;
}