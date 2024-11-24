#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_STRING_LENGTH 50

// Define the Employee structure
typedef struct {
    int employeeID;
    char name[MAX_STRING_LENGTH];
    char gender[MAX_STRING_LENGTH];
    char ethnicity[MAX_STRING_LENGTH];
    float salary;
} Employee;

// Function to input employee data
void inputEmployeeData(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Maximum employee capacity reached.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &employees[*count].employeeID);
    getchar();  // Clear newline character

    printf("Enter Name: ");
    fgets(employees[*count].name, MAX_STRING_LENGTH, stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';  // Remove newline

    printf("Enter Gender (male/female/non-binary): ");
    fgets(employees[*count].gender, MAX_STRING_LENGTH, stdin);
    employees[*count].gender[strcspn(employees[*count].gender, "\n")] = '\0';

    printf("Enter Ethnicity: ");
    fgets(employees[*count].ethnicity, MAX_STRING_LENGTH, stdin);
    employees[*count].ethnicity[strcspn(employees[*count].ethnicity, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &employees[*count].salary);

    (*count)++;
}

// Function to calculate average salaries based on criteria
float calculateAverageSalary(Employee employees[], int count, const char *criteria, const char *value) {
    float totalSalary = 0.0;
    int matches = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(criteria, "gender") == 0 && strcmp(employees[i].gender, value) == 0) {
            totalSalary += employees[i].salary;
            matches++;
        } else if (strcmp(criteria, "ethnicity") == 0 && strcmp(employees[i].ethnicity, value) == 0) {
            totalSalary += employees[i].salary;
            matches++;
        }
    }

    return (matches > 0) ? totalSalary / matches : 0.0;
}

// Function to display comparison results
void displayComparisonResults(Employee employees[], int count) {
    float companyMaleAvg = calculateAverageSalary(employees, count, "gender", "male");
    float companyFemaleAvg = calculateAverageSalary(employees, count, "gender", "female");

    // Replace these with actual Canadian average values
    float canadianMaleAvg = 64000.0;
    float canadianFemaleAvg = 45800.0;

    printf("\nComparison of Average Salaries:\n");
    printf("Males: Company = %.2f, Canadian Average = %.2f\n", companyMaleAvg, canadianMaleAvg);
    printf("Females: Company = %.2f, Canadian Average = %.2f\n", companyFemaleAvg, canadianFemaleAvg);
}

// Main function
int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Employee Data\n");
        printf("2. Calculate and Compare Salaries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputEmployeeData(employees, &count);
                break;
            case 2:
                displayComparisonResults(employees, count);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
