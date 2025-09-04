#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void) {
	queue *myq = createq();
	person newPerson = {"Wes Kallgren", 25};
	enqueue(myq, newPerson);
	person ty = {"Ty Davis", 24};
	enqueue(myq, ty);

	person temp = dequeue(myq);
	printf("%s is %d years old.\n", temp.name, temp.age);
	temp = dequeue(myq);
	printf("%s is %d years old.\n", temp.name, temp.age);


	return 0;
}
