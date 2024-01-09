/**
 * -------------------------------------
 * @file  main.c
 * Lab 4 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-20
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "stack_array.h"
#include "queue_array.h"
#include "queue_array.c"
#define SIZE 128

/**
 * Simple stack testing.
 */
void test_stack(void) {
	char buffer[SIZE];

	stack_struct stack;
	data_type item = 0;

	printf("Initialize stack\n");
	stack_initialize(&stack, data_to_string, data_copy);
	printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(&stack)));
	printf("Stack count: %d\n", stack_count(&stack));
	printf("Add data to stack:\n");
	item = 0;

	while (stack_push(&stack, &item)) {
		// Fill the stack
		printf("  Pushed: %s\n", data_to_string(&item, buffer, SIZE));
		item++;
	}
	printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(&stack)));
	printf("Stack count: %d\n", stack_count(&stack));
	stack_peek(&stack, &item);
	printf("Stack peek: ");
	printf("%s\n", data_to_string(&item, buffer, SIZE));
	printf("\n");
	printf("Contents of stack:\n");
	stack_display(&stack, buffer, SIZE);

	printf("Empty out the stack:\n");

	while (!stack_empty(&stack)) {
		stack_pop(&stack, &item);
		printf("  Popped: %s\n", data_to_string(&item, buffer, SIZE));
	}
	printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(&stack)));
	printf("Stack count: %d\n", stack_count(&stack));

}

/**
 * Simple queue testing.
 */
void test_queue(void) {
	char buffer[SIZE];

	queue_struct queue;
	data_type item = 0;

	printf("Initialize queue\n");
	queue_initialize(&queue, data_to_string, data_copy);
	printf("queue empty: %s\n", BOOL_TO_STR(queue_empty(&queue)));
	printf("queue count: %d\n", queue_count(&queue));
	printf("Add data to queue:\n");
	item = 0;

	while (queue_insert(&queue, &item)) {
		// Fill the queue
		printf("  Inserted: %s\n", data_to_string(&item, buffer, SIZE));
		item++;
	}
	printf("queue empty: %s\n", BOOL_TO_STR(queue_empty(&queue)));
	printf("queue count: %d\n", queue_count(&queue));
	queue_peek(&queue, &item);
	printf("queue peek: ");
	printf("%s\n", data_to_string(&item, buffer, SIZE));
	printf("\n");
	printf("Contents of queue:\n");
	queue_display(&queue, buffer, SIZE);

	printf("Test circularity of queue:\n");
	printf("Remove half the queue:\n");

	for (int i = 0; i < (queue.count / 2); i++) {
		queue_remove(&queue, &item);
		printf("  Removed:%s\n", data_to_string(&item, buffer, SIZE));
	}
	printf("queue count: %d\n", queue_count(&queue));
	printf("Insert half of queue again:\n");
	while (queue_insert(&queue, &item)) {
		// Fill the queue
		printf("  Inserted: %s\n", data_to_string(&item, buffer, SIZE));
		item++;
	}
	printf("queue count: %d\n", queue_count(&queue));
	printf("Contents of queue:\n");
	queue_display(&queue, buffer, SIZE);
	printf("Empty the queue:\n");
	while (!queue_empty(&queue)) {
		queue_remove(&queue, &item);
		printf("  Removed:%s\n", data_to_string(&item, buffer, SIZE));
	}
	printf("queue empty: %s\n", BOOL_TO_STR(queue_empty(&queue)));
	printf("queue count: %d\n", queue_count(&queue));

}

/**
 * Test the file and string functions.
 *
 * @param argc - unused
 * @param args - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	test_stack();
	// test_queue();

	return (EXIT_SUCCESS);
}
