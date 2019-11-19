
#include<iostream>
#include <random>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //QuickSort(nums,0,n-1);
        //heapSort(nums);
        //mergeSort(nums);
        shellSort(nums);
        return nums;
    }
    //快速排序
    void QuickSort(vector<int>& arr,int L,int R){
        if(L<R) {
            int random = rand() % (R -L + 1);
            swap(arr[L + random], arr[R]);
            vector <int> p = partition(arr, L, R);
            QuickSort(arr, L, p[0] - 1);
            QuickSort(arr, p[1] + 1, R);
         }
    }
    vector<int> partition(vector<int>& arr,int L,int R){
        int less = L - 1;
        int more = R;
        int index = L;
        while (index < more){
            if (arr[index] < arr[R]){
                swap(arr[index++], arr[++less]);
            }
            else if (arr[index] == arr[R]){
                index++;
            }
            else{
                swap(arr[index], arr[--more]);
            }
        }
        swap(arr[more], arr[R]);
        vector<int> a = {less + 1, more};
        return a;
    } 
    //堆排序
    void heapSort(vector<int>& arr) {
    //构造大根堆
    heapInsert(arr);
    int size = arr.size();
    while (size > 1) {
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(arr,0,size);
        } 
    }
    void heapInsert(vector <int>& arr){
        int size = arr.size();
        for (int i = 0;i < size; i++){
            int currentindex = i;
            int fatherindex = (currentindex  - 1)/2;
            while (arr[currentindex] > arr[fatherindex]){
                swap(arr[currentindex], arr[fatherindex]);
                currentindex = fatherindex;
                fatherindex = (currentindex - 1)/2;
            }
        }
    }
    void heapify (vector <int>& arr, int index, int size){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        while (left < size){
            int largestindex;
            if (arr[left] < arr[right] && right < size){
                largestindex = right;
            }
            else{
                largestindex = left;
            }
            if (arr[index] > arr[largestindex]) {
            largestindex = index;
            }
            if (index == largestindex){
                break;
            }
            swap(arr[largestindex], arr[index]);
            index = largestindex;
            left = 2 * index + 1;
            right = 2 * index + 2;
        }
    }
    //归并排序
    void mergeSort(vector<int>& arr) {
        if (arr.size() < 2) {
            return;
        }
        mergeSort(arr, 0, arr.size() - 1);
    }
    void mergeSort(vector<int>& arr, int L, int R) {
        if (L == R) {
            return;
        }
        int mid = (L + R) / 2;
        //将数组左侧全部排成有序
        mergeSort(arr, L, mid);//T(N/2)
        //将数组右侧全部排成有序
        mergeSort(arr, mid + 1, R);//T(N/2)
        merge(arr, L, mid, R);//O(N):因为N个数的话，需要依次扫过去
    }
    void merge(vector<int>& arr, int L, int mid, int R) {
        //开辟一个临时数组，用来存放归并过程中的排好序的元素
        vector<int> help(R - L + 1);
        //临时数组的索引
        int i = 0;
        int p1 = L;
        int p2 = mid + 1;
        while (p1 <= mid && p2 <= R) {
            if (arr[p1] <= arr[p2]) {
                help[i] = arr[p1];
                i++;
                p1++;
            } 
            else {
                help[i] = arr[p2];
                i++;
                p2++;
            }
        }
        while (p1 <= mid) {
            help[i] = arr[p1];
            i++;
            p1++;
        }
        //上面的while循环和下面的while循环只会执行一个
        while (p2 <= R) {
            help[i] = arr[p2];
            i++;
            p2++;
        }
        for (int j = 0; j < help.size(); j++) {
            // 这里要用arr[L+j]接受，因为每次进来归并排序的数组起始索引是L，长度是help的长度
            arr[L + j] = help[j];
        }
    }
    //希尔排序
    void shellSort(vector<int>& nums) {
        for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < nums.size(); ++i) {
                for (int j = i; j - gap >= 0 && nums[j - gap] > nums[j]; j -= gap) {
                    swap(nums[j - gap], nums[j]);
                }
            }
        }
    }
    // 冒泡排序 
    void bubbleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
    //插入排序
    void insertSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j - 1 >= 0 && nums[j - 1] > nums[j]; --j) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
    
    // 选择排序 超时
    void selectSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int min_ind = i;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] < nums[min_ind]) {
                    min_ind = j;
                }
            }
            swap(nums[i], nums[min_ind]);
        }
    }


};

