#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// Member struct definition
typedef struct Member {
    char username[30];

    char familyName[30];

    char givenName[30];

    int birthYear;

    int birthMonth;
    
    int birthDay;

    char birthPlace[50];

    char inviter[30];

    struct Member *next;
    
} Member;

bool isValidDate(int year, int month, int day) {
    // Check valid range for year, month, and day
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap years
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

// Function Prototypes Before main
Member *loadDatabase();

void saveDatabase(Member *head);

Member *addMember(Member *head);

void searchMember(Member *head);

Member *deleteMember(Member *head);

void listInvitedMembers(Member *head);

void listAllMembers(Member *head);

void freeMemory(Member *head);

// Function to load the database from file
Member *loadDatabase() {
    FILE *file = fopen("community_db.txt", "r");

    Member *head = NULL;

    if (!file) {
        printf("No database found. Starting with an empty database\n");
        return head;
    }

    while (!feof(file)) {
        Member *newMember = (Member *)malloc(sizeof(Member));

        fscanf(file, "%s %s %s %d %d %d %s %s\n",
               newMember->username, newMember->familyName, newMember->givenName,
               &newMember->birthYear, &newMember->birthMonth, &newMember->birthDay,
               newMember->birthPlace, newMember->inviter);

        newMember->next = head;
        head = newMember;
    }

    fclose(file);
    printf("Database loaded successfully.\n");
    return head;
}

// Function to save the database to file
void saveDatabase(Member *head) {
    FILE *file = fopen("community_db.txt", "w");

    if (!file) {
        printf("Error saving database.\n");
        return;
    }

    Member *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s %s %s %d %d %d %s %s\n",
                temp->username, temp->familyName, temp->givenName,
                temp->birthYear, temp->birthMonth, temp->birthDay,
                temp->birthPlace, temp->inviter);
        temp = temp->next;
    }

    fclose(file);
    printf("Database saved successfully.\n");
}

// Function to add a new member
Member *addMember(Member *head) {
    Member *newMember = (Member *)malloc(sizeof(Member));

    printf("Enter Username: ");
    scanf("%s", newMember->username);
    printf("Enter Family Name: ");
    scanf("%s", newMember->familyName);
    printf("Enter Given Name: ");
    scanf("%s", newMember->givenName);
    printf("Enter Birth Year, Month, and Day: ");
int year, month, day;

while (true) {
    if (scanf("%d %d %d", &year, &month, &day) == 3) {
        // If three valid integers are provided, validate the date
        if (isValidDate(year, month, day)) {
            newMember->birthYear = year;
            newMember->birthMonth = month;
            newMember->birthDay = day;
            break;
        } else {
            printf("Invalid date. Please enter a valid Birth Year, Month, and Day: ");
        }
    } else {
        // Clear the invalid input
        while (getchar() != '\n');
        printf("Invalid input. Please enter numeric values for Birth Year, Month, and Day: ");
    }
}
    printf("Enter Birthplace: ");
    scanf("%s", newMember->birthPlace);
    printf("Enter Inviter Username: ");
    scanf("%s", newMember->inviter);

    newMember->next = head;
    head = newMember;
    printf("New member '%s' added successfully.\n", newMember->username);
    return head;
}

// Function to search for a member
void searchMember(Member *head) {
    char search[50];
    printf("Enter username or family name to search: ");
    scanf("%s", search);

    Member *temp = head;
    int found = 0;

    while (temp) {
        if (strcmp(temp->username, search) == 0 || strcasecmp(temp->familyName, search) == 0) {
            printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
                   temp->username, temp->familyName, temp->givenName,
                   temp->birthYear, temp->birthMonth, temp->birthDay,
                   temp->birthPlace, temp->inviter);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No members found matching '%s'.\n", search);
    }
}

Member *deleteMember(Member *head) {
    char username[30];
    printf("Enter username of member to delete: ");
    scanf("%s", username);

    Member *current = head;
    Member *prev = NULL;

    while (current) {
        if (strcmp(current->username, username) == 0) {
            // Found the member to delete
            if (prev) {
                // If it's not the first member, bypass the current node
                prev->next = current->next;
            } else {
                // If it's the first member, update the head
                head = current->next;
            }

            // Free the memory and set the pointer to NULL
            free(current);
            current = NULL;
            printf("Member '%s' deleted successfully.\n", username);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("No member found with username '%s'.\n", username);
    return head;
}


// Function to list members invited by a specific person
void listInvitedMembers(Member *head) {
    char inviter[30];
    printf("Enter inviter username: ");
    scanf("%s", inviter);

    Member *temp = head;
    int found = 0;

    while (temp) {
        if (strcmp(temp->inviter, inviter) == 0) {
            found = 1;
            printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
                   temp->username, temp->familyName, temp->givenName,
                   temp->birthYear, temp->birthMonth, temp->birthDay,
                   temp->birthPlace, temp->inviter);
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No members were invited by '%s'.\n", inviter);
    }
}

// Function to list all members
void listAllMembers(Member *head) {
    if (!head) {
        printf("No members in the community.\n");
        return;
    }

    Member *temp = head;
    while (temp) {
        printf("\nUsername: %s\nFamily Name: %s\nGiven Name: %s\nDate of Birth: %d-%02d-%02d\nBirthplace: %s\nInviter: %s\n",
               temp->username, temp->familyName, temp->givenName,
               temp->birthYear, temp->birthMonth, temp->birthDay,
               temp->birthPlace, temp->inviter);
        temp = temp->next;
    }
}

// Function to free allocated memory
void freeMemory(Member *head) {
    Member *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    Member *head = loadDatabase();
    int choice;

    do {
        printf("\n--- Facebook Community Management System ---\n");
        printf("1. Save Database\n");
        printf("2. Add New Member\n");
        printf("3. Search for Member\n");
        printf("4. Delete Member\n");
        printf("5. List Members Invited by a Specific Person\n");
        printf("6. List All Members\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: 
                saveDatabase(head); 
                break;
            case 2: 
                head = addMember(head); 
                break;
            case 3: 
                searchMember(head); 
                break;
            case 4: 
                head = deleteMember(head); 
                break;
            case 5: 
                listInvitedMembers(head); 
                break;
            case 6: 
                listAllMembers(head); 
                break;
            case 7: 
                saveDatabase(head); 
                freeMemory(head); 
                printf("Exiting program.\n"); 
                break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
