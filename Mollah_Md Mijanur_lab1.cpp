#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int num);
void mergeSort(int arr[], int left, int right);
void mergeSort(int arr[], int left, int mid, int right);
void mergeSort2(int arr[], int left, int right);

int main(void){
    int num;
    cin >> num;
    int arr[num];
    int arr1[num];
    for (int i = 0; i < num; i++){
        int rval = rand() % (1 + 4*num - 1) - 1;
        arr[i] = rval;
        arr1[i] = rval;
    }
    auto s1 = high_resolution_clock::now();
    mergeSort(arr, 0, num);
    auto s2 = high_resolution_clock::now();
    auto time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for mergeSort";
    cout << endl;
    s1 = high_resolution_clock::now();
	selectionSort(arr1, num);
	s2 = high_resolution_clock::now();
	time = duration_cast<microseconds> (s2 - s1);
	cout << time.count() << " microseconds for selectionSort";
	cout << endl;
	s1 = high_resolution_clock::now();
    mergeSort2(arr1, 0, num);
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for selectionSort inside mergeSort";
	cout << endl;
	cout << "The values of n I have used are 5, 10, 50, 100, 500, 1000";
	cout << endl;
	cout << "And have come to notice that even when n was 100 mergeSort took more time than selectionSort but the when n was 100 selectionSort was took a lot more time than mergeSort";
	cout << endl;
	cout << "And when n was 1000 the gap only widened between mergeSort and selectionSort with selectionSort taking a lot more time to run.";
	cout << endl;
    cout << "After experimenting for the same value of n the time of the combination of the sorts was closer to mergeSort until n = 100"; 
    cout << "and from n = 500 and so on the values were closer to selectionSort";
    return 0;
}

void selectionSort(int arr[], int num) 
{
    if (num <= 1)
    return;
    
    int p = 0;
    int max = arr[0];
    for (int i = 1; i < num; i++) {
        if (arr[i] > max)
        {
        p = i;
        max = arr[i];
        }
    }
    
    int temp = arr[num-1];
    arr[num-1] = max;
    arr[p] = temp;
    
    selectionSort(arr, num-1);
}

 
void merge(int arr[], int s, int m, int e) 
{ 
	int fh = m - s + 1; 
	int sh = e - m; 

	int LeftArr[fh], RightArr[sh]; 

	for (int i = 0; i < fh; i++) {
		LeftArr[i] = arr[s + i]; 
	}
	for (int i = 0; i < sh; i++) {
		RightArr[i] = arr[m + i + 1]; 
    } 
	
	int c = s; 
	int a = 0; 
	int b = 0; 
	
	while (a < fh && b < sh) 
	{ 
		if (LeftArr[a] <= RightArr[b]) 
		{ 
			arr[c] = LeftArr[a]; 
			a++; 
		} 
		else
		{ 
			arr[c] = RightArr[b]; 
			b++; 
		} 
		c++; 
	} 

	while (a < fh) 
	{ 
		arr[c] = LeftArr[a]; 
		a++; 
		c++; 
	} 

	while (b < sh) 
	{ 
		arr[c] = RightArr[b]; 
		b++; 
		c++; 
	} 
} 


void mergeSort(int arr[], int s, int e) 
{ 
	if (s < e) 
	{ 
		int m = (s+e)/2; 
		mergeSort(arr, s, m); 
		mergeSort(arr, m+1, e); 
		merge(arr, s, m, e); 
	} 
} 


void mergeSort2(int arr[], int s, int e) 
{ 
	if (s < e) 
	{ 
		int m = (s+e)/2; 
		mergeSort(arr, s, m); 
		mergeSort(arr, m+1, e); 
		selectionSort(arr, e); 
	} 
} 