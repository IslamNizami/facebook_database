#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "member.h"

// Load database function to initialize the member linked list from a file.
Member *loadDatabase() {
    // Open the file in read mode. This file stores the member database.
    FILE *file = fopen("community_db.txt", "r");
    Member *head = NULL; // Initialize the head of the linked list as NULL.

    // If the file doesn't exist, notify the user and start with an empty database.
    if (!file) {
        printf("No database found. Starting with an empty database\n");
        return head;
    }

    // Read each line of the file until the end is reached.
    while (!feof(file)) {
        // Allocate memory for a new member node.
        Member *newMember = (Member *)malloc(sizeof(Member));
        
        // Read the member details from the file.
        fscanf(file, "%s %s %s %d %d %d %s %s\n",
               newMember->username, newMember->familyName, newMember->givenName,
               &newMember->birthYear, &newMember->birthMonth, &newMember->birthDay,
               newMember->birthPlace, newMember->inviter);

        // Add the new member node to the front of the linked list.
        newMember->next = head;
        head = newMember;
    }

    // Close the file after reading all records.
    fclose(file);
    printf("Database loaded successfully.\n");

    // Return the head of the linked list.
    return head;
}

// Save database function to persist the member linked list into a file.
void saveDatabase(Member *head) {
    // Open the file in write mode. This will overwrite any existing file.
    FILE *file = fopen("community_db.txt", "w");

    // If the file cannot be opened, notify the user and exit the function.
    if (!file) {
        printf("Error saving database.\n");
        return;
    }

    // Initialize a temporary pointer to traverse the linked list.
    Member *temp = head;

    // Iterate through the linked list and write each member's details into the file.
    while (temp != NULL) {
        fprintf(file, "%s %s %s %d %d %d %s %s\n",
                temp->username, temp->familyName, temp->givenName,
                temp->birthYear, temp->birthMonth, temp->birthDay,
                temp->birthPlace, temp->inviter);
        temp = temp->next; // Move to the next node in the list.
    }

    // Close the file after writing all records.
    fclose(file);
    printf("Database saved successfully.\n");
}
