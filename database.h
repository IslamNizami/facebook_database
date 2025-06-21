
#ifndef DATABASE_H
#define DATABASE_H

#include "member.h"

//Function prototypes
Member *loadDatabase();
void saveDatabase(Member* head);

#endif