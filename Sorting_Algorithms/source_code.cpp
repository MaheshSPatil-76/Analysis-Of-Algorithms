#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include<conio.h>
using namespace std;
#define for0(n) for (int i = 0; i < n; i++)

int ch, ch2, n;
char ch3;
clock_t time_req;
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void merge(int array[], int l, int m, int r) {
  int i, j, k, nl, nr;
  // size of left and right sub-arrays
  nl = m - l + 1;
  nr = r - m;
  int larr[nl], rarr[nr];
  // fill left and right sub-arrays
  for (i = 0; i < nl; i++)
    larr[i] = array[l + i];
  for (j = 0; j < nr; j++)
    rarr[j] = array[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  // marge temp arrays to real array
  while (i < nl && j < nr) {
    if (larr[i] <= rarr[j]) {
      array[k] = larr[i];
      i++;
    } else {
      array[k] = rarr[j];
      j++;
    }
    k++;
  }
  while (i < nl) { // extra element in left array
    array[k] = larr[i];
    i++;
    k++;
  }
  while (j < nr) { // extra element in right array
    array[k] = rarr[j];
    j++;
    k++;
  }
}
void mergeSort(int array[], int l, int r) {
  int m;
  if (l < r) {
    int m = l + (r - l) / 2;
    // Sort first and second arrays
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
  }
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller
    // than it is found. For descending order, change key<array[j] to
    // key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

void allocate() {
  cout << "Enter the no. of elements you want to test with:";
  cin >> n;
  int a[n];
  if (ch3 == 'y') {
    cout << endl << "Enter " << n << " numbers :";
    for (int i = 0; i < n; i++)
      cin >> a[i];
  } else {
    cout << ch2 << endl;
    switch (ch2) {
    case 1:
      for0(n) a[i] = i + 1;
      // cout<<endl;
      break;
    case 2:
      for0(n) a[i] = rand() % (100000);
      // cout<<endl;
      break;
    case 3:
      for0(n) a[i] = n - i;
      //  cout<<endl;
      break;
    default:
      cout << " Invalid choice" << endl;
      allocate();
    }
  }

  switch (ch) {
  case 1:
    time_req = clock();
    selectionSort(a, n);
    time_req = clock() - time_req;
    cout << "Using pow function, it took " << (double)time_req / CLOCKS_PER_SEC
         << " seconds" << endl;
    break;
  case 2:
    time_req = clock();
    insertionSort(a, n);
    time_req = clock() - time_req;
    cout << "Using pow function, it took " << (double)time_req / CLOCKS_PER_SEC
         << " seconds" << endl;
    break;
  case 3:
    time_req = clock();
    quickSort(a, 0, n - 1);
    time_req = clock() - time_req;
    cout << "Using pow function, it took " << (double)time_req / CLOCKS_PER_SEC
         << " seconds" << endl;
    break;
  case 4:
    time_req = clock();
    mergeSort(a, 0, n - 1);
    time_req = clock() - time_req;
    cout << "Using pow function, it took " << (double)time_req / CLOCKS_PER_SEC
         << " seconds" << endl;
    break;
  default:
    cout << "Invalid Choice!!!" << endl;
    // input();
  }
}
void input2() {
  cout << "------------- Case-wise Analysis------------" << endl;
  cout << "        1.Best Case\n        2.Average Case        \n        "
          "3.Worst Case"
       << endl;
  cout << "---------------------------------------------" << endl;
  cout << "Enter your choice:";
  cin >> ch2;
  // ch2=3;
  allocate();
}
void input() {
  // cout << "Do you want to work with manual cases(y/n):";
  // cin >> ch3;
  cout << endl << "------- SORTING TECHNIQUES----------" << endl;
  cout << "        1.Selection sort\n        2.Insertion Sort\n        3.Quick "
          "sort\n        4.Merge Sort "
       << endl;
  cout << "------------------------";
  cout << "\n Enter Your choice:";
  cin >> ch;
  // ch=3;
  input2();
}
int main() {

  // input();
  char s;
  s = 'y';
  // int i = 11;
  while (s == 'y') {
    input();
    cout << "Do you want to Test another cases y/n:";
    cin >> s;
  }
}
