// Abhinav Gupta
// 18ucs086

#include <bits/stdc++.h>
using namespace std;

// Merge Function for merge sorting
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[m + 1 + j];


    int i = 0,j=0,k=l;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// 1) MergeSort
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


//Function of QuickSort
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


// 2) Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

//Function to random pivot to randomized QuickSort
int partition_random(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}

// 3) Randomized Quick Sort
void Randomized_quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition_random(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


// 4) Heap Data Structure
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
// 5) Heap Sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}

// 6) Count Sort 
void CountSort(int arr[], int n)
{
	int k = INT_MIN;	
	for(int i=0;i<n;i++)
	{
		k = max(k,arr[i]);
	}

	int cnt[k+1]={0},b[n];
	for(int i=0;i<n;i++)
		cnt[arr[i]]++;
	for(int i=1;i<=k;i++)
		cnt[i]+=cnt[i-1];

	for(int i=n-1;i>=0;i--)
	{
		b[--cnt[arr[i]]] = arr[i];
	}
	for(int i=0;i<n;i++)
		arr[i] = b[i];

}

//Count Sort For Radix Sort
void CountSortForRadix(int arr[], int n, int p)
{

	int cnt[11]={0},b[n];
	for(int i=0;i<n;i++)
		cnt[(arr[i]/p)%10]++;
	for(int i=1;i<=9;i++)
		cnt[i]+=cnt[i-1];

	for(int i=n-1;i>=0;i--)
	{
		b[--cnt[(arr[i]/p)%10]] = arr[i];
	}
	for(int i=0;i<n;i++)
		arr[i] = b[i];

}
// Max Function for Radix Sort
int getMax(int arr[],int n)
{
	int k = INT_MIN;
	for(int i=0;i<n;i++)
	{
		k = max(k,arr[i]);
	}
	return k;
}
// 7) Radix Sort
void RadixSort(int arr[],int n)
{
	int max_key = getMax(arr,n);
	for(int p=1;max_key/p>0;p*=10)
		CountSortForRadix(arr,n,p);
}


// 8) Print Sort
void BucketSort(float arr[], int n)
{
    vector<float> b[n];


    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];

}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<'\n';

}

int main()
{
	
	int arr[] = {7,8,2,5,4,6,3,1}; // Sample array to be sorted

	int n = *(&arr + 1) - arr;
	cout<<"Original Array : ";
    print(arr,n);

    mergeSort(arr,0,n-1);
    cout<<"MergeSort : => ";
    print(arr,n);
    cout<<endl;

    quickSort(arr,0,n-1);
    cout<<"QuickSort : => ";
    print(arr,n);
    cout<<endl;

    Randomized_quickSort(arr,0,n-1);
    cout<<"Randomized QuickSort : => ";
    print(arr,n);
    cout<<endl;

    heapSort(arr,n);
    cout<<"HeapSort : => ";
    print(arr,n);
    cout<<endl;

    CountSort(arr,n);
    cout<<"CountSort : => ";
    print(arr,n);
    cout<<endl;

    RadixSort(arr,n);
    cout<<"RadixSort : => ";
    print(arr,n);
    cout<<"\n\n";

    float arr1[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    n = *(&arr1 + 1) - arr1;
    cout<<"Original Array : ";
    for(int i=0;i<n;i++)
    	cout<<arr1[i]<<" ";

    BucketSort(arr1,n);
    cout<<endl;

    cout<<"\nABucketSort : => ";
    for(int i=0;i<n;i++)
    	cout<<arr1[i]<<" ";
    cout<<endl;


}
