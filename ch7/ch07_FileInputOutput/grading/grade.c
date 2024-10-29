#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Function prototypes
void generate_input_file(const char* filename, int num_students);
void calculate_grade(Student* s);
void print_students(FILE* fp, Student students[], int n);
void search_student(Student students[], int n);

// Sorting algorithms
void quicksort(Student students[], int left, int right);
void bubblesort(Student students[], int n);

// Conditional compilation for sorting
#ifdef USE_QUICKSORT
#define sort_students quicksort
#else
#define sort_students bubblesort
#endif

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <generate_flag>\n", argv[0]);
        return 1;
    }

    // If generate_flag is 1, generate a random input file
    if (atoi(argv[3]) == 1) {
        generate_input_file(argv[1], MAX_STUDENTS);
        printf("Random input file generated: %s\n", argv[1]);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    Student students[MAX_STUDENTS] = { 0 };  // All elements initialized to 0
    int count = 0;

    // Reading student information from input file
    while (fscanf(input_file, "%s\t%s\t%d\t%d\t%d", students[count].reg_no, students[count].name,
        &students[count].kor, &students[count].eng, &students[count].math) != EOF) {
        students[count].total = students[count].kor + students[count].eng + students[count].math;
        students[count].average = students[count].total / 3.0;
        calculate_grade(&students[count]);
        count++;
    }

    fclose(input_file);

    // Sorting and measuring time
    clock_t start = clock();
    sort_students(students, 0, count - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting took %.6f seconds\n", time_taken);

    // Writing sorted student data to output file
    print_students(output_file, students, count);
    fclose(output_file);

    // Search for a student's grade by registration number or name
    search_student(students, count);

    return 0;
}

// Function to generate a random input file
void generate_input_file(const char* filename, int num_students) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error creating input file.\n");
        return;
    }

    const char* first_names[] = { "John", "Jane", "Alice", "Bob", "Chris" };
    const char* last_names[] = { "Doe", "Smith", "Johnson", "Brown", "Davis" };

    srand(time(NULL));  // Seed for random number generation

    for (int i = 0; i < num_students; i++) {
        int rand_kor = rand() % 101;  // Random score between 0 and 100
        int rand_eng = rand() % 101;
        int rand_math = rand() % 101;
        char reg_no[20];
        snprintf(reg_no, sizeof(reg_no), "2023%04d", i);  // Generate registration number

        // Generate random name
        char name[MAX_NAME_LEN];
        snprintf(name, sizeof(name), "%s %s", first_names[rand() % 5], last_names[rand() % 5]);

        // Write to file
        fprintf(fp, "%s\t%s\t%d\t%d\t%d\n", reg_no, name, rand_kor, rand_eng, rand_math);
    }

    fclose(fp);
}

// Function to calculate the grade based on average score
void calculate_grade(Student* s) {
    if (s->average >= 90) {
        s->grade = 'A';
    }
    else if (s->average >= 80) {
        s->grade = 'B';
    }
    else if (s->average >= 70) {
        s->grade = 'C';
    }
    else if (s->average >= 60) {
        s->grade = 'D';
    }
    else {
        s->grade = 'F';
    }
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

// Function to search for a student by registration number or name
void search_student(Student students[], int n) {
    char search_term[20];
    printf("Enter registration number or name to search: ");
    scanf("%s", search_term);

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].reg_no, search_term) == 0 || strcmp(students[i].name, search_term) == 0) {
            printf("Found: %s %s, Total: %d, Average: %.2f, Grade: %c\n",
                students[i].reg_no, students[i].name, students[i].total,
                students[i].average, students[i].grade);
            return;
        }
    }

    printf("Student not found.\n");
}

// Quick sort implementation
void quicksort(Student students[], int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    Student pivot = students[(left + right) / 2];

    while (i <= j) {
        while (students[i].total < pivot.total) i++;
        while (students[j].total > pivot.total) j--;
        if (i <= j) {
            Student temp = students[i];
            students[i] = students[j];
            students[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(students, left, j);
    if (i < right) quicksort(students, i, right);
}

// Bubble sort implementation
void bubblesort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].total > students[j + 1].total) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
