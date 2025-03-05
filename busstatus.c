#include <stdio.h>
#include <string.h>


struct Ticket {
    char name[100];
    char destination[100];
    int busStatus;
};

void bookTicket(struct Ticket *ticket) {
    printf("Enter your city");
    fgets(ticket->name, sizeof(ticket->name), stdin);
    ticket->name[strcspn(ticket->name, "\n")] = '\0';

    printf("Enter your destination: ");
    fgets(ticket->destination, sizeof(ticket->destination), stdin);
    ticket->destination[strcspn(ticket->destination, "\n")] = '\0'; 

    
    if (strcmp(ticket->destination, "City A") == 0) {
        ticket->busStatus = 1; 
    } else {
        ticket->busStatus = 0;
    }
}

void displayTicketInfo(struct Ticket ticket) {
    printf("\nTicket Information:\n");
    printf("Name: %s\n", ticket.name);
    printf("Destination: %s\n", ticket.destination);
    
    if (ticket.busStatus == 1) {
        printf("Bus Status: Available\n");
    } else {
        printf("Bus Status: Not Available\n");
    }
}

int main() {
    struct Ticket ticket;

    printf("Bus Ticket Booking System\n");

    
    bookTicket(&ticket);

    
    displayTicketInfo(ticket);

    return 0;
}
