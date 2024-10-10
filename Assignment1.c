#include <stdio.h> // A standard input/output library

// Specifies a function that doesn't return any value
void Housing();
void Transportation();
void Both();

int main() {
    int choice;
    
    do {
        // Show the options for the user to pick
        printf("Pick one of these options:\n");
        printf("1. Housing\n");
        printf("2. Transportation\n");
        printf("3. Both Housing and Transportation\n");
        printf("0. Exit\n");
        printf("Your choice (0, 1, 2, or 3): ");
        
        scanf("%d", &choice);
        
        // Handle what the user picks
        if (choice == 1) {
            Housing();
            choice = -1;  // Reset to keep the loop going
        } else if (choice == 2) {
            Transportation();
            choice = -1;  // Reset to keep the loop going
        } else if (choice == 3) {
            Both();
            choice = -1;  // Reset to keep the loop going
        } else if (choice == 0) {
            printf("Alright, exiting the program.\n");
        } else {
            printf("Whoops! Please enter 0, 1, 2, or 3.\n");
            choice = -1;  // Reset to keep the loop going
        }
    } while (choice != 0);

    return 0;
}

// TASK 1: EVAN FROST
void Housing() { 
    double kwh_per_month, energy_emissions;
    // Ask the user for monthly electricity use
    printf("What's your average monthly electricity usage in kWh? ");
    scanf("%lf", &kwh_per_month);

    // Calculate emissions from electricity usage
    energy_emissions = (kwh_per_month / 30) * 0.417;
    printf("Your daily carbon emissions from electricity are: %.2f kg CO2\n", energy_emissions);
}

// TASK 2: EVAN FROST
void Transportation() {
    int transport_method;
    double miles_per_day, emission_factor, emissions;

    // Ask the user to pick their transportation method
    printf("How do you get around?\n");
    printf("1. Gasoline-powered vehicle\n");
    printf("2. Electric car\n");
    printf("3. Hybrid car\n");
    printf("4. Walks, bikes, or public transit\n");
    printf("Your choice (1, 2, 3, or 4): ");
    scanf("%d", &transport_method);

    // Set emission factor based on the transportation choice
    if (transport_method == 1) {
        emission_factor = 0.404;  // Gasoline car emissions
    } else if (transport_method == 2) {
        emission_factor = 0.10425;  // Electric car emissions (from power generation)
    } else if (transport_method == 3) {
        emission_factor = 0.404;  // Hybrid car emissions
    } else if (transport_method == 4) {
        emission_factor = 0.0;  // Minimal emissions for walking, biking, or public transit
    } else {
        printf("Hmm, didn't get that. Setting emissions to zero.\n");
        emission_factor = 0.0;
    }

    // Ask for daily mileage
    printf("How many miles do you drive per day? ");
    scanf("%lf", &miles_per_day);

    // Calculate emissions based on daily miles and emission factor
    emissions = miles_per_day * emission_factor;
    printf("Your daily carbon emissions from transportation are: %.2f kg CO2\n", emissions);
}

void Both() {
    // Calculate emissions for both housing and transportation
    Housing();
    Transportation();
}

// TASK 3:
// TASK 4:

// TASK 5: LLOYD DELA CRUZ
// A function to calculate and display the total carbon footprint
void TotalFootprint() {
    double average_canadian_daily = 54.8; // Average carbon footprint per day in Canada (kg CO2)

    // Display the total emissions calculated so far
    printf("\nYour total daily carbon footprint is: %.2f kg CO2\n", total_emissions);

        // Compare user's total emissions with the Canadian average
    if (total_emissions > average_canadian_daily) {
        // If the user's emissions are higher than the national average
        printf("Your carbon footprint is above the Canadian average of 54.8 kg CO2 per day.\n");
        // Tells that the user adopt sustainable practices to reduce emissions
        printf("Consider adopting more sustainable practices.\n");
    } else {
        // If the user's emissions are below the national average
        printf("Your carbon footprint is below the Canadian average. Keep up the good work!\n");
    }

    // Reset the total emissions after displaying for the result, so the user can make a new calculation
    total_emissions = 0;    
}
