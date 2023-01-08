#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filename "students.txt"

struct student
{
    char* name;
    int registration_number;
    int* grades;
    float avg;

};

struct node
{
    struct student* stud;
    struct node* next;
}*head;

void calc_avg(struct student* stud)
{
    float sum = 0;
    for(int i=0; i<5; i++) 
    {
        sum += *(stud->grades + i);
    }
    sum /= 5.0;

    stud->avg = sum;
}

struct student* read_stud(FILE* file)
{
    

    struct student* new_stud = (struct student*)malloc(sizeof(struct student));
    new_stud->grades = (int*)malloc(5 * sizeof(int));
    new_stud->name  = (char*)malloc(100);

    fscanf(file, "%d", &new_stud->registration_number);
    fscanf(file, "%d", new_stud->grades);
    fscanf(file, "%d", new_stud->grades + 1);
    fscanf(file, "%d", new_stud->grades + 2);
    fscanf(file, "%d", new_stud->grades + 3);
    fscanf(file, "%d", new_stud->grades + 4);
    fgets(new_stud->name, 100, file);

    new_stud->name = new_stud->name + 1; // stergem spatiul de la inceput
    if(*(new_stud->name + strlen(new_stud->name) - 1) == '\n')
        *(new_stud->name + strlen(new_stud->name) - 1) = *(new_stud->name + strlen(new_stud->name)); // stergem '\n' de la sfarsit

    calc_avg(new_stud);
    
    return new_stud;
}

void add(struct student* stud)
{
    struct node* nod = (struct node*) malloc (sizeof(struct node)), *p, *q = NULL;
    nod->stud = stud;
    nod->next = NULL;

    p = head;
    while(p != NULL && p->stud->avg > stud->avg) { q=p; p = p->next; }
    while(p != NULL && p->stud->avg == stud->avg && strcmp(p->stud->name, stud->name) <= 0) { q=p; p = p->next;}
    
    if(q==NULL) { head = nod; head->next = p; }
    else
    {
        if(p == NULL) q->next = nod;
        else
        {
            q->next = nod;
            nod->next = p;
        }
    }     

}

void print_stud(struct student* student)
{
    printf("Reg. No.: %d\n", student->registration_number);
    printf("Name: %s\n", student->name);
    printf("Grades: ");
    for(int i=0; i<5; i++)
        printf("%d ", *(student->grades + i));
    printf("\nAverage: %.2f\n", student->avg);

    printf("\n\n\n");
}

int main()
{
    struct node *p; 
    struct student* student;
    FILE* file = fopen(filename, "r");

    while(!feof(file))
    {
        student = read_stud(file);
        add(student);
    }
    p = head;
    while(p != NULL)
    {
        print_stud(p->stud);
        p = p->next;
    }
}
