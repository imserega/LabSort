
#include "LabSort.h"

using namespace std;


int main() {
    try {
        if (SIZE_OF_ARRAY > 100000) {
            throw "The Overflow Was Detected";
        }
    }
    catch (const char* exception) {
        cerr << "Error: " << exception << endl;
    }
    SortingAlgos sort;

    double time_result_qs = 0.0;
    for (int i = 0; i < ITERATE_CONST; ++i) {
        
        int arr[SIZE_OF_ARRAY];
        for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
            arr[i] = rand() % SIZE_OF_ARRAY;
        }
        int size = sizeof(arr) / sizeof(arr[0]);
        clock_t begin = clock();
        sort.quickSort(arr, 0, size - 1);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << fixed;
        time_result_qs += elapsed_secs;
    }
    cout << "Average time for QS: " << time_result_qs / ITERATE_CONST;

    cout << endl;

    double time_result_insrt = 0.0;
    for (int i = 0; i < ITERATE_CONST; ++i) {

        int arr[SIZE_OF_ARRAY];
        for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
            arr[i] = rand() % SIZE_OF_ARRAY;
        }
        int size = sizeof(arr) / sizeof(arr[0]);
        clock_t begin = clock();
        sort.insertionSort(arr, size);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << fixed;
        time_result_insrt += elapsed_secs;
    }
    cout << "Average time for INSRT: " << time_result_insrt / ITERATE_CONST;
    

    int array[SIZE_OF_ARRAY];

    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        array[i] = rand() % SIZE_OF_ARRAY;
    }

    //char str[] = "hufhuaHfufwinfa";
    //sort.countSort(str);
    //cout << str << endl;

    /*
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        cout << arr[i] << " ";
    }
    */

    
    
    /*
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        cout << arr[i] << " ";
    }
    */
   // int result = binarySearch(arr, x, 0, size - 1);
    /*
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);

    */
	return 0;
}

int SortingAlgos::binarySearch(int array[], int x, int low, int high) {
    clock_t begin = clock();
    //Iterate until high and low meet
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << fixed << endl;
    cout << "Time required: " << elapsed_secs << endl;

    return -1;
}



void SortingAlgos::insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

//QuickSort Algorithm

void SortingAlgos::swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int SortingAlgos::partition(int array[], int low, int high) {

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void SortingAlgos::quickSort(int array[], int low, int high) {
    if (low < high) {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
    
}

//BogoSorting Algorithm

bool SortingAlgos::isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

void SortingAlgos::shuffle(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
        swap(&a[i], &a[rand() % n]);
}

void SortingAlgos::bogoSort(int a[], int n){
    clock_t begin = clock();

    while (!isSorted(a, n))
        shuffle(a, n);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << fixed << endl;
    cout << "Time required: " << elapsed_secs << endl;
}

//CountSorting Algorithm
void SortingAlgos::countSort(char arr[]){
    cout << "Counting Sort Algorithm for Char:\n";
    clock_t begin = clock();
    char output[RANGE];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << fixed << endl;
    cout << "Time required: " << elapsed_secs;
}


