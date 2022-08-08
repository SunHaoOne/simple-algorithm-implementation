#include<iostream>
#include<vector>
using namespace std;

void maxHeap(vector<int>& nums, int start, int end) {
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end) {
		if (son + 1 <= end && nums[son] <= nums[son + 1]) son++;
		if (nums[dad] >= nums[son]) return;
		else {
			swap(nums[son], nums[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
}

void heapSort(vector<int>& nums) {
	int n = nums.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeap(nums, i, n - 1);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		maxHeap(nums, 0, i - 1);
	}
}

int main() {
	vector<int> nums = { 7,4,3,6,3,8,2,1,5 };
	heapSort(nums);
	for (int num : nums) cout << num << " ";
	return 0;
}
