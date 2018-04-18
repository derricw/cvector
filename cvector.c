#include<stdio.h>
#include<stdlib.h>


typedef struct {
  size_t size;
  size_t used;
  int *data;
} vector;

void vinit(vector *a, size_t initialSize) {
  a->data = (int *)malloc(initialSize * sizeof(int));
  a->size = initialSize;
  a->used = 0;
}

void vappend(vector *a, int item) {
  if (a->used >= a->size) {
    a->size *= 2;
    a->data = (int *)realloc(a->data, a->size * sizeof(int));
  } 
  a->data[a->used] = item;
  a->used++;
}


void vprint(vector *a) {
  printf("[");
	for (int i=0; i < a->used; i++) {
		printf(" %i", a->data[i]);
		if (i < a->used-1) {
			printf(",");
		}
	}
	printf("]\n");
  printf("size: %lu\n", a->size);
	printf("used: %lu\n", a->used);
}

void vinsert(vector *a, int item, int index) {
  int temp;
	if (index >= a->used) {
		return vappend(a, item);
	}
	if (0 <= index) {
		for (int i=index; i <= a->used; i++) {
			if (i >= a->used) {
				return vappend(a, item);
			}
			temp = a->data[i];
			a->data[i] = item;
			item = temp;
		}
	}
}

void vfree(vector *a) {
  free(a->data);
  a->data = NULL;
  a->used = 0;
  a->size = 0;
}


int main(int argc, char *argv[]) {
  vector v;
  vinit(&v, 2);
  for (int i=0; i<100; i++) {
    vappend(&v, i);
  }
	vprint(&v);
  vinsert(&v, 5, 100);
  vinsert(&v, 5, 0);
	vinsert(&v, 1238098, 5);
	vprint(&v);
	vfree(&v);
}


