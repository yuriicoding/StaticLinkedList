#include "list.h"
#include "stdio.h"
#include "stdlib.h"

void freeItemFromList(void *value)
{
    //Using static memory to test everything, so this function has only testing purpose
    value = 0;
}

bool compareInts (void* value1, void* value2){
    int * first_item = (int *) value1;
    int * second_item = (int *) value2;

    if (*(first_item) == *(second_item)){
        return 1;
    }
    else{
        return 0;
    }
}

bool compareChars (void* value1, void* value2){
    char * first_item = (char *) value1;
    char * second_item = (char *) value2;

    if (*(first_item) == *(second_item)){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {

    printf("\nALL OF THE FOLLOWING TESTS ARE RELATED TO LIST1 ONLY\n");

    printf("\nCreating list list1...\n");
    List* list1 = List_create();

    int * current = (int*)List_curr(list1);
    int * first = (int*)List_first(list1);
    int * last = (int*)List_last(list1);
    int * next = (int*)List_next(list1);
    int * prev = (int*)List_prev(list1);
    int nodes_num = List_count(list1);

    printf("\nCurrent item: %p", (current));
    printf("\nFirst item: %p", (first));
    printf("\nLast item: %p", (last));
    printf("\nNext item: %p", (next));
    printf("\nPrevious item: %p", (prev));
    printf("\nNumber of items: %d\n", nodes_num);


    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};

    printf("\nAdding element 0 to array list1 ...\n");
    List_append(list1, &(arr[0]));
    printf("Address of this element: %p\n", &(arr[0]));

    current = (int*)List_curr(list1);
    first = (int*)List_first(list1);
    next = (int*)List_next(list1);
    prev = (int*)List_prev(list1);
    last = (int*)List_last(list1);
    nodes_num = List_count(list1);

    printf("\nCurrent item: %d", *(current));
    printf("\nFirst item: %d", *(first));
    printf("\nNext item: %p", (next));
    printf("\nPrevious item: %d", *(prev));
    printf("\nLast item: %d", *(last));
    printf("\nNumber of items: %d\n", nodes_num);


    printf("\nAdding 11 elements to list1 from 0 to 10...\n");
    for (int i = 0; i < 11; i++){
        List_append(list1, &(arr[i]));
    }

    printf("\nAdded elements from last to first: \n");
    int * item = (int*)List_curr(list1);
    while (item != 0){
        printf("%d    ", *(item));
        item = (int*)List_prev(list1);
    }

    printf("\n");

    printf("\nRemoving first element...\n");
    List_first(list1);
    int * removed = (int*)List_remove(list1);
    printf("\nRemoved item: %d\n", *(removed));


    printf("\nAdded elements from first to last: \n");
    while (List_curr(list1) != 0){
        int * item = (int*)List_curr(list1);
        printf("%d    ", *(item));
        List_next(list1);
    }

    printf("\n");

    printf("\nTrimming 5 elements... \n");
    for (int i = 0; i < 5; i++){
        List_trim(list1);
    }

    current = (int*)List_curr(list1);
    printf("\nCurrent item: %d\n", *(current));

    printf("\nAdded elements from last to first: \n");
    while (List_curr(list1) != 0){
        int * item = (int*)List_curr(list1);
        printf("%d    ", *(item));
        List_prev(list1);
    }

    printf("\n");


    List_first(list1);
    printf("\nChecking if element 10 is still in list1...\n");
    int check_element = 10;
    int * found = (int*)List_search(list1, compareInts, &(check_element));
    printf("\nFound item: %p\n", (found));
    current = (int*)List_curr(list1);
    printf("\nCurrent item: %p\n", (current));

    List_first(list1);
    List_prev(list1);
    printf("\nChecking if element 3 is still in list1...\n");
    check_element = 3;
    found = (int*)List_search(list1, compareInts, &(check_element));
    printf("\nFound item: %d\n", *(found));
    current = (int*)List_curr(list1);
    printf("\nCurrent item: %d\n", *(current));

    printf("\nInserting 10 after element 3, and then immediately 0 before 10...\n");
    List_insert_after(list1, &(arr[10]));
    List_insert_before(list1, &(arr[0]));

    List_first(list1);
    printf("\nAdded elements from first to last: \n");
    while (List_curr(list1) != 0){
        int * item = (int*)List_curr(list1);
        printf("%d    ", *(item));
        List_next(list1);
    }







    printf("\n\nALL OF THE FOLLOWING TESTS ARE RELATED TO LIST1 AND LIST2\n");

    printf("\nCreating list list2...\n");
    List * list2 = List_create();

    char arr1[] = {'a','b','c','d','e'};
    printf("\nInserting 5 elements in list2...\n");
    for (int i = 0; i < 5; i++){
        List_insert_after(list2, &(arr1[i]));
    }

    List_first(list2);
    printf("\nAdded to list 2 elements from first to last: \n");
    while (List_curr(list2) != 0){
        char * item = (char*)List_curr(list2);
        printf("%c    ", *(item));
        List_next(list2);
    }

    List_first(list2);
    printf("\nChecking if element f is in list2...\n");
    char check_element1 = 'f';
    char * found1 = (char*)List_search(list2, compareChars, &(check_element1));
    printf("\nFound item: %p\n", (found1));
    char* current1 = (char*)List_curr(list2);
    printf("\nCurrent item: %p\n", (current1));

    List_first(list2);
    printf("\nChecking if element e is in list2...\n");
    check_element1 = 'e';
    found1 = (char*)List_search(list2, compareChars, &(check_element1));
    printf("\nFound item: %c\n", *(found1));
    current1 = (char*)List_curr(list2);
    printf("\nCurrent item: %c\n", *(current1));

    printf("\nConcatenating list1 and list2...\n");
    List_concat(list1, list2);

    printf("\nElements from list1 from first to last:\n");
    List_first(list1);
    while (List_curr(list1) != 0){
        int * item = (int*)List_curr(list1);
        printf("%d    ", *(item));
        List_next(list1);
    }

    printf("\nRemoving last 5 elements from list1... \n");
    char first_letter = 'a';
    List_first(list1);
    List_search(list1, compareChars, &(first_letter));
    for (int i = 0; i < 5; i++){
        List_remove(list1);
    }

    printf("\nElements from list1 from first to last:\n");
    List_first(list1);
    while (List_curr(list1) != 0){
        int * item = (int*)List_curr(list1);
        printf("%d    ", *(item));
        List_next(list1);
    }

    printf("\nCreating new empty list list3...\n");
    List * list3 = List_create();
    printf("\nConcatenating list3 and list1...\n");
    List_concat(list3, list1);

    printf("\nElements from list3 from first to last:\n");
    List_first(list3);
    while (List_curr(list3) != 0){
        int * item = (int*)List_curr(list3);
        printf("%d    ", *(item));
        List_next(list3);
    }

    current = (int*)List_curr(list3);
    first = (int*)List_first(list3);
    next = (int*)List_next(list3);
    prev = (int*)List_prev(list3);
    last = (int*)List_last(list3);
    nodes_num = List_count(list3);

    printf("\nCurrent item: %p", (current));
    printf("\nFirst item: %d", *(first));
    printf("\nNext item: %d", *(next));
    printf("\nPrevious item: %d", *(prev));
    printf("\nLast item: %d", *(last));
    printf("\nNumber of items: %d\n", nodes_num);


    printf("\nDeleting list3...\n");
    List_free(list3, freeItemFromList);

    current = (int*)List_curr(list3);
    first = (int*)List_first(list3);
    next = (int*)List_next(list3);
    prev = (int*)List_prev(list3);
    last = (int*)List_last(list3);
    nodes_num = List_count(list3);

    printf("\nCurrent item: %p", (current));
    printf("\nFirst item: %p", (first));
    printf("\nNext item: %p", (next));
    printf("\nPrevious item: %p", (prev));
    printf("\nLast item: %p", (last));
    printf("\nNumber of items: %d\n", nodes_num);

    





    printf("\n\nENDING TESTS DESIGNED TO FILL IN HEADS AND NODES ARRAYS MAXIMALLY\n");
    List * arr_list[20];

    printf("\nChecking that only 10 heads are available...\n");
    for (int i = 0; i < 20; i++){
        arr_list[i] = List_create();
        printf("\nAddress of the list %d: %p\n", i, arr_list[i]);
    }

    printf("\nChecking that only 100 nodes are available...\n");
    int element_to_fill = 10;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 15; j++){
            List_append(arr_list[i], &(element_to_fill));
        }
        printf("\nNumber of nodes in the list %d: %d\n", i, List_count(arr_list[i])); 
    }
   
    return 0;
}
