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
    char case_;
    for (int i = 0, j = 0; i < messageLength; i++) {
        // Only letters can be encoded
        if (isalpha(message[i])) {
            // The letters' case is important for the encryption/decryption process
            // This is because of the letters' ASCII value
            if (islower(message[i])) {
                case_ = 'a';
            }
            else {
                case_ = 'A';
            }
            int keyIndex = tolower(key[j % keyLength]) - 'a';
            message[i] = (message[i] - case_ + keyIndex) % 26 + case_;
            j++;
        }
    }
}

// Vigenere decryption given message and key
void decrypt(char message[], const char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char case_;
    for (int i = 0, j = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            // The letters' case is important for the encryption/decryption process
            // This is because of the letters' ASCII value
            if (islower(message[i])) {
                case_ = 'a';
            }
            else {
                case_ = 'A';
            }
            int keyIndex = tolower(key[j % keyLength]) - 'a';
            message[i] = (message[i] - case_ - keyIndex + 26) % 26 + case_;
            j++;
        }
    }
}

int main() {
    char *message = NULL;
    char *key = NULL;
    int choice;

    printf("\n");
    printf("--Welcome to Agent Vigenere--\n");
    printf("\n");
  
    // 
    while (choice != 2) {
        printf("Would you like to:\n");
        printf("\n");
        printf("1. Encode a message\n");
        printf("2. Decode a message\n");
        printf("3. Quit\n");
        printf("\n");

        // Repeat the type part in case the user gives an invalid input
        while (choice != 1 || choice != 2 || choice != 3) {
            printf("Type 1/2/3 and hit enter: ");

            scanf("%d", &choice);

            // If the user types 3, quit
            if (choice == 3) {
                printf("\n");
                printf("Goodbye!\n");
                return 0;
            }
            // If the user does not give a valid input, try again
            else if (choice != 1 && choice != 2) {
                while (getchar() != '\n');
                printf("\n");
                printf("Invalid selection. Try again.\n");
                printf("\n");
                continue;
            }
            // If the user chooses a valid input, break out of the loop
            else if (choice == 1 || choice == 2){
              break;
            }
        }
          // Continue
          while (getchar() != '\n');
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
          if (choice == 1) {
              encrypt(message, key);
              printf("\n");
              printf("Encrypted message: %s\n", message);
          }
          // Decrypt the message
          else if (choice == 2) {
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

          scanf("%d", &choice);

          printf("\n");
          printf("\n");

      }

    printf("Goodbye!\n");

    // Free memory
    free(message);
    free(key);
  
    return 0;
}