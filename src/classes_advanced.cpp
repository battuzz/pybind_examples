#include <pybind11/pybind11.h>
#include <string>

class Animal
{
public:
    virtual ~Animal() {}
    virtual std::string make_sound(int n_times) = 0;
};

class Cat : public Animal
{
public:
    std::string make_sound(int n_times) override
    {
        std::string result;
        for (int i = 0; i < n_times; ++i)
            result += "Meow! ";
        return result;
    }
};

class PyAnimal : public Animal
{
public:
    /* Inherit the constructors */
    using Animal::Animal;

    /* Trampoline (need one for each virtual function) */
    std::string make_sound(int n_times) override
    {
        PYBIND11_OVERRIDE_PURE(
            std::string, /* Return type */
            Animal,      /* Parent class */
            make_sound,  /* Name of function in C++ (must match Python name) */
            n_times      /* Argument(s) */
        );
    }
};

std::string make_animal_sound(Animal *animal)
{
    return animal->make_sound(3);
}

namespace py = pybind11;

void init_class_advanced(py::module &m)
{
    py::class_<Animal, PyAnimal>(m, "Animal")
        .def(py::init<>())
        .def("make_sound", &Animal::make_sound);

    py::class_<Cat, Animal>(m, "Cat")
        .def(py::init<>());

    m.def("make_animal_sound", &make_animal_sound);
}