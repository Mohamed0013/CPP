#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* original = new Data();
    original->id = 1;
    original->name = "SomeData";
    original->value = 42;

    std::cout << "=== Original pointer ===\n";
    std::cout << "Address : " << original << "\n";
    std::cout << "id      : " << original->id << "\n";
    std::cout << "name    : " << original->name << "\n";
    std::cout << "value   : " << original->value << "\n";

    // Pointer => integer
    uintptr_t raw = Serializer::serialize(original);

    std::cout << "\n=== Serialized (as integer) ===\n";
    std::cout << "Raw value : " << raw << "\n";

    // Integer => pointer
    Data* restored = Serializer::deserialize(raw);

    std::cout << "\n=== Restored pointer ===\n";
    std::cout << "Address : " << restored << "\n";
    std::cout << "id      : " << restored->id << "\n";
    std::cout << "name    : " << restored->name << "\n";
    std::cout << "value   : " << restored->value << "\n";

    std::cout << "\n=== Verification ===\n";
    if (original == restored)
        std::cout << "Round-trip successful!\n";
    else
        std::cout << "Something went wrong.\n";

    delete original;
    return 0;
}