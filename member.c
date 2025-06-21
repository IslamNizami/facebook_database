#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

// Function to add a new member to the linked list.
Member *addMember(Member *head) {
    // Allocate memory for the new member.
    Member *newMember = (Member *)malloc(sizeof(Member));
    if (!newMember) {
        printf("Memory allocation failed.\n");
        return head;
    }

    // Collect details for the new member.
    printf("Enter Username: ");
    scanf("%s", newMember->username);
    printf("Enter Family Name: ");
    scanf("%s", newMember->familyName);
    printf("Enter Given Name: ");
    scanf("%s", newMember->givenName);
    printf("Enter Birth Year, Month, Day: ");
    scanf("%d %d %d", &newMember->birthYear, &newMember->birthMonth, &newMember->birthDay);
    printf("Enter Birthplace: ");
    scanf("%s", newMember->birthPlace);
    printf("Enter Inviter Username: ");
    scanf("%s", newMember->inviter);

    // Add the new member to the front of the linked list.
    newMember->next = head;
    head = newMember;

    // Notify the user of the successful addition.
    printf("New member '%s' added successfully.\n", newMember->username);
    return head;
}

// Function to search for a member by username or family name.
void searchMember(Member *head) {
    char search[50]; // Variable to store the search query.
    printf("Enter username or family name to search: ");
    scanf("%s", search);

    Member *temp = head;
    int found = 0; // Flag to check if any member is found.

    // Traverse the linked list and search for matches.
    while (temp) {
        if (strcmp(temp->username, search) == 0 || strcasecmp(temp->familyName, search) == 0) {
            // Print the member details if a match is found.
            printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
                   temp->username, temp->familyName, temp->givenName,
                   temp->birthYear, temp->birthMonth, temp->birthDay,
                   temp->birthPlace, temp->inviter);
            found = 1;
        }
        temp = temp->next;
    }

    // Notify the user if no matches were found.
    if (!found) {
        printf("No members found matching '%s'.\n", search);
    }
}

// Function to delete a member by username.
Member *deleteMember(Member *head) {
    char username[30];
    printf("Enter username of member to delete: ");
    scanf("%s", username);

    Member *current = head;
    Member *prev = NULL;

    // Traverse the list to find the member to delete.
    while (current) {
        if (strcmp(current->username, username) == 0) {
            // Found the member to delete.
            if (prev) {
                // If it's not the first member, bypass the current node.
                prev->next = current->next;
            } else {
                // If it's the first member, update the head.
                head = current->next;
            }

            // Free the memory for the deleted member.
            free(current);
            printf("Member '%s' deleted successfully.\n", username);
            return head;
        }
        prev = current;
        current = current->next;
    }

    // Notify the user if the member was not found.
    printf("No member found with username '%s'.\n", username);
    return head;
}

// Function to list members invited by a specific inviter.
void listInvitedMembers(Member *head) {
    char inviter[30];
    printf("Enter inviter username: ");
    scanf("%s", inviter);

    Member *temp = head;
    int found = 0; // Flag to check if any members are invited by the given inviter.

    // Traverse the list and find members invited by the specified inviter.
    while (temp) {
        if (strcmp(temp->inviter, inviter) == 0) {
            // Print the member details if a match is found.
            printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
                   temp->username, temp->familyName, temp->givenName,
                   temp->birthYear, temp->birthMonth, temp->birthDay,
                   temp->birthPlace, temp->inviter);
            found = 1;
        }
        temp = temp->next;
    }

    // Notify the user if no matches were found.
    if (!found) {
        printf("No members were invited by '%s'.\n", inviter);
    }
}

// Function to list all members in the linked list.
void listAllMembers(Member *head) {
    // If the list is empty, notify the user.
    if (!head) {
        printf("No members in the community.\n");
        return;
    }

    // Traverse the list and print each member's details.
    Member *temp = head;
    while (temp) {
        printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
               temp->username, temp->familyName, temp->givenName,
               temp->birthYear, temp->birthMonth, temp->birthDay,
               temp->birthPlace, temp->inviter);
        temp = temp->next;
    }
}

// Function to free all allocated memory in the linked list.
void freeMemory(Member *head) {
    Member *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All memory has been freed.\n");
}
