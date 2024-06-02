#include "../StrongType.hpp"

// addable and printable only with other Meter
template <typename T>
using Meter = StrongType<T, struct MeterTag, Addable, Printable, Swappable>;

// addable and printable only with other Kilometer
template <typename T>
using Kilometer = StrongType<T, struct KilometerTag, Addable, Printable, Swappable>;

// non-addable
using Surname = StrongType<std::string, struct SurnameTag, Printable, Swappable>;

int main()
{
    auto meter1 = Meter<long>{ 30L };
    auto meter2 = Meter<long>{ 40L };
    auto meter3 = meter1 + meter2;
    std::cout << "meter3: " << meter3.get() << '\n';
    swap(meter1, meter2);
    std::cout << "meter2: " << meter2.get() << '\n';

    Surname jane{ "Doe" };
    Surname john{ "Wick" };
    // auto strange = jane + john; // ERROR - no operator+
}