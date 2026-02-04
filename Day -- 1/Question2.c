/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; // In case no solution is found
}
int main() {
    int numsSize, target, returnSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    
    if(result != NULL) {
        printf("Indices of the two numbers that add up to %d are: [%d, %d]\n", target, result[0], result[1]);
    } else {
        printf("No two numbers add up to the target.\n");
    }
    
    free(nums);
    free(result);
    return 0;
}