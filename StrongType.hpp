#ifndef __STRONGTYPE_H__
#define __STRONGTYPE_H__

#include <iostream>

// use CRTP as implementation (not design) pattern for mixin
// to provide *ables for StrongType
// use of variadic template, phantom type (tag)

template <typename Derived> // CRTP
struct Comparable
{
    // hidden friends
    friend bool operator==(const Derived& lhs, const Derived& rhs) {
        return lhs.get() == rhs.get();
    }
};

template <typename Derived> // CRTP
struct Addable
{
    // hidden friends
    friend Derived& operator+=(Derived& lhs, Derived& rhs) {
        lhs.get() += rhs.get();
        return lhs;
    }
    friend Derived operator+(Derived const& lhs, Derived const& rhs) {
        return Derived{ lhs.get() + rhs.get() };
    }
};

template <typename Derived> // CRTP
struct Printable
{
    friend std::ostream& operator<<(std::ostream& os, const Derived& d) {
        os << d.get();
        return os;
    }
};

template <typename Derived> // CRTP
struct Swappable
{
    friend void swap(Derived& lhs, Derived& rhs) {
        using std::swap; // enable ADL
        swap(lhs.get(), rhs.get());
    }
};

// use variadic template to provide CRTP mixin for *ables (skills)
template <typename T, typename Tag, template<typename> class... Skills>
class StrongType : private Skills<StrongType<T,Tag,Skills...>>...
{
public:
    using value_type = T;
    StrongType(T const& value) : value_{value} { std::cout << "copy ctor" << '\n'; }
    StrongType(T&& value) : value_{std::move(value)} { std::cout << "move ctor" << '\n'; }

    T& get() { return value_; }
    T const& get() const { return value_; }

private:
    T value_;
};

#endif // __STRONGTYPE_H__