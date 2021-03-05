#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

// Two-Sum (Leetcode #1)

vector<int>twoSum(vector<int>& nums, int goal){

    map<int,int> hashmap;
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++) {

        int curr = nums[i];
        int compliment = goal - curr;

        if (hashmap.find(compliment) != hashmap.end()) {

            answer.push_back(hashmap[compliment]);
            answer.push_back(i);
            break;
        }
        hashmap[curr] = i;
    }
    return answer;
}

// Binary Search O(logN)

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
    vector<int> nums = {2,7,11,15};

    int n = sizeof(arr) / sizeof (arr[0]);

    int target = 36;
    int goal = 18;

    vector<int> answer;
    answer = twoSum(nums,goal);

    // [2,7,11,15] --> index: 1,2 == 18
    cout << answer[0] << " " << answer[1] << endl;

    int index = binary_Search(arr,0,n-1,target);

    if (index == -1){
        cout << target << " was not present in the array. ";
    } else {
        cout << target << " was found at index " << index << " in the array.";
    }

    return 0;
}
