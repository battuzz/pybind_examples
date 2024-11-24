#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11::literals;

int add(int a, int b)
{
    return a + b;
}

void init_ex1(py::module &m)
{
    // Simple function binding
    m.def("add", &add, "Adds two numbers");

    // Adding keyword arguments with defaults
    m.def("add2", &add, "i"_a = 7, "j"_a = 3);
}