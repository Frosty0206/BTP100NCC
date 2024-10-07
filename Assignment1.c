#include <stdio.h>

void Housing();
void Transportation();
void Both();

int main() {
    int choice;
    
    do {
        // Display menu
        printf("Choose an option:\n");
        printf("1. Housing\n");
        printf("2. Transportation\n");
        printf("3. Housing and Transportation\n");
        printf("0. Exit\n");
        printf("Enter your choice (0, 1, 2, or 3): ");
        
        scanf("%d", &choice);
        
        // Use switch to handle choices
        switch (choice) {
            case 1:
                Housing();
            case 2:
                Transportation();
            case 3:
                Both();
            case 0:
                printf("Exiting the program.\n");
                choice == 1;
            default:
                printf("Invalid choice! Please enter 0, 1, 2, or 3.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void Housing() {
    printf("Calculating carbon footprint for Housing\n");

}

void Transportation() {
    printf("Calculating carbon footprint for Transportation\n");

}

void Both() {
    printf("Calculating carbon footprint for both Housing and Transportation\n");

}
