#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate if the input is a number
int isValidNumber(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Invalid number
        }
    }
    return 1; // Valid number
}

// Structure to store bus details
struct Bus {
    char busNumber[10];
    char sourceCity[50];
    char destinationCity[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

// Function to check if available seats are valid
int isValidSeats(int totalSeats, int availableSeats) {
    return (availableSeats <= totalSeats && availableSeats >= 0);
}

int main() {
    struct Bus bus;
    char input[50];
    
    // Get and validate Bus Number
    printf("Enter Bus Number: ");
    scanf("%s", bus.busNumber);

    // Get and validate Source City
    printf("Enter Source City: ");
    scanf("%s", bus.sourceCity);

    // Get and validate Destination City
    printf("Enter Destination City: ");
    scanf("%s", bus.destinationCity);

    // Get and validate Total Seats
    do {
        printf("Enter Total Seats: ");
        scanf("%s", input);
    } while (!isValidNumber(input));
    bus.totalSeats = atoi(input);

    // Get and validate Available Seats
    do {
        printf("Enter Available Seats: ");
        scanf("%s", input);
    } while (!isValidNumber(input));
    bus.availableSeats = atoi(input);
    
    // Validate available seats
    if (!isValidSeats(bus.totalSeats, bus.availableSeats)) {
        printf("Invalid available seats input. Available seats must not exceed total seats.\n");
        return 1;
    }

    // Get and validate Fare
    do {
        printf("Enter Fare: ");
        scanf("%s", input);
    } while (!isValidNumber(input));
    bus.fare = atof(input);

    // Display the bus details
    printf("\nBus Status:\n");
    printf("Bus Number: %s\n", bus.busNumber);
    printf("Source City: %s\n", bus.sourceCity);
    printf("Destination City: %s\n", bus.destinationCity);
    printf("Total Seats: %d\n", bus.totalSeats);
    printf("Available Seats: %d\n", bus.availableSeats);
    printf("Fare: %.2f\n", bus.fare);

    return 0;
}