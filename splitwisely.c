#include <stdio.h>
#include <stdlib.h>


int main() {
    int num_people;
    char newline; // To capture newline character in input buffer

    printf("\n");
    printf( "\n,d88~~\\         888 ,e,   d8                  ,e,                 888        \n"
            "8888    88-~8e  888  \"  _d88_ Y88b    e    /  \"   d88~\\  e88~~8e  888 Y88b  / \n"
            "`Y88b   88  88b 888 888  888   Y88b  d8b  /  888 C888   d888  88b 888  Y888/  \n"
            " `Y88b, 88  888 888 888  888    Y888/Y88b/   888  Y88b  8888__888 888   Y8/   \n"
            "   8888 88  88P 888 888  888     Y8/  Y8/    888   888D Y888    , 888    Y    \n"
            "\\__88P' 88-_8\"  888 888  \"88_/    Y    Y     888 \\_88P   \"88___/  888   /     \n"
            "        88                                                            _/     \n");
    printf("\n");
    printf("                                By Howard C.\n");
    printf("\n");
    printf( "Splitwisely is a bill calculator that takes the amount spent per person as \n"
            "inputs and adds their respective share of the service charge, VAT, and/or \n"
            "any additional fees based on a weighting of spending as a proportion of \n"
            "the total bill. The program asks for three inputs: \n"
            "\n"
            "1. Number of people involved in the bill. \n"
            "2. Amount spent by specific people. \n"
            "3. Service charge, VAT, and/or fees that has been applied to the bill. \n"
            "\n"
            "Inputs (2) and (3) should be positive numbers up to two decimals places. \n"
            "A tabular breakdown is presented at the end showing how much each unique \n"
            "person owes, with the total bill and service charge also displayed. \n");

    char start_program;
    while (1) {
        printf("\nDo you want to start the program? (Y/N): ");
        scanf(" %c", &start_program);

        if (start_program == 'Y' || start_program == 'y') {
            break;
        } else if (start_program == 'N' || start_program == 'n') {
            printf("\nExiting the program . . . \n");
            return 0;
        } else {
            printf("\nError: Invalid input. Please enter Y or N.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    while (1) {
        printf("\nEnter number of people: ");

        // Input validation loop to check if the number of people is a positive integer
        if (scanf("%d%c", &num_people, &newline) != 2 || newline != '\n' || num_people <= 0) {
            printf("\nError: Invalid input. Please enter a natural number (e.g. 1,2,3) for the number of people.\n");
            printf("Press ENTER to continue . . .\n");
            while (getchar() != '\n');
        } else {
            break; // Exits loop if valid input is received
        }
    }

    // Creates an empty array to store amount spent by each person
    double expenses[num_people];

    // Filling array with inputted expenses for each person
    for (int i = 0; i < num_people; i++) {
        printf("\nEnter amount spent by person %d: ", i + 1);

        // Loop to validate input for amount spent is a non-negative number
        double expense;
        if (scanf("%lf", &expense) != 1 || expense < 0) {
            printf("\nError: Invalid input. Please enter a non-negative number for the amount spent.\n");
            i--; // Decrement i to repeat step for the same person
            while (getchar() != '\n');
        } else {
            // Otherwise, conditions are met and the value is writen for person i to the expense array
            expenses[i] = expense; 
        }
    }

    // Input for service charge percentage
    double service_charge;

    while (1) {
        printf("\nEnter the service charge or VAT percentage (e.g. 12.5 for 12.5%%): ");

        // Loop to check if the input for service charge is a non-negative number
        if (scanf("%lf", &service_charge) != 1 || service_charge < 0) {
            printf("\nError: Invalid input. Please enter a non-negative number.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }

    // Calculate total amount spent by summing through the array
    double total_amount = 0.0;
    for (int i = 0; i < num_people; i++) {
        total_amount += expenses[i];
    }

    // Calculate total service charge amount and total bill including service charge
    double service_charge_amount = total_amount * (service_charge / 100);
    double total_amount_with_service_charge = total_amount + service_charge_amount;

    printf("\n------------------------------------------------");
    printf("\nBreakdown\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_people; i++) {
        // Calculates a person's share of the service charge or VAT by applying a weighting based on their contribution to the total damage
        double fees = (expenses[i] / total_amount) * total_amount_with_service_charge;
        // Prints the final amount owed by adding how much they spent plus their share of the service charge
        printf("Person %d owes: %.2f\n", i + 1, fees);
    }

    printf("\nService Charge / VAT / Fees due: %.2f\n", service_charge_amount);
    printf("Amount due (incl. service charge): %.2f\n", total_amount_with_service_charge);
    printf("------------------------------------------------\n");
    
    return 0;
}