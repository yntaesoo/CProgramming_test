/* Reads each number from an input file and writes it
 * rounded to 2 decimal places on a line of an output file.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE * inp; /* pointer to input file */
	FILE * outp; /* pointer to ouput file */
	double item;
	int input_status; /* status value returned by fscanf */
	 
	/* Prepare files for input or output */
	inp = fopen("indata.txt", "r");
	outp = fopen("outdata.txt", "w");
	
	/* Read each item, format it, and write it */
	input_status = fscanf(inp, "%lf", &item);
	while (input_status == 1) {
		fprintf(outp, "%.2f\n", item);
		input_status = fscanf(inp, "%lf", &item);
	}
	
	/* Close the files */
	fclose(inp);
	fclose(outp);
	
	return (0);
}
