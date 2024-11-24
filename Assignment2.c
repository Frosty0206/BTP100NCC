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

        if (strcasecmp(employees[*count].gender, "male") == 0 ||
            strcasecmp(employees[*count].gender, "female") == 0 ||
            strcasecmp(employees[*count].gender, "non-binary") == 0) {
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

        if (strcasecmp(employees[*count].ethnicity, "BIPOC") == 0 ||
            strcasecmp(employees[*count].ethnicity, "Non-BIPOC") == 0) {
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
    float totalSalary = 0.0F;
    int matches = 0;

    for (int i = 0; i < count; i++) {
        if (strcasecmp(criteria, "gender") == 0 && strcasecmp(employees[i].gender, value) == 0) {
            totalSalary += employees[i].salary;
            matches++;
        } else if (strcasecmp(criteria, "ethnicity") == 0 && strcasecmp(employees[i].ethnicity, value) == 0) {
            totalSalary += employees[i].salary;
            matches++;
        }
    }

    return (matches > 0) ? totalSalary / matches : 0.0;
}

// Function to display comparison results
void displayComparisonResults(Employee employees[], int count) {
    
    // Average Salaries for Companies
    float companyAvgSalaries[5] = {
        calculateAverageSalary(employees, count, "gender", "male"),        // Company Male Average Salary ------- Index 0
        calculateAverageSalary(employees, count, "gender", "female"),      // Company Female Average Salary ----- Index 1 
        calculateAverageSalary(employees, count, "gender", "non-binary"),  // Company Non-Binary Average Salary - Index 2
        calculateAverageSalary(employees, count, "ethnicity", "BIPOC"),    // Company BIPOC Average Salary ------ Index 3
        calculateAverageSalary(employees, count, "ethnicity", "Non-BIPOC") // Company Non-BIPOC Average Salary -- Index 4
    };

    // Average Salaries for Individuals in Canada
    float canadianAvgSalaries[5] = {
        64000.0F, // Canadian Male Average Salary ------- Index 0
        45800.0F, // Canadian Female Average Salary ----- Index 1 
        36270.0F, // Canadian Non-Binary Average Salary - Index 2
        45700.0F, // Canadian BIPOC Average Salary ------ Index 3
        54100.0F  // Canadian Non-BIPOC Average Salary -- Index 4
    };

    printf("\nComparison of Average Salaries:\n");

    printf("\nGender:\n");
    printf("Males: Company = %.2f, Canadian Average = %.2f - %s\n", companyAvgSalaries[0], canadianAvgSalaries[0], 
    (companyAvgSalaries[0] < canadianAvgSalaries[0]) ? "Less than the average" : "More than the average");
    printf("Females: Company = %.2f, Canadian Average = %.2f - %s\n", companyAvgSalaries[1], canadianAvgSalaries[1], 
    (companyAvgSalaries[1] < canadianAvgSalaries[1]) ? "Less than the average" : "More than the average");
    printf("Non-Binary: Company = %.2f, Canadian Average = %.2f - %s\n",  companyAvgSalaries[2], canadianAvgSalaries[2], 
    (companyAvgSalaries[2] < canadianAvgSalaries[2]) ? "Less than the average" : "More than the average");

    printf("\nEthnicity:\n");
    printf("BIPOC: Company = %.2f, Canadian Average = %.2f - %s\n", companyAvgSalaries[3], canadianAvgSalaries[3], 
    (companyAvgSalaries[3] < canadianAvgSalaries[3]) ? "Less than the average" : "More than the average");
    printf("Non-BIPOC: Company = %.2f, Canadian Average = %.2f - %s\n", companyAvgSalaries[4], canadianAvgSalaries[4], 
    (companyAvgSalaries[4] < canadianAvgSalaries[4]) ? "Less than the average" : "More than the average");
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
