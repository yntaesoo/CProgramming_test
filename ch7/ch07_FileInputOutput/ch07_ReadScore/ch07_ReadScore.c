
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STUDENTS 1000
#define MAX_NAME_LEN 100

// Struct for student information
typedef struct {
	char reg_no[20];
	char name[MAX_NAME_LEN];
	int kor, eng, math;
	int total;
	float average;
	char grade;
} Student;

void print_students(FILE* fp, Student students[], int n);

int main(int argc, int* argv[])
{
	FILE* input_file, * output_file;

	input_file = fopen(argv[1], "r");
	if (!input_file) {
		printf("Error opening input file.\n");
		return 1;
	}

	Student students[MAX_STUDENTS] = { 0 };  // All elements initialized to 0
	int count = 0;

	// Reading student information from input file
	int tag = 1;
	while (tag) {
		if (fscanf(input_file, "%s\t%s\t%d\t%d\t%d", students[count].reg_no, students[count].name,
			&students[count].kor, &students[count].eng, &students[count].math) == EOF)
			tag = 0; 
		count++;
	}
	//while (fscanf(input_file, "%s\t%s\t%d\t%d\t%d", students[count].reg_no, students[count].name,
	//	&students[count].kor, &students[count].eng, &students[count].math) != EOF) {
	//	
	//	count++;
	//}
	fclose(input_file);

	output_file = fopen(argv[2], "w");
	if (!output_file) {
		printf("Error opening output file.\n");
		fclose(input_file);
		return 1;
	}
	print_students(output_file, students, count);

	fclose(output_file);
}

// Function to print student data to file
void print_students(FILE* fp, Student students[], int n) {
	fprintf(fp, "Reg No\tName\tKOR\tENG\tMATH\tTotal\tAverage\tGrade\n");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%.2f\t%c\n", students[i].reg_no, students[i].name,
			students[i].kor, students[i].eng, students[i].math,
			students[i].total, students[i].average, students[i].grade);
	}
}
