#include <pybind11/pybind11.h>
#include <iostream>
#include <sstream>

namespace py = pybind11;
using namespace pybind11::literals;

int add(int a, int b)
{
    return a + b;
}

double mul(double a, double b)
{
    std::cout << "Double" << std::endl;
    return a * b;
}

int mul(int a, int b)
{
    std::cout << "Int" << std::endl;
    return a * b;
}

template <typename T>
T divide(T t1, T t2)
{
    return t1 / t2;
}

void print_dict(const py::dict &dict)
{
    std::stringstream out;
    for (auto item : dict)
    {
        out << "key=" << std::string(py::str(item.first)) << ", "
            << "value=" << std::string(py::str(item.second));
        py::print(out.str());
    }
}

void init_functions(py::module &m)
{
    // Simple function binding
    m.def("add", &add, "Adds two numbers");

    // Adding keyword arguments with defaults
    m.def("add_with_arguments", &add, "i"_a = 7, "j"_a = 3);

    // Overloads
    m.def("mul", py::overload_cast<int, int>(&mul));
    m.def("mul", py::overload_cast<double, double>(&mul));

    // Templates
    m.def("divide", &divide<double>, "Divide on double");
    m.def("divide", &divide<int>, "Divide on double");

    // Python types
    m.def("print_dict", &print_dict, "Prints dictionaries");
}