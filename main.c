#include <stdio.h>
#include <stdbool.h>

#define MAX_SPOTS 10

typedef struct {
    int spot_number;
    bool occupied;
    char license_plate[10];
} ParkingSpot;

ParkingSpot parking_lot[MAX_SPOTS];

void initializeParkingLot() {
    for (int i = 0; i < MAX_SPOTS; i++) {
        parking_lot[i].spot_number = i + 1;
        parking_lot[i].occupied = false;
    }
}

void displayParkingLot() {
    printf("Parking Lot Status:\n");
    for (int i = 0; i < MAX_SPOTS; i++) {
        printf("Spot %d: %s\n", parking_lot[i].spot_number, parking_lot[i].occupied ? parking_lot[i].license_plate : "Empty");
    }
}

int findEmptySpot() {
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (!parking_lot[i].occupied) {
            return i;
        }
    }
    return -1; // No empty spots available
}

int main() {
    initializeParkingLot();

    while (1) {
        printf("\nCar Parking System Menu:\n");
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parking lot status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (findEmptySpot() != -1) {
                    int empty_spot = findEmptySpot();
                    parking_lot[empty_spot].occupied = true;
                    printf("Enter the license plate of the parked car: ");
                    scanf("%s", parking_lot[empty_spot].license_plate);
                    printf("Car parked in Spot %d\n", parking_lot[empty_spot].spot_number);
                } else {
                    printf("Sorry, the parking lot is full.\n");
                }
                break;

            case 2:
                printf("Enter the spot number to remove the car: ");
                int spot_to_remove;
                scanf("%d", &spot_to_remove);

                if (spot_to_remove >= 1 && spot_to_remove <= MAX_SPOTS) {
                    if (parking_lot[spot_to_remove - 1].occupied) {
                        parking_lot[spot_to_remove - 1].occupied = false;
                        printf("Car removed from Spot %d\n", spot_to_remove);
                    } else {
                        printf("Spot %d is already empty.\n", spot_to_remove);
                    }
                } else {
                    printf("Invalid spot number.\n");
                }
                break;

            case 3:
                displayParkingLot();
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
