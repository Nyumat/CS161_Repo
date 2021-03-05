// Use this for leetcode practice in C++.

#include <string>
#include <iostream>

using namespace std;

// Recursive Binary Search is O(logn) because our search is shrinking in half each time.

int binary_Search(int arr[], int left, int right, int target) {

    if (left <= right) {

        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binary_Search(arr,left,right - 1, target);
        if (arr[mid] < target)
            return binary_Search(arr,mid + 1, right, target);

    }
    return -1;
}

int main() {

    int arr[] = {1,4,15,20,22,25,33,36,41};

    int n = sizeof(arr) / sizeof (arr[0]);

    int target = 36;

    int index = binary_Search(arr,0,n-1,target);

    if (index == -1){
        cout << target << " was not present in the array. ";
    } else {
        cout << target << " was found at index " << index << " in the array.";
    }

    return 0;

}
