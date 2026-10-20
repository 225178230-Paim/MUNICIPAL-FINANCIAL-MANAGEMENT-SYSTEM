# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Project:** Project A – Foundation System
**Programing language:** ANSI C (C99)

## Group Members

| # | Name | Student Number |
|---|------|----------------|
| 1 | Sanwel | 226043762 |
| 2 | Peneyambeko | 226099962 |
| 3 | Masake | 226055841 |
| 4 | Nghidileko | 226075583 |
| 5 | Nyambe | 225124459 |
| 6 | Liswani | 225005255 |
| 7 | Paim | 225178230 |

## Project Description

The Municipal Financial Management System (MFMS) is a application written in C. It's main purpose is to help a municipality manage employees, department budgets, suppliers and assets, and produce summary reports.


## System Features

- **Main menu:** The main menu is the main navigation between all functions of the app. 

- **Employee management:** The employee management manages various operations employee related. e.g.: Here the user will be able to add employees, display them, search for them, calculate their salaries, etc.

- **Budget management:** The budget management manages operations budget related. e.g.: Here the user will be able to input the budget and expenditure of a department, perform calculations on them, see the results, etc. 

- **Supplier management:** This function of the app has the purpose of storing supplier’s information and comparing them.

- **Asset management:** This function of the app has the purpose of storing diverse types of assets, count them, retrieve them, and display them.

- **Reports:** This function of the app is responsible for giving reports to the user, it reports all the operations done in the above functions.




## Project Structure

```
MFMS/
├── main.c
├── employees.c / employees.h
├── budget.c / budget.h
├── suppliers.c / suppliers.h
├── assets.c / assets.h
├── reports.c / reports.h
└── README.md
```

## Compilation Instructions


```bash
gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## How to Run

Linux / macOS / WSL:

```bash
./mfms
```

Windows (Command Prompt or PowerShell):

```bash
mfms.exe
```

The user Chooses an option from the main menu by entering its number, then follows the prompts seen on screen.

## Individual Responsibilities

| Member | Primary Responsibility | Functions / Modules |
|--------|------------------------|---------------------|
| Sanwel | Employee Management | e.g. employees.c: addEmployee(), ... |
| Peneyambeko | Budget Management | e.g. budget.c: ... |
| Masake | Supplier Management | e.g. suppliers.c: ... |
| Nghidileko | Asset Management | e.g. assets.c: ... |
| Nyambe | Reports | e.g. reports.c: ... |
| Liswani | Functions, integration and validation | e.g. main.c, validation functions |
| Paim | Testing, documentation and Git coordination | README, report, test log |