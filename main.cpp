#include <iostream>
#include <vector>

using namespace std;


template<class dataType>
void print (vector<dataType> & vec) {
    for (int i =0 ; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template<class dataType>
void exch(vector<dataType>& collection, int i, int j) {
    dataType temp = collection[i];
    collection[i] = collection[j];
    collection[j] = temp;
}


template<class dataType>
void selectionSort(vector<dataType>& collection) {
    int n = collection.size();
    for (int i = 0; i < n; ++i) {
        int min = i;
        int j = i + 1;
        for (; j < n; ++j) {
            if (collection[j] < collection[min]) {
                min = j;
            }
        }
        exch(collection, i, min);
    }
}

template<class dataType>
void insertionSort(vector<dataType>& collection) {
    int n = collection.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (collection[j] < collection[j -1]) {
                exch(collection, j, j -1);
            } else {
                break;
            }
        }
    }
}

template<class dataType>
void bubbleSort(vector<dataType>& collection) {
    int n = collection.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (collection[j] > collection[j+1]) {
                exch(collection, j, j+1);
            }
        }
    }
}




template<class dataType>
int partition(vector<dataType> &collection, int lo, int hi) {
    int i = lo;         // left indices
    int j = hi + 1;      // right indices
    dataType value = collection[lo];
    while(true) {
        // scan right until you find a larger value
        while (collection[++i] < value) {
            if (i == hi) break;
        }
        // scan left until you find a smaller value
        while (value < collection[--j]) {
            if (j == lo) break;
        }
        // if i <= j we're done
        if (i >= j) break;
        // swap i and j in the list and repeat
        exch(collection, i, j);
    }
    exch(collection, lo, j);
    return j;
}

template<class dataType>
void qSort(vector<dataType> &collection, int lo, int hi) {
    //base case
    if (hi <= lo) { return;}
    //general case
    int j = partition(collection, lo, hi);

    qSort(collection, lo, j - 1);
    qSort(collection, j + 1, hi);
}

template<class dataType>
void quickSort(vector<dataType> &collection) {
    qSort(collection, 0, collection.size() - 1);
}

template<class dataType>
void merge(vector<dataType> &collection, vector<dataType> &aux, int lo, int mid, int hi) {
    int i = lo;
    int j = mid+1;
    // copy the section of collection we're working on.
    for (int k = lo; k <= hi; k++) {
        aux[k] = collection[k];
    }

    for (int k = lo; k <= hi; k++) {
        if (i > mid)                collection[k] = aux[j++];
        else if (j > hi)            collection[k] = aux[i++];
        else if (aux[j] < aux[i])   collection[k] = aux[j++];
        else                        collection[k] = aux[i++];


    }
}

template<class dataType>
void mSort(vector<dataType>& collection, vector<dataType>& aux, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo)/2;
    mSort(collection, aux, lo, mid);
    mSort(collection, aux, mid+1, hi);
    merge(collection, aux, lo, mid, hi);
}

template<class dataType>
void mergeSort(vector<dataType>& collection) {
    vector<dataType> aux(collection);
    mSort(collection, aux, 0, collection.size() - 1);
}







int main() {
    int numbers[] = {39, 3, 38, 46, 29, 18, 19, 16, 43, 19, 41, 27, 44,
                 35, 15, 44, 50, 25, 25, 4, 40, 26, 36, 34, 13};

    vector<int> selection_numbers(numbers, numbers + sizeof(numbers) / sizeof(int));
    print(selection_numbers);
    cout << "Selection Sort:" << endl;
    selectionSort(selection_numbers);
    print(selection_numbers);

    cout << "Insertion Sort:" << endl;
    vector<int> insertion_numbers(numbers, numbers + sizeof(numbers) / sizeof(int));
    insertionSort(insertion_numbers);
    print(insertion_numbers);

    cout << "Bubble Sort:" << endl;
    vector<int> bubble_numbers(numbers, numbers + sizeof(numbers) / sizeof(int));
    bubbleSort(bubble_numbers);
    print(bubble_numbers);

    cout << "Quick Sort:" << endl;
    vector<int> quick_numbers(numbers, numbers + sizeof(numbers) / sizeof(int));
    quickSort(quick_numbers);
    print(quick_numbers);

    cout << "Merge Sort:" << endl;
    vector<int> merge_numbers(numbers, numbers + sizeof(numbers) / sizeof(int));
    mergeSort(merge_numbers);
    print(merge_numbers);

}