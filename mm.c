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

#define FLOAT_TYPE double
#define READ_FLOAT "%lf "

#define MINARGS 4

void write_output(FLOAT_TYPE *matrix, int size)
{
    int i;
    FILE *output;

    if((output = fopen("result.txt","w")) == NULL)
    {
        printf("Cannot write result.txt\n");
    }

    for(i = 0; i < (size * size); i++)
    {
        fprintf(output,"%.2f",*(matrix + i));

        if(i % size - 1 == 0 && i != 0)
            fprintf(output,"\n");
        else
            fprintf(output," ");
    }

    fclose(output);
}

FLOAT_TYPE calcRC(FLOAT_TYPE* matrix1, FLOAT_TYPE* matrix2, int r, int c, int n){
    FLOAT_TYPE result = 0;
    int i, j = 0;

    //build row
    i = r; j = c;
    while(i%n || i == r){
        result += matrix1[i]*matrix2[j];
        printf("Did %d, %d\n",i, j);
        j+=n;
        i++;
    }

    printf("Result for %d, %d is %f\n",r,c,result);
    return result;
}

FLOAT_TYPE *calc(FLOAT_TYPE* matrix1, FLOAT_TYPE* matrix2, int n) {
    FLOAT_TYPE * result;
    int i = 0;
    int r = 0, c = 0; //current row, column
    int stop = n*n;

    result = (FLOAT_TYPE *)malloc(stop*sizeof(FLOAT_TYPE));

    //row = matrix[r+0,+1,+2,...N-1]
    //column = matrix[c, c+n, c+2n, ... ]
    for(i = 0; i < stop; i++){
        printf("Calc %d %d %d\n",r, c, i);
        result[i] = calcRC(matrix1, matrix2, r, c, n);
        c++;                //always increment column
        if(c == n)
        {
            r += n; //increment rows
            c = 0;
        }
    }

    return result;
}

void parse_file(FILE *input, FLOAT_TYPE *data, int size)
{
    int i;
    FLOAT_TYPE temp;

    for(i = 0; i < (size * size);i++)
    {
        if(fscanf(input,READ_FLOAT, &temp) == 0)
        {
            printf("Cannot parse file\n");
            exit(EXIT_FAILURE);
        }
        *(data + i) = temp;
    }
}

int main (int argc, char **argv){

	int Msize = 0;
	FLOAT_TYPE *matrix1;
	FLOAT_TYPE *matrix2;
	FLOAT_TYPE *result;
	FILE *file1, *file2;

	// argument check
	/* 1 : N, 		size of NxN matrix
	 * 2 : file1, 	first matrix
	 * 3 : file2,	second matrix
	 */
	if(argc < MINARGS){
		//not enough args
		printf("usage , mm <N> <file1> <file2>\n");
		exit(EXIT_SUCCESS);
	}

	//Read in input params
	Msize = atoi(argv[1]);

	if((file1 = fopen(argv[2],"r")) == NULL)
	{
	    printf("Cannot open file 1\n");
	    exit(EXIT_FAILURE);
	}

    if((file2 = fopen(argv[3],"r")) == NULL)
    {
        printf("Cannot open file 2\n");
        exit(EXIT_FAILURE);
    }

	matrix1 = (FLOAT_TYPE*)malloc(Msize*Msize*sizeof(FLOAT_TYPE));
	matrix2 = (FLOAT_TYPE*)malloc(Msize*Msize*sizeof(FLOAT_TYPE));
	
	//parse files
	parse_file(file1, matrix1, Msize);
	parse_file(file2, matrix2, Msize);

	//Calculating
	result = calc(matrix1, matrix2, Msize);
	
	//Output
	//write to 'result.out'
	write_output(result, Msize);
	
	return 0;
}
