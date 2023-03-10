/*
 * main.c
 *
 *  Created on: 6 de mar de 2017
 *      Author: clecius
 */
#include <stdio.h>
#include <unistd.h>

const int h = 40;
const int w = 100;
const int fh = 5;
const int fw = 3;

void clear() {
	for (int i = 0; i < 100; i++) {
		printf("\n");
	}
}
int point(int ih, int iw) {
	if (ih > (h - 1 - fh)) {
		int fhi = fw - (h - ih);
		int med = w / 2;
		int lbound = med - fw - fhi;
		int rbound = med + fw + fhi;
		return iw > lbound && iw < rbound ? 1 : 0;
	}
	return 0;
}

int main() {
	int matrix[h][w];
	int *idx[h];
	/*Fill Matrix with zeros*/
	for (int ih = 0; ih < h; ih++) {
		idx[ih] = &matrix[ih];
		for (int iw = 0; iw < w; iw++) {
			matrix[ih][iw] = point(ih, iw);
		}
	}
	int iterations = ((h * 2) + fh);
	for (int step = 0; step < iterations; step++) {
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
		idx[h - 1] = tmp;
		usleep((step > iterations ? 1 : iterations - step) * 1000);
	}
	return (1);
}

