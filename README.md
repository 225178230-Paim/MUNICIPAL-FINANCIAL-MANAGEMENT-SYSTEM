# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Project:** Project A – Foundation System
**Language:** ANSI C (C99)

## Group Members

| # | Name | Student Number |
|---|------|----------------|
| 1 | [Sanwel] | [226043762] |
| 2 | [Peneyambeko] | [226099962] |
| 3 | [Masake] | [226055841] |
| 4 | [Nghidileko] | [226075583] |
| 5 | [Name] | [Student number] |
| 6 | [Liswani] | [225005255] |
| 7 | [Paim] | [225178230] |

## Project Description

The Municipal Financial Management System (MFMS) is a menu-driven console application written in C. It helps a municipality manage employees, departmental budgets, suppliers and assets, and produce summary reports.

## System Features

- **Main menu:** clear navigation between all modules, with handling of invalid choices.
- **Employee management:** add, display and search employees; calculate salary information (basic salary plus housing and transport allowances) [add any extra fields or deductions your group implemented].
- **Budget management:** enter departmental budgets and expenditure, calculate the remaining budget, show whether each department is within budget, and identify departments that exceeded their allocation.
- **Supplier management:** add, display and search suppliers (ID, name, email, telephone, town/location).
- **Asset management:** maintain an asset register (ID, name, type, purchase value, department, condition) with display and search.
- **Reports:** employee report (total, average, highest and lowest salary), budget report, supplier report and asset report.
- **Input validation:** rejects negative salaries and budgets, empty names, invalid menu choices and invalid numeric input.

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

Requirements: GCC and a terminal (tested in Visual Studio Code).

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

Choose an option from the main menu by entering its number, then follow the on-screen prompts.

## Individual Responsibilities

| Member | Primary Responsibility | Functions / Modules |
|--------|------------------------|---------------------|
| [Sanwel] | Employee Management | [e.g. employees.c: addEmployee(), ...] |
| [Peneyambeko] | Budget Management | [e.g. budget.c: ...] |
| [Masake] | Supplier Management | [e.g. suppliers.c: ...] |
| [Nghidileko] | Asset Management | [e.g. assets.c: ...] |
| [Name] | Reports | [e.g. reports.c: ...] |
| [Liswani] | Functions, integration and validation | [e.g. main.c, validation functions] |
| [Paim] | Testing, documentation and Git coordination | [README, report, test log] |