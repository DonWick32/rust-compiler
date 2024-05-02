// use std::io;

// fn main() {
//   int arr[10];
//   int n = 10;

//   quick_sort(arr, 0, n - 1);
//   return;
// }

// fn quick_sort(int arr, int low, int high) {
//     if low < high {
//       int pivot = partition(arr, low, high);
//       quick_sort(arr, low, pivot - 1); // Sort left sub-array
//       quick_sort(arr, pivot + 1, high); // Sort right sub-array
//     }
//   }
  
// fn partition(int arr, int low, int high) {
//     int pivot = arr[high]; // Choose last element as pivot
//     int i = low - 1;
  
//     for j in low..high {
//       if (arr[j] <= pivot) {
//         i++;
//         swap(arr[i], arr[j]);
//       }
//     }
  
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
//   }


fn main() {
  int arr[10];
  int n = 10;

  quicksort();
  return;
}

fn quicksort(int arr, int low, int high) {
    if low < high {
      int pivot = 0;
      partition();
      quicksort(); // Sort left sub-array
      quicksort(); // Sort right sub-array
    }
  }
  
fn partition(int arr, int low, int high) {
    int pivot = arr[low]; // Choose last element as pivot
    int i = low;
  
    for j in (low+1)..high {
      if j < pivot {
        
        i = i + 1;
        int t1 = arr[i];
        int t2 = arr[j];
      }
    }

    int t1 = arr[i];
    int t2 = arr[low];

    i = i + 1;

    return;
  }
  