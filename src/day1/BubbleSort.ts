// sort in place algorithm
// Time complexity: O(n^2)
export default function bubble_sort(arr: number[]): void {
  // iterate through the array
  for(let i = 0; i < arr.length; i++ ) {
    // iterate through the array again but this time compare each element with the next element
    // arr.length - 1 - i is used to account for the indexes we have already seen, and if an array only has 1 item, it is sorted
    // without this optimization we would iterate the already sorted part of the array
    for(let j = 0; j < arr.length - 1 - i; j++) {
      if(arr[j] > arr[j + 1]) {
        const temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  s}
