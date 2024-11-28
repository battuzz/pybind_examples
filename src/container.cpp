#include <vector>
#include <pybind11/pybind11.h>
#include <iostream>

using namespace pybind11::literals;

struct Data
{
    double value1;
    double value2;
};

class Element
{
public:
    Element() = default;
    Element(Data values) : data(values) {}
    Element(const Element &other) : data(other.data)
    {
        std::cout << "copying from " << &other << std::endl;
    }

    Data data;
};

class Container
{
public:
    Container() : data(10, Element(Data{0.1, 0.2})) {};

    Element &operator[](size_t idx) { return data[idx]; }
    const Element &operator[](size_t idx) const { return data[idx]; }

protected:
    std::vector<Element> data;
};

namespace py = pybind11;

void init_container(py::module &m)
{
    py::class_<Data>(m, "Data")
        .def(py::init<double, double>(), "Constructs a new instance", "v1"_a, "v2"_a)
        .def_readwrite("value1", &Data::value1)
        .def_readwrite("value2", &Data::value2);

    py::class_<Element>(m, "Element")
        .def(py::init<Data>(), "Constructs a new instance", "values"_a)
        .def_readwrite("data", &Element::data)
        .def("__repr__", [](const Element &e)
             { return std::to_string(e.data.value1) + ", " + std::to_string(e.data.value2); });

    py::class_<Container>(m, "Container")
        .def(py::init<>(), "Constructs a new instance")
        // .def("__getitem__", [](Container &c, size_t idx) -> Element &
        //      { return c[idx]; }, "idx"_a, py::return_value_policy::reference_internal)
        .def("__getitem__", [](Container &c, size_t idx) -> Element &
             { return c[idx]; }, "idx"_a)
        .def("__setitem__", [](Container &c, size_t idx, const Element &e)
             { c[idx] = e; }, "idx"_a, "val"_a);
}