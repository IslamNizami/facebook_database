#include <stdio.h>
#include "member.h"
#include "database.h"

// Main function
int main() {
    // Load the database from the file into the linked list.
    Member *head = loadDatabase();

    int choice; // Variable to store the user's menu choice.

    // Menu-driven loop: Continues until the user chooses to exit (choice == 7).
    do {
        // Display the menu options.
        printf("\n--- Facebook Community Management System ---\n");
        printf("1. Save Database\n");
        printf("2. Add New Member\n");
        printf("3. Search for Member\n");
        printf("4. Delete Member\n");
        printf("5. List Members Invited by a Specific Person\n");
        printf("6. List All Members\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        // Read the user's choice and consume any extra newline characters.
        scanf("%d", &choice);
        getchar();

        // Execute the appropriate action based on the user's choice.
        switch (choice) {
            case 1: 
                // Save the current linked list to the database file.
                saveDatabase(head); 
                break;
            case 2: 
                // Add a new member to the linked list.
                head = addMember(head); 
                break;
            case 3: 
                // Search for a member by username or family name.
                searchMember(head); 
                break;
            case 4: 
                // Delete a member by username and update the linked list head.
                head = deleteMember(head); 
                break;
            case 5: 
                // List all members invited by a specific inviter.
                listInvitedMembers(head); 
                break;
            case 6: 
                // List all members in the community.
                listAllMembers(head); 
                break;
            case 7: 
                // Save the database, free allocated memory, and exit the program.
                saveDatabase(head); 
                freeMemory(head); 
                printf("Exiting program.\n"); 
                break;
            default: 
                // Handle invalid input.
                printf("Invalid choice. Please try again.\n"); 
        }
    } while (choice != 7); // Continue looping until the user selects "Exit."

    return 0; // End of the program.
}
