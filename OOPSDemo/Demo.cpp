#include<iostream>

using namespace std ;

class Student
{
    public :
    char name ;
    int rollno ;
    int age ;

    void introduceYourself()
    {
        cout << name << " is " << age << " years old and has rollno " << rollno << "." << endl ;
    }

    void sayHii(char name)
    {
        cout << this->name << " says hi to " << name << endl ;
    }
} ;

int main()
{
    // Student s ;
    // s.name = 'A' ;
    // s.rollno = 70 ;
    // s.age = 20 ;

    // cout << s.name << endl ;
    // cout << s.rollno << endl ;
    // cout << s.age << endl ;
    
    // s.introduceYourself() ;
    // s.sayHii('R') ;

    // Student s1 ;
    // s1.name = 'B' ;
    // s1.rollno = 700 ;
    // s1.age = 200 ;

    // s1.introduceYourself() ;

    Student *s = new Student() ;
    s->name = 'A' ;
    (*s).age = 15 ;
    (*s).rollno = 100 ;

    cout << s->name  << endl ;

    return 0 ;
}