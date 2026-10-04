#ifndef COMMON_H
#define COMMON_H

#define MAX_EMPLOYEES    100
#define MAX_DEPARTMENTS   50
#define MAX_SUPPLIERS    100
#define MAX_ASSETS       100
#define NAME_LEN          50
#define ID_LEN            10
#define DEPT_LEN          30
#define EMAIL_LEN         50
#define PHONE_LEN         15
#define TOWN_LEN          30
#define TYPE_LEN          30
#define COND_LEN          20

typedef struct {
    char   id[ID_LEN];
    char   name[NAME_LEN];
    char   department[DEPT_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

typedef struct {
    char   department[DEPT_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;

typedef struct {
    char id[ID_LEN];
    char name[NAME_LEN];
    char email[EMAIL_LEN];
    char telephone[PHONE_LEN];
    char town[TOWN_LEN];
} Supplier;

typedef struct {
    char   id[ID_LEN];
    char   name[NAME_LEN];
    char   type[TYPE_LEN];
    double purchaseValue;
    char   department[DEPT_LEN];
    char   condition[COND_LEN];
} Asset;
int getValidInt(const char *prompt, int min, int max);
double getValidDouble(const char *prompt, double min, double max);
void getValidString(const char *prompt, char *buffer, int size);
int getValidMenuChoice(int min, int max);
void clearInputBuffer(void);
#endif