#include "Header.h"

int main()
{
    Users* set[] =
    {
      new Patient, new Paramedic, new Paramedic, new Patient, new Patient, 0
    };
    CountVisitor count;
    GetTypeVisitor type;
    
    cout << "LIST USERS:\n";
    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&count);
        set[i]->accept(&type);
    }
    cout << "\nSTATISTICS:\n";
    count.PrintNum();
}

