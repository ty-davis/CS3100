/* file: queue.c
 * Ty Davis
 * CS 3100
 * Dr. Huson
 * This file implements the functions outlined in the queue.h header file
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

queue *createq(void) {
	// initialize new queue
	queue *newQ = (queue *) malloc(sizeof(queue));
	newQ->tail = NULL;
	newQ->head = NULL;
	return newQ;
}

bool enqueue(queue *q, person p) {
	// first check if q exists
	if (q == NULL) {
		printf("Invalid queue object provided to enqueue function.\n");
		return false;
	}

	// allocate memory for the new node
	node *newNode = (node *) malloc(sizeof(node));

	// put a new person onto the queue
	newNode->value = p;

	// manage the next pointer
	newNode->next = NULL;

	// update the queue
	if (q->head == NULL) {
		q->head = newNode;
	} else {
		q->tail->next = newNode;
	}
	q->tail = newNode;
	return true;
}

person dequeue(queue *q) {
	// returns the person at the head of the queue and then removes it from the queue
	person p = {"", 0};

	// Error checking for if q is null or empty
	if (q == NULL) {
		printf("Invalid queue object provided to dequeue object.\n");
		return p;
	} else if (q->head == NULL) {
		printf("Queue object is empty.\n");
		return p;
	}

	// get the person object from the head of the queue
	p = q->head->value;
	// temp node to hold on to before freeing
	node *temp = q->head;
	if (q->head == q->tail) {
		q->head = NULL;
		q->tail = NULL;
	} else {
		q->head = temp->next;
	}

	// free the node
	free(temp);
	return p;
}

bool isemptyqueue(queue *q) {
	// check if the queue is empty or null
	if (q == NULL) {
		printf("Invalid queue object in isemptyqueue.\n");
		return true;
	}
	return (q->head == NULL);
}

bool emptyq(queue *q) {
	// empty the queue and return true if successful
	if (q == NULL) {
		printf("Invalid queue object in emptyq.\n");
	}
	if (isemptyqueue(q)) {
		return false;
	}

	// remove the element at the head until the queue is empty
	while (!isemptyqueue(q)) {
		// dequeue calls free on the node, so no need to do it here
		dequeue(q);
	}
	return true;
}

bool freeq(queue *q) {
	// free the memory allocated for the queue object if it is empty
	if (q == NULL) {
		return true;
	}
	// free if empty
	if (isemptyqueue(q)) {
		free(q);
		return true;
	}
	return false;
}
