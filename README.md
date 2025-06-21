# Facebook Community Management System

A C-based command-line application to manage members of a Facebook-like community. It supports functionalities like adding, searching, deleting, and listing members, along with persistent data storage.

## 🧩 Features

- ✅ Add New Members
- 🔍 Search Members (by username or family name)
- ❌ Delete Members (by username)
- 📃 List All Members
- 👥 List Members Invited by a Specific Person
- 💾 Persistent Storage via `community_db.txt`

---

## 🧱 Data Structures

- **Struct:** Each member is stored using a `Member` struct.
- **Linked List:** Used for dynamic management of members in memory.


🔧 Modules
Main Module

Handles user input and menu-driven interface.

Database Management

Loads/saves member data to community_db.txt.

Member Management

Core logic for adding, searching, deleting, and listing members.

Memory Management

Ensures all allocated memory is properly freed.

🔁 Core Functions
Function	Description
Member* loadDatabase()	Loads data from community_db.txt into a linked list
void saveDatabase()	Writes the current member list to the file
Member* addMember()	Adds a new member to the list
void searchMember()	Searches member by username or family name
Member* deleteMember()	Deletes a member by username
void listAllMembers()	Displays all members
void listInvitedMembers()	Shows members invited by a specific user
void freeMemory()	Frees all linked list memory

🚀 How to Run
Prerequisites
GCC or any C compiler

A text editor or IDE (e.g., VS Code)

Compilation
Ensure these files are in the same directory:

css
Copy
Edit
main.c
database.c
member.c
Then compile:
gcc -o community_manager main.c database.c member.c
Run the program
./community_manager

📘 Usage Guide
On Startup
If community_db.txt exists, it will be loaded automatically.

Otherwise, a new file will be created.

Menu Options
Save Database

Add New Member

Inputs: username, name, date of birth, birthplace, inviter

Search Member

By username or family name

Delete Member

By username

List Members by Inviter

Enter inviter’s username

List All Members

Exit and Save

Input Format
Date of Birth: YYYY MM DD

Text: Keep input within limits (e.g., username max 50 chars)

📂 File Information
Data File: community_db.txt (saved in the same directory)

Binary File (after compilation): community_manager

🧼 Memory Management
All dynamically allocated memory is freed upon exit using:
void freeMemory(Member *head);


📄 License:
This project is intended for educational purposes and is open for learning and modification.

✍️ Author:
Islam Nizami

Feel free to connect!
