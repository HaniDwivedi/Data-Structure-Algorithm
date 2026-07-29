/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct {
    int key;
    int value;
} HashItem;

int hash(int key) {
    return abs(key) % HASH_SIZE;
}

void insert(HashItem** hashTable, int key, int value) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        index = (index + 1) % HASH_SIZE;
    }
    hashTable[index] = (HashItem*)malloc(sizeof(HashItem));
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int find(HashItem** hashTable, int key) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % HASH_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
int* result=(int*)malloc(2*sizeof(int));
*returnSize=2;
for(int i=0; i<numsSize;i++){
    for(int j=i+1;j<numsSize;j++){
        if(nums[i]+nums[j]==target){
            result[0]=i;
            result[1]=j;
            return result;
        }
    }
}

return NULL;
}
   
