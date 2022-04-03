//define the hash element
typedef struct {
    int key, index;     //number and its index
    UT_hash_handle hh;
} HashElement;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));
    
    //declare an element for start of hashtable
    HashElement *ht = NULL;     //the hash table must be initilised to null
    HashElement *elem, *tmp;    //other elements, tmp needed for freeing
    
    //iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int lookup = target - nums[i];      //the value we need given this num is target - this num
        
        //look for the needed value in the hashtable
        HASH_FIND_INT(ht, &lookup, elem);
        
        //was the lookup value in the hash table?
        if (elem) {
            result[0] = elem->index;  //the first index will always be the hashed element  
            result[1] = i;
            return result;
        }
        
        //otherwise, need to add this value and index to hashtable
        elem = (HashElement*)malloc(sizeof(HashElement));
        elem->key = nums[i];
        elem->index = i;
        HASH_ADD_INT(ht, key, elem);    //key here is name of the key parameter in the struct
    } 
    
    //delete and free items from hashtable
    HASH_ITER(hh, ht, elem, tmp) {
        HASH_DEL(ht,elem);  /* delete it */
        free(elem);            /* free it */
    }
    return result;   
}