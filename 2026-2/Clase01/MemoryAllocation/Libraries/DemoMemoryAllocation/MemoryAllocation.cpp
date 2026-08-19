//
// Created by erasmo on 8/19/26.
//

#include "MemoryAllocation.hpp"

#include "../Utilities/AuxiliaryFunctions.hpp"

void demo_local_variables() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "LOCAL VARIABLES");
    print_line(cout, '=', OUTPUT_WIDTH);
    int code = 10;
    double average = 18.75;
    bool approved = true;
    char grade = 'A';

    cout << "code:   " << code << endl;
    cout << "average:  " << average << endl;
    cout << "approved: " << approved << endl;
    cout << "grade:    " << grade << endl;
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "Memory addresses:");
    print_line(cout, '=', OUTPUT_WIDTH);
    cout << "&code:   " << &code << endl;
    cout << "&average:  " << &average << endl;
    cout << "&approved: " << &approved << endl;

    // Cout interprets char* as a C-string.
    // We cast it to void* to print the actual memory address.
    cout << "&grade:    "
            << static_cast<void *>(&grade)
            << endl;

    cout << "sizeof(code):     " << sizeof(code) << " bytes" << endl;
    cout << "sizeof(average):  " << sizeof(average) << " bytes" << endl;
    cout << "sizeof(approved): " << sizeof(approved) << " bytes" << endl;
    cout << "sizeof(grade):    " << sizeof(grade) << " bytes" << endl;
}

void demo_pointers() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "POINTERS");
    print_line(cout, '=', OUTPUT_WIDTH);
    int code = 25;

    int *ptr_code = &code;

    cout << "code:      " << code << endl;
    cout << "&code:     " << &code << endl;
    cout << "ptrCode:   " << ptr_code << endl;
    cout << "*ptrCode:  " << *ptr_code << endl;

    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "Changing the variable through the pointer");
    print_line(cout, '=', OUTPUT_WIDTH);

    *ptr_code = 100;

    cout << "code:      " << code << endl;
    cout << "*ptrCode:  " << *ptr_code << endl;
    cout << "&code:     " << &code << endl;
    cout << "ptrCode:   " << ptr_code << endl;
}

void demo_dynamic_int() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "DYNAMIC INT");
    print_line(cout, '=', OUTPUT_WIDTH);

    int *ptrCode = new int;

    *ptrCode = 50; // Dereferenced pointers = stored value

    cout << "Allocated address: " << ptrCode << endl;
    cout << "Stored value:      " << *ptrCode << endl;

    delete ptrCode;

    // delete releases the dynamically allocated memory.
    // After delete, the pointer becomes a dangling pointer.
    // A dangling pointer is a pointer that still holds the address of memory
    // that has already been released and is no longer valid to access.
    // Assigning nullptr prevents accidental access to the released memory.
    // If the pointer goes out of scope immediately after delete, this step can be omitted.

    ptrCode = nullptr;
}

void demo_dynamic_primitives_types() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "DYNAMIC PRIMITIVE TYPES");
    print_line(cout, '=', OUTPUT_WIDTH);

    auto integer = new int;
    auto *real = new double;
    auto state = new bool;
    auto character = new char;

    *integer = 123;
    *real = 12.75;
    *state = true;
    *character = 'E';

    cout << "*integer:   " << *integer << endl;
    cout << "*real:      " << *real << endl;
    cout << "*state:     " << *state << endl;
    cout << "*character: " << *character << endl;

    delete integer;
    delete real;
    delete state;
    delete character;

    integer = nullptr;
    real = nullptr;
    state = nullptr;
    character = nullptr;
}

void demo_static_string() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "STATIC STRING");
    print_line(cout, '=', OUTPUT_WIDTH);

    char name[20];

    strcpy(name, "Erasmo");

    cout << "Text: " << name << endl;

    cout << "Starting address: "
         << static_cast<void *>(name)
         << endl;
}

void demo_dynamic_string() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "DYNAMIC STRING");
    print_line(cout, '=', OUTPUT_WIDTH);

    char *course = allocate_string("Programming 2");

    cout << course << endl;

    delete[] course;

    course = nullptr;
}

// ============================================================
// char** means:
//
//     pointer -> pointer -> char
//
// One common use is representing a dynamic array of strings.
// ============================================================
void demo_dynamic_array_strings() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "STATIC ARRAY STRING");
    print_line(cout, '=', OUTPUT_WIDTH);

    int size = 4;

    char **languages = create_string_array(size);

    languages[0] = allocate_string("C");
    languages[1] = allocate_string("C++");
    languages[2] = allocate_string("Java");
    languages[3] = allocate_string("Python");

    for (int i = 0; i < size; i++)
        cout << languages[i] << endl;

    delete_string_array(languages, size);
}

void demo_memory_leak() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "MEMORY LEAK");
    print_line(cout, '=', OUTPUT_WIDTH);

    int *number = new int;

    *number = 100;

    cout << "Value: " << *number << endl;

    number = new int;
    // The first int still exists in memory.
    // But we no longer know its address.

    *number = 200;

    cout << "Value: " << *number << endl;

    delete number; // So this only releases the second pointer and the first is leaked.
    number = nullptr;
}

void demo_correct_reallocation() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "CORRECT REALLOCATION");
    print_line(cout, '=', OUTPUT_WIDTH);

    int *number = new int;

    *number = 10;

    cout << *number << endl;

    // Release the previous object before allocating another one.
    delete number;

    number = nullptr; // Here is the catch!

    number = new int;

    *number = 20;

    cout << *number << endl;

    delete number;

    number = nullptr;
}

void demo_pointer_reference() {
    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "POINTER REFERENCE");
    print_line(cout, '=', OUTPUT_WIDTH);

    int *ptr_number = nullptr;

    allocated_ptr(ptr_number, 100);

    cout << *ptr_number << endl;

    delete ptr_number;

    ptr_number = nullptr;
}
