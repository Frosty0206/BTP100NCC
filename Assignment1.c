#include <stdio.h> // A standard input/output library

double Housing(double kwh_per_month);
double Transportation(double daily_miles);
double Consumption(double weekly_waste);
double CompareToCanadianAverage(double total_emissions);

int main() {
    double miles_per_day = 0.0, kwh_per_month = 0.0, waste_per_week = 0.0;
    double transportation_emissions = 0.0, energy_emissions = 0.0, waste_emissions = 0.0;
    double total_emissions = 0.0;
    
    // Calculate the daily transportation emissions
    transportation_emissions = Transportation(miles_per_day);
    printf("Your daily carbon emissions from transportation are: %.2lf kg CO2\n\n", transportation_emissions);

    // Calculate the daily energy emissions
    energy_emissions = Housing(kwh_per_month);
    printf("Your daily carbon emissions from electricity are: %.2lf kg CO2\n\n", energy_emissions);

    // Calculate the daily waste emissions
    waste_emissions = Consumption(waste_per_week);
    printf("Your daily carbon emissions from waste are %.2lfkg CO2\n\n", waste_emissions);

    // Task 4: Calculate Total Carbon Footprint, John D. Petropoulos
    total_emissions = transportation_emissions + energy_emissions + waste_emissions;

    // Print final output
    CompareToCanadianAverage(total_emissions);

    return 0; // Indicates a successful exit
}

// Task 1: Transportation, Evan Frost
// Asks users what their transportation method is, then calculates their daily
// emissions by multiplying their given daily mileage by an emission factor and
// returns the product
double Transportation(double daily_miles) {
    int transport_method;
    double emission_factor;

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
    scanf("%lf", &daily_miles);

    // Calculate emissions based on daily miles and emission factor
    return daily_miles * emission_factor;
}

// Task 2: Housing, Evan Frost
// Asks users what their monthly electricity usage in kWh is, 
// calculates their daily carbon emissions given that value, 
// and returns the result
double Housing(double kwh_per_month) { 
    // Ask the user for monthly electricity use
    printf("What's your average monthly electricity usage in kWh? ");
    scanf("%lf", &kwh_per_month);

    // Calculate emissions from electricity usage
    return (kwh_per_month / 30) * 0.417;
}

// Task 3: Consumption, John D. Petropoulos
// Asks for the user's weekly generated waste and returns the daily emissions  
double Consumption(double weekly_waste) {
    printf("How much waste do you generate in a week? (lbs): ");
    scanf("%lf", &weekly_waste);
    return (weekly_waste / 7) * 0.24;
}

// Task 5: Comparison with Canadian Average, Lloyd Dela Cruz
// A function to calculate and display the total carbon footprint
double CompareToCanadianAverage(double total_emissions) {
    double average_canadian_daily = 54.8; // Average carbon footprint per day in Canada (kg CO2)

    // Display the total emissions calculated so far
    printf("-------------------------------------------------------------------------\n\n");
    printf("Your total daily carbon footprint is: %.2f kg CO2\n", total_emissions);

        // Compare user's total emissions with the Canadian average
    if (total_emissions > average_canadian_daily) {
        // If the user's emissions are higher than the national average and tells that the user adopt sustainable practices to reduce emissions
        printf("Your carbon footprint is above the Canadian average of 54.8 kg CO2 per day.\nConsider adopting more sustainable practices.\n");
    } else {
        // If the user's emissions are below the national average
        printf("Your carbon footprint is below the Canadian average.\nKeep up the good work!\n");
    }
    // Reset the total emissions after displaying for the result, so the user can make a new calculation
    total_emissions = 0;    
}
