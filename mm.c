/**
 * 	------------------------
 * 	 CPE458 - Project 1
 *		 Matrix Multiplication
 *		------------------------
 *		Brian C. Danque
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MINARGS 4

int main (int argc, char **argv){
	int Msize = 0;
	float *matrix1;
	float *matrix2;
	float *result;
	int file1, file2;

	// argument check
	/* 1 : N, 		size of NxN matrix
	 * 2 : file1, 	first matrix
	 * 3 : file2,	second matrix
	 */
	if(argc < MINARGS){
		//not enough args
		printf("usage , %s <N> <file1> <file2>\n");
		exit(EXIT_SUCCESS);
	}
	//Get Stuff
	//int Msize = atoi(argv[1]);
	//matrix1 = (float*)malloc(Msize*Msize*sizeof(float));
	//matrix2 = (float*)malloc(Msize*Msize*sizeof(float));
	
	//Open File1,2
	//matrix1 = parseFile(file1);
	//matrix2 = parseFile(file2);	
	
	//Calculating
	//result = calc(matrix1, matrix2);
	
	//Output
	//write to 'result.out'
	
	return 0;
}

//get stuff
//parse files
//float * parseFile(int fp) {}
//calculate

/*float * calc(float* matrix1, float* matrix2, int n) {
	float * result;
	int i,j = 0; //indices for each matrix
	int r, c; //current row, column
	
	//row = matrix[r+0,+1,+2,...N-1]
	//column = matrix[c, c+n, c+2n, ... ]
}*/

//output
/*void output() {
	
}*/