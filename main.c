/*
 * main.c
 *
 *  Created on: 6 de mar de 2017
 *      Author: clecius
 */
#include <stdio.h>
#include <unistd.h>

const int h = 10;
const int w = 100;
void clear() {
	for (int i = 0; i < 100; i++) {
		printf("\n");
	}
}
int main() {
	int matrix[h][w];
	int* idx[h];
	/*Fill Matrix with zeros*/
	for (int ih = 0; ih < h; ih++) {
		idx[ih] = &matrix[ih];
		for (int iw = 0; iw < w; iw++) {
			matrix[ih][iw] = ih < 8 ? 0 : 1;
		}
	}

	for (int step = 0; step < 20; step++) {
		clear();
		/*Print Matrix*/
		printf("Step[%d]\n", step);
		for (int ih = 0; ih < h; ih++) {
			for (int iw = 0; iw < w; iw++) {
				printf("%d", idx[ih][iw]);
			}
			printf("\n");
		}

		/*Move*/
		int* tmp = idx[0];
		for (int i = 1; i < h; i++) {
			idx[i - 1] = idx[i];
		}
		idx[h-1] = tmp;

		sleep(1);
	}
	return (1);
}

