#ifndef MEMBER_H
#define MEMBER_H

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

// Function Prototypes
Member *addMember(Member *head);
void searchMember(Member *head);
Member *deleteMember(Member *head);
void listInvitedMembers(Member *head);
void listAllMembers(Member *head);
void freeMemory(Member *head);

#endif // MEMBER_H