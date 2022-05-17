// 实现快速排序和归并排序两种算法

// 1. 快速排序
int partition(vector<int>& nums, int left, int right) {
    int pivot = rand() % (right - left + 1) + left;
    swap(nums[left], nums[pivot]);
    int local = left;
    while (left < right) {
        while (left < right && nums[local] <= nums[right]) right--;
        while (left < right && nums[local] >= nums[left]) left++;
        swap(nums[left], nums[right]);
    }
    swap(nums[left], nums[local]);

    return left;
}
void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
}

// 2.归并排序

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    // 合并两个有序数组, [left, mid], [mid + 1, right]
    int p1 = left;
    int p2 = mid + 1;
    int p = 0;
    while (p1 <= mid && p2 <= right) {
        if (nums[p1] < nums[p2]) {
            temp[p] = nums[p1];
            p1++;
        }
        else{
            temp[p] = nums[p2];
            p2++;
        }
        p++;
    }
    while (p1 <= mid) {
        temp[p] = nums[p1];
        p1++;
        p++;
    }
    while (p2 <= right) {
        temp[p] = nums[p2];
        p2++;
        p++;
    }
    for (int i = 0; i < temp.size(); i++) {
        nums[left + i] = temp[i];
    }
}
void mergeSort(vector<int>& nums, int left, int right){
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void print(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "快速排序:" << endl;
    vector<int> nums1 = {1,5,3,2,4,9,6,8,7};
    quickSort(nums1, 0, nums1.size() - 1);
    print(nums1);
    cout << "归并排序:" << endl;
    vector<int> nums2 = {1,5,3,2,4,9,6,8,7};
    mergeSort(nums2, 0, nums2.size() - 1);
    print(nums2);


    return 0;
}