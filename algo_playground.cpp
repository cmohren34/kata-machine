#include <iostream>
#include <cmath>
using namespace std;

// Linear Search
// O(n)
// search every single element in the array from beginning to end
bool linearSearch(int arr[], int size, int n) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == n) return true;
  }
  return false;
}

// Binary Search
// O(log n) , sorted in non-decreasing order
// start in the middle, if we don't find it cut the search area in half
// "int mid = low + (high - low) / 2;" prevents integer overflow
bool binarySearch(int arr[], int size, int n) {
  int low = 0;
  int high = size - 1;

  while(low <= high) {
    int mid = low + (high - low / 2);
    
    if(arr[mid] == n) {
      return true;
    }
    else if(arr[mid] < n) {
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return false;
}

// think about it like we have an array full of falses, when we detect a true we jump back to make sure
// there wasn't one in between our increments
// O(√N)
int twoCrystalBalls(bool breaks[], int size) {
  int jumpAmount = sqrt(size);
  int i = jumpAmount;

  for (; i < size; i += jumpAmount) {
    if(breaks[i] == true) {
      break;
    }
  }

  i -= jumpAmount;
  for(int j = 0; j <= jumpAmount && i < size; ++j, ++i) {
    if (breaks[i] == true){
      return i;
    }
  }

  return -1;
}



// Bubble Sort
// O(n^2)
// start at 0, compare n to n + 1 position, if n greater than n + 1, swap
// The size - 1 - i in the inner loop limits the comparisons on each pass since
// the largest element will be sorted in place after each full array iteration.
void bubbleSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1 - i; j++){

      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

      }
    }
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int rev_arr[] = {1, 10, 4, 5, 11, 12, 22, 3, 1};

  // divide the total size of the array, by the size of 1 element (in bytes)
  int size = sizeof(arr) / sizeof(arr[0]);

  // n is what we are looking for
  int n = 7;
  int n2 = 100;

  std::cout << linearSearch(arr, size, n) << " - Linear Search" << std::endl;
  std::cout << binarySearch(arr, size, n) << " - Binary Search\n" << std::endl;

  std::cout << linearSearch(arr, size, n2) << " - Linear Search (should not contain n)"
            << std::endl;
  std::cout << binarySearch(arr, size, n2) << " - Binary Search (should not contain n)\n"
            << std::endl;

  std::cout << "Before sorting:" << std::endl;
  printArray(rev_arr, size);
  bubbleSort(rev_arr, size);
  std::cout << "\nAfter sorting:" << std::endl;
  printArray(rev_arr, size);

  cout << "\n**testing done**" << endl;

  return 0;
}
