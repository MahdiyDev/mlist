#pragma once

#include <stdlib.h>
#include <assert.h>

#ifndef LIST_ASSERT
	#define LIST_ASSERT assert
#endif
#ifndef LIST_MALLOC
	#define LIST_MALLOC malloc
#endif
#ifndef LIST_FREE
	#define LIST_FREE free
#endif

#define new_item(item) (typeof(item))LIST_MALLOC(sizeof(typeof(item)))

#define list_push(list, item) 												\
	do {																	\
		typeof(item)* new_node = new_item(&item);							\
		LIST_ASSERT(new_node != NULL && "Buy more RAM...");					\
		*new_node = item;													\
		new_node->next = (list)->head;										\
		(list)->head = new_node;											\
		(list)->length++;			 										\
	} while (0)

#define list_insert_after(list, prev, item) 								\
	do {																	\
		LIST_ASSERT(prev != NULL && "prev is NULL");						\
		typeof(item)* new_node = new_item(&item);							\
		*new_node = item;													\
		new_node->next = prev->next;										\
		prev->next = new_node;												\
		(list)->length++;													\
	} while (0)

#define list_append(list, item)												\
	do {																	\
		typeof(item)* new_node = new_item(&item);							\
		LIST_ASSERT(new_node != NULL && "Buy more RAM...");					\
		*new_node = item;													\
		new_node->next = NULL;												\
		if ((list)->head == NULL) {											\
			(list)->head = new_node;										\
		} else {															\
			typeof(item)* current = (list)->head;							\
			while (current->next != NULL) {									\
				current = current->next;									\
			}																\
			current->next = new_node;										\
		}																	\
		(list)->length++;													\
	} while (0)

#define create_list(list)													\
	do {																	\
		list = (typeof(list))LIST_MALLOC(sizeof(typeof(list)));				\
		(list)->length = 0;													\
		(list)->head = NULL;												\
	} while (0)

#define free_list(list) LIST_FREE((list)->head)
