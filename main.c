#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of devices
#define MAX_DEVICES 5

// Device states: 0 for off, 1 for on, 0 for unlocked, 1 for locked
int lights[MAX_DEVICES] = {0};           // 0 for off, 1 for on
int tempSensors[MAX_DEVICES] = {0};      // Store temperature in Celsius
int motionSensors[MAX_DEVICES] = {0};    // 0 for no motion, 1 for motion detected
int securityLocks[MAX_DEVICES] = {0};    // 0 for unlocked, 1 for locked

// Function declarations
void displayMenu();
void controlLights();
void monitorTemperature();
void monitorMotion();
void controlLocks();
void simulateDevices();

// Main function
int main() {
    int choice;
    
    // Seed the random number generator
    srand(time(NULL));

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLights(); break;
            case 2: monitorTemperature(); break;
            case 3: monitorMotion(); break;
            case 4: controlLocks(); break;
            case 5: simulateDevices(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Display menu options
void displayMenu() {
    printf("\nSmart Home Automation System\n");
    printf("1. Control Lights\n");
    printf("2. Monitor Temperature Sensors\n");
    printf("3. Monitor Motion Sensors\n");
    printf("4. Control Security Locks\n");
    printf("5. Simulate Device Operations\n");
    printf("6. Exit\n");
}

// Control lights (on/off)
void controlLights() {
    int device;
    printf("Enter device number (1 to %d): ", MAX_DEVICES);
    scanf("%d", &device);
    if (device < 1 || device > MAX_DEVICES) {
        printf("Invalid device number.\n");
        return;
    }

    int action;
    printf("1. Turn On\n2. Turn Off\n");
    printf("Choose an action: ");
    scanf("%d", &action);

    if (action == 1) {
        lights[device - 1] = 1;
        printf("Light %d turned ON.\n", device);
    } else if (action == 2) {
        lights[device - 1] = 0;
        printf("Light %d turned OFF.\n", device);
    } else {
        printf("Invalid action.\n");
    }
}

// Monitor temperature sensors
void monitorTemperature() {
    int device;
    printf("Enter device number (1 to %d): ", MAX_DEVICES);
    scanf("%d", &device);
    if (device < 1 || device > MAX_DEVICES) {
        printf("Invalid device number.\n");
        return;
    }

    // Simulate temperature between 15 to 30 Celsius
    tempSensors[device - 1] = 15 + rand() % 16;
    printf("Temperature of sensor %d: %d°C\n", device, tempSensors[device - 1]);
}

// Monitor motion sensors
void monitorMotion() {
    int device;
    printf("Enter device number (1 to %d): ", MAX_DEVICES);
    scanf("%d", &device);
    if (device < 1 || device > MAX_DEVICES) {
        printf("Invalid device number.\n");
        return;
    }

    // Simulate motion detection (0 or 1)
    motionSensors[device - 1] = rand() % 2;
    if (motionSensors[device - 1] == 1) {
        printf("Motion detected by sensor %d.\n", device);
    } else {
        printf("No motion detected by sensor %d.\n", device);
    }
}

// Control security locks (lock/unlock)
void controlLocks() {
    int device;
    printf("Enter device number (1 to %d): ", MAX_DEVICES);
    scanf("%d", &device);
    if (device < 1 || device > MAX_DEVICES) {
        printf("Invalid device number.\n");
        return;
    }

    int action;
    printf("1. Lock\n2. Unlock\n");
    printf("Choose an action: ");
    scanf("%d", &action);

    if (action == 1) {
        securityLocks[device - 1] = 1;
        printf("Lock %d is now LOCKED.\n", device);
    } else if (action == 2) {
        securityLocks[device - 1] = 0;
        printf("Lock %d is now UNLOCKED.\n", device);
    } else {
        printf("Invalid action.\n");
    }
}

// Simulate all devices' states
void simulateDevices() {
    printf("\nSimulating device states...\n");

    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("\nDevice %d:\n", i + 1);

        // Light status
        printf("  Light: %s\n", lights[i] ? "ON" : "OFF");

        // Temperature sensor status
        printf("  Temperature: %d°C\n", tempSensors[i]);

        // Motion sensor status
        printf("  Motion: %s\n", motionSensors[i] ? "Detected" : "Not Detected");

        // Lock status
        printf("  Lock: %s\n", securityLocks[i] ? "LOCKED" : "UNLOCKED");
    }
}