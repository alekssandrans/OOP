#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person
{
    public:
        Person(const char* new_name="name", const char* new_dateOfBirth="yyyymmdd");
        Person(const Person& other);
        Person& operator=(const Person& other);
        ~Person();

        void setName(const char* new_name);
        void setDateOfBirth(const char* new_dateOfBirth);

        const char* getName() const {return this->name;}
        const char* getDateOfBirth() const {return this->dateOfBirth;}

        void print() const;

    private:
        char* name;
        char dateOfBirth[9];

        bool isValidDate(const char* date);
};
#endif // PERSON_H_INCLUDED
