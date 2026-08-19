#include "Libraries/DemoMemoryAllocation/MemoryAllocation.hpp"
#include "Libraries/Utilities/AuxiliaryFunctions.hpp"

int main() {

    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "MEMORY ALLOCATION DEMO - C++");
    print_line(cout, '=', OUTPUT_WIDTH);

    demo_local_variables();

    demo_pointers();

    demo_dynamic_int();

    demo_dynamic_primitives_types();

    demo_static_string();

    demo_dynamic_string();

    demo_dynamic_array_strings();

    demo_memory_leak();

    demo_correct_reallocation();

    demo_pointer_reference();


    print_line(cout, '=', OUTPUT_WIDTH);
    print_centered_text(cout, "END OF DEMO");
    print_line(cout, '=', OUTPUT_WIDTH);
    return 0;
}
