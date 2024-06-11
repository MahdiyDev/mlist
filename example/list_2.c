#include <stdio.h>

#include "../list.h"

typedef struct ListItem ListItem;

typedef struct ListItem {
    int value;
    ListItem* next;
} ListItem;

typedef struct {
    int length;
    ListItem* head;
} List;

int main(int argc, char** argv)
{
    List* list;
    create_list(list);

    for (int i = 0; i < 10; i++) {
        list_push(list, (ListItem) { .value = i });
        if (i == 5) {
            list_insert_after(list, list->head, (ListItem) { .value = 47 });
        }
    }

    ListItem* currentItem = list->head;
    for (int i = 0; i < list->length; i++) {
        printf("%d", currentItem->value);
        if (currentItem->next) {
            printf(" -> ");
            currentItem = currentItem->next;
        } else {
            printf(" -> NULL");
        }
    }
    printf("\n");

    free_list(list);

    return 0;
}