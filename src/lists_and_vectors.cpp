#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <vector>

// PYBIND11_MAKE_OPAQUE(std::vector<int>)

namespace py = pybind11;
using namespace pybind11::literals;

std::vector<double> double_vector(const std::vector<double> &input)
{
    std::vector<double> output;
    output.reserve(input.size());

    for (auto &elem : input)
    {
        output.push_back(2 * elem);
    }

    return output;
}

double double_vectorized(double x)
{
    return x * 2;
}

void append_1(std::vector<int> &v)
{
    v.push_back(1);
}

class MyClass
{
public:
    std::vector<int> contents;
};

void init_lists_and_vectors(py::module &m)
{
    // Simple function binding
    m.def("double_vector", &double_vector, "Doubles all elements in vector");
    m.def("double_vectorized", py::vectorize(double_vectorized));

    // All values are copied
    m.def("append_1", &append_1);
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def_readwrite("contents", &MyClass::contents);
}