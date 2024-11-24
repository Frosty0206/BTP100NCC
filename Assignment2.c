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

    //select valid gender input
    int validGender = 0; // Flag for valid gender input
    while (!validGender) {
        printf("Enter Gender (male/female/non-binary): ");
        fgets(employees[*count].gender, MAX_STRING_LENGTH, stdin);
        employees[*count].gender[strcspn(employees[*count].gender, "\n")] = '\0';

        if (strcmp(employees[*count].gender, "male") == 0 ||
            strcmp(employees[*count].gender, "female") == 0 ||
            strcmp(employees[*count].gender, "non-binary") == 0) {
            validGender = 1; // Set flag to indicate valid input
        } else {
            printf("Invalid gender input. Please enter 'male', 'female', or 'non-binary'.\n");
        }
    }

    int validEthnicity = 0; // Flag for valid ethnicity input
    while (!validEthnicity) {
        printf("Enter Ethnicity (BIPOC/Non-BIPOC): ");
        fgets(employees[*count].ethnicity, MAX_STRING_LENGTH, stdin);
        employees[*count].ethnicity[strcspn(employees[*count].ethnicity, "\n")] = '\0';

        if (strcmp(employees[*count].ethnicity, "BIPOC") == 0 ||
            strcmp(employees[*count].ethnicity, "Non-BIPOC") == 0) {
            validEthnicity = 1; // Set flag to indicate valid input
        } else {
            printf("Invalid ethnicity input. Please enter 'BIPOC' or 'Non-BIPOC'.\n");
        }
    }

    int validSalary = 0; // Flag for valid salary input
    while (!validSalary) {
        printf("Enter Salary: ");
        if (scanf("%f", &employees[*count].salary) != 1) {
            printf("Invalid input. Please enter a valid salary (numeric value).\n");
            while(getchar() != '\n'); // Clear the input buffer
        } else {
            validSalary = 1; // Set flag to indicate valid input
        }
    }

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
    float companyNonBinAvg = calculateAverageSalary(employees,count, "gender", "non-binary");
    
    float companyBIPOCAvg = calculateAverageSalary(employees, count, "ethnicity", "BIPOC");
    float companyNonBIPOCAvg = calculateAverageSalary(employees, count, "ethnicity", "Non-BIPOC");

    // gender and ethnicity average salaries
    float canadianMaleAvg = 64000.0;
    float canadianFemaleAvg = 45800.0;
    float canadianNonBinAvg = 36270.0;

    float canadianBIPOCAvg = 45700.0;
    float canadianNonBipocAvg = 54100.0;

    printf("\nComparison of Average Salaries:\n");

    printf("\n Gender:\n");
    printf("Males: Company = %.2f, Canadian Average = %.2f\n", companyMaleAvg, canadianMaleAvg);
    printf("Females: Company = %.2f, Canadian Average = %.2f\n", companyFemaleAvg, canadianFemaleAvg);
    printf("Non-Binary: Company = %.2f, Canadian Average = %.2f\n", companyNonBinAvg, canadianNonBinAvg);

    printf("\n Ethnicity\n");
    printf("BIPOC: Company = %.2f, Canadian Average = %.2f\n", companyBIPOCAvg, canadianBIPOCAvg);
    printf("BIPOC: Company = %.2f, Canadian Average = %.2f\n", companyNonBIPOCAvg, canadianNonBipocAvg);
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
