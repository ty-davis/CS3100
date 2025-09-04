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
		printf("Invalid queue object provided to enqueue function.");
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
	person p = {"", 0};

	if (q == NULL) {
		printf("Invalid queue object provided to dequeue object.");
		return p;
	} else if (q->head == NULL) {
		printf("Queue object is empty.");
		return p;
	}

	p = q->head->value;
	node *temp = q->head;
	if (q->head == q->tail) {
		q->head = NULL;
		q->tail = NULL;
	} else {
		q->head = temp->next;
	}

	free(temp);
	return p;
}

bool isemptyqueue(queue *q) {
	if (q == NULL) {
		printf("Invalid queue object in isemptyqueue.");
		return false;
	}
	return (q->head == NULL);
}

bool emptyq(queue *q) {
	if (q == NULL) {
		printf("Invalid queue object in emptyq.");
	}
	if (isemptyqueue(q)) {
		return false;
	}
	node *temp;
	while (q->head != NULL) {
		temp = q->head;
		printf(".\n\n\n\n----- %s -----\n\n\n\n", temp->value.name);
		dequeue(q);
	}
	return true;
}

bool freeq(queue *q) {
	if (q == NULL) {
		return true;
	}
	if (isemptyqueue(q)) {
		free(q);
		return true;
	}
	return false;
}
