//
//  main.c
//  sortArithmetic
//
//  Created by wupeng on 2017/4/13.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#include <stdio.h>


/**
 打印数组中的元素
 
 @param arr 数组
 */
void PrintArr(int *arr, int len) {
    int i = 0;
    while (i < len) {
        printf("%d--", arr[i]);
        i++;
    }
    printf("\n");
}


/**
 冒泡排序

 @param arr 数组
 @param len 数组长度
 */
void BubbleSort(int *arr, int len) {
    int i, j, max;
    printf("*****冒泡排序*****\n");
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                max = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = max;
            }
        }
        printf("第%d次内部循环结果为", i + 1);
        PrintArr(arr, len);
        printf("\n");
        
    }
}


/**
 优化的冒泡排序

 @param arr 数组
 @param len 数组长度
 */
void OptimizeBubbleSort(int *arr, int len) {
    //设置标志位，检查在一次遍历的过程中是否有交换，如果没有说明数组位有序
    int exchange = len - 1;
    int max;
    while (exchange != 0) {
        exchange = 0;
        printf("*****优化的冒泡排序*****\n");
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                max = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = max;
                exchange = j;
            }
            printf("第%d次内部循环结果为", j + 1);
            PrintArr(arr, len);
            printf("\n");
        }

    }
}



/**
 选择排序

 @param arr 数组
 @param len 数组长度
 */
void SelectSort(int *arr, int len) {
    int i, j, minOfIndex;
    printf("*****选择排序*****\n");
    for (i = 0; i < len - 1; i++) {
        minOfIndex = i;
        //在无序区查找最小记录
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[minOfIndex]) {
                minOfIndex = j;
            }
        }
        //交换记录
        if (minOfIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minOfIndex];
            arr[minOfIndex] = temp;
        }
        printf("第%d次内部循环结果为", i + 1);
        PrintArr(arr, len);
        printf("\n");
    }
}

/**
 归并排序
 
 @param sourceArr 待排序数组
 @param tempArr 临时数组
 @param startIndex 起始索引
 @param midIndex 中间索引
 @param endIndex 末尾索引
 */
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}


/**
 快速排序
 
 @param arr 数组
 @param left 数组左边left个元素
 @param right 数组右边right个元素
 */
void QuickSort(int *arr, int left, int right) {
    //如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了
    if(left >= right){
        return ;
    }
    int i = left;
    int j = right;
    int key = arr[left];
    /*控制在当组内寻找一遍*/
    while(i < j){
        //而寻找结束的条件就是，
        //1，找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）
        //2，没有符合条件1的，并且i与j的大小没有反转
        while(i < j && key <= arr[j]){
            //向前寻找
            j--;
        }
        //找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        // a[left]，那么就是给key）
        arr[i] = arr[j];
        
        while(i < j && key >= arr[i]){
            //这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
            //因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    PrintArr(arr, 8);
    QuickSort(arr, left, i - 1);//最后用同样的方式对分出来的左边的小组进行同上的做法
    QuickSort(arr, i + 1, right);//用同样的方式对分出来的右边的小组进行同上的做法
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}


/**
 插入排序

 @param arr 数组
 @param n 数组长度
 */
void InsertSort(int*arr, int n) {
    int i,j,temp;
    for(i=1;i<n;i++) {
        temp=*(arr+i);
        //j为要插入的位置
        for(j=i;j>0&&*(arr+j-1)>temp;j--){
            //同时将有序区j以后的数向后移一位
            *(arr+j)=*(arr+j-1);
        }
        //将找到的要插入的位置赋值
        *(arr+j)=temp;
        PrintArr(arr, n);
    }
}


/**
 根据数组array构建大根堆

 @param array 待调整的堆数组
 @param i i是待调整的数组元素的位置
 @param len len是数组的长度
 */
void HeapAdjust(int array[],int i,int len){
    PrintArr(array, len);
    int nChild, nTemp;
    for(;2 * i + 1 < len; i = nChild) {
        //子结点的位置=2*（父结点位置）+1
        nChild = 2 * i + 1;
        //得到子结点中较大的结点
        if(nChild < len-1 && array[nChild+1] > array[nChild]) {
            ++nChild;
        }
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(array[i] < array[nChild]) {
            nTemp = array[i];
            array[i] = array[nChild];
            array[nChild] = nTemp;
        } else break; //否则退出循环
    }
    PrintArr(array, len);
}
//堆排序算法
void HeapSort(int *arr, int len){
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i = len / 2 - 1; i >= 0; --i) {
        HeapAdjust(arr,i,len);
    }
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i = len - 1; i > 0; --i) {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        arr[i] = arr[0]^arr[i];
        arr[0] = arr[0]^arr[i];
        arr[i] = arr[0]^arr[i];
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(arr,0,i);
        PrintArr(arr, len);
    }
}


int main(int argc, const char * argv[]) {

    int len = 8;
    int arr[] = {48, 38, 65, 97, 76, 13, 27, 49};
    int arr1[] = {76, 97, 65, 49};
//    BubbleSort(arr, len);
//    OptimizeBubbleSort(arr, len);
//    SelectSort(arr, len);
    
//    QuickSort(arr, 0, 8);
//    int arr1[8];
//    Merge(arr, arr1, 0, 4, 7);

//    InsertSort(arr, 8);
    
    HeapSort(arr, 8);
    PrintArr(arr, 8); 
    
    
    printf("Hello, World!\n");
    return 0;
}




















































