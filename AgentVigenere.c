#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
TODO:
-Add some sort of GUI
-Add some more advanced features
*/

// Vigenere encryption given message and key
void encrypt(char message[], const char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    for (int i = 0, j = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            int keyIndex = tolower(key[j % keyLength]) - 'a';
            message[i] = (message[i] - base + keyIndex) % 26 + base;
            j++;
        }
    }
}

// Vigenere decryption given message and key
void decrypt(char message[], const char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    for (int i = 0, j = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            int keyIndex = tolower(key[j % keyLength]) - 'a';
            message[i] = (message[i] - base - keyIndex + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    char *message = NULL;
    char *key = NULL;
    char choice;

    printf("\n");
    printf("--Welcome to Agent Vigenere--\n");
    printf("\n");

    while (1) {
        printf("Would you like to:\n");
        printf("\n");
        printf("1. Encode a message\n");
        printf("2. Decode a message\n");
        printf("3. Quit\n");
        printf("\n");
        printf("Type 1/2/3 and hit enter: ");

        // Use scanf to read a single character
        scanf(" %c", &choice);

        while (getchar() != '\n');

        // If the user types 3, quit
        if (choice == '3') {
            printf("\n");
            break;
        }
        // If the user does not give a valid input, try again
        else if (choice != '1' && choice != '2') {
            printf("\n");
            printf("Invalid selection. Try again.\n");
            printf("\n");
            continue;
        }

        // Continue
        printf("\n");
        printf("Enter a message: ");
        size_t message_size = 0;
        getline(&message, &message_size, stdin);
        message[strcspn(message, "\n")] = '\0';

        // Input encryption key
        printf("Enter an encryption key: ");
        size_t key_size = 0;
        getline(&key, &key_size, stdin);
        key[strcspn(key, "\n")] = '\0';

        // Encrypt the message
        if (choice == '1') {
            encrypt(message, key);
            printf("\n");
            printf("Encrypted message: %s\n", message);
        }
        // Decrypt the message
        else {
            decrypt(message, key);
            printf("\n");
            printf("Decrypted message: %s\n", message);
        }

        // Ask if the user wants to continue or quit
        printf("\n");
        printf("Would you like to:\n");
        printf("\n");
        printf("1. Encrypt/Decrypt another message\n");
        printf("2. Quit\n");
        printf("\n");
        printf("Type 1/2 and hit enter: ");

        // Validate the user's input for continuing or quitting
        while (1) {
            scanf(" %c", &choice);
            while (getchar() != '\n');
            // If user
            if (choice == '1' || choice == '2') {
                break;
            }
            printf("\n");
            printf("Invalid selection. Try again.\n");
            printf("\n");
        }

        // If the user types 2, break the loop to quit
        if (choice == '2') {
            break;
        }
    }

    // Free memory
    free(message);
    free(key);

    return 0;
}