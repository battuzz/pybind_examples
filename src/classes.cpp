#include <pybind11/pybind11.h>
#include <sstream>
#include <string>
#include <iostream>

class Pet
{
public:
    Pet(const std::string &name) : name(name) {}
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string pet(int times)
    {
        std::stringstream ret;
        ret << "This pet was pet " << times << " times!";

        return ret.str();
    }

private:
    std::string name;
};

class Dog : public Pet
{
public:
    Dog(const std::string &name) : Pet(name) {}
    std::string bark() const { return "woof!"; }
};

/* Polynorphism */
struct PolymorphicPet
{
    virtual ~PolymorphicPet() = default;
};

struct PolymorphicDog : PolymorphicPet
{
    std::string bark() const { return "woof!"; }
};

/* Bindings */

namespace py = pybind11;

void init_classes(py::module &m)
{
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def_property("name", &Pet::getName, &Pet::setName)
        .def("pet", &Pet::pet, "pet the Pet")
        .def("__repr__",
             [](const Pet &a)
             {
                 return "<test_package.Pet named '" + a.getName() + "'>";
             });

    py::class_<Dog, Pet>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);

    m.def("pet_store", []()
          { return std::unique_ptr<Pet>(new Dog("Molly")); });

    /* Polymorphism */
    py::class_<PolymorphicPet>(m, "PolymorphicPet");
    py::class_<PolymorphicDog, PolymorphicPet>(m, "PolymorphicDog")
        .def(py::init<>())
        .def("bark", &PolymorphicDog::bark);

    // Again, return a base pointer to a derived instance
    m.def("pet_store2", []()
          { return std::unique_ptr<PolymorphicPet>(new PolymorphicDog); });
}