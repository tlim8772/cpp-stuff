#include <bits/stdc++.h>
#include <omp.h>
#include "time.cpp"
using namespace std;

void merge(vector<int>& arr, int s1, int e1, int s2, int e2) {
    int s = s1;
    vector<int> temp;
    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] < arr[s2]) {
            temp.push_back(arr[s1]);
            s1 ++;
        } else {
            temp.push_back(arr[s2]);
            s2 ++;
        }
    }

    if (s1 <= e1) temp.insert(temp.end(), arr.begin() + s1, arr.begin() + e1 + 1);
    if (s2 <= e2) temp.insert(temp.end(), arr.begin() + s2, arr.begin() + e2 + 1);

    for (int i = s; i <= e2; i ++) {
        arr[i] = temp[i - s];
    }
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s == e) return;

    int m = (s + e) >> 1;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);
    merge(arr, s, m, m + 1, e);
}

// get resource unavailable
// to mitigate, stop creating threads when size of arr to sort is small
void parallelMergeSort(vector<int>& arr, int s, int e) {
    if (s == e) return;
    else if (e - s + 1 <= 500) {
        mergeSort(arr, s, e);
        return;
    }

    int m = (s + e) >> 1;

    //thread t1([&arr] (int s1, int e1) {parallelMergeSort(arr, s1, e1);}, s, m);
    // need ref, as all args passed into thread is moved or copied by value
    // if function needs ref type, use ref(arg)
    thread t1(parallelMergeSort, ref(arr), s, m);
    parallelMergeSort(arr, m + 1 , e);
    t1.join();
    
    merge(arr, s, m, m + 1, e);
}



void ompMergeSort(vector<int>& arr, int s, int e) {
    if (s == e) return;
    else if (e - s + 1 <= 500) {
        mergeSort(arr, s, e);
        return;
    }
    
    int m = (s + e) >> 1;

    #pragma omp parallel
    {
        #pragma omp single // only 1 thread add the task to the task pool
        {
            #pragma omp task
            ompMergeSort(arr, s, m);

            #pragma omp task
            ompMergeSort(arr, m + 1, e);
        }
    } 
    // no need for taskwait, as at the end of omp parallel, there is a implicit barrier.
    // only need taskwait if you need the task to end, inside the task itself
        
    merge(arr, s, m, m + 1, e);
}

bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i ++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

void test(function<void(vector<int>&,int,int)> sorter, int sz) {
    vector<int> arr;
    for (int i = sz - 1; i >= 0; i --) arr.push_back(i);

    Clock c;
    c.start();
    sorter(arr, 0, arr.size() - 1);
    c.end();

    cout << c.time() << endl;

    if (!isSorted(arr)) cout << "not sorted" << endl;
}



int main() {

    
    //test(mergeSort, 1e6);
    test(ompMergeSort, 1e6);
    //test(parallelMergeSort, 1e6);

}