#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

// PYBIND11_MAKE_OPAQUE(std::vector<int>)

void init_functions(py::module &);
void init_lists_and_vectors(py::module &);
void init_ex3(py::module &);
void init_ex4(py::module &);
void init_ex5(py::module &);
void init_classes(py::module &);
void init_container(py::module &);
void init_class_advanced(py::module &);
void init_call_python(py::module &);

PYBIND11_MODULE(test_package, m)
{
    // py::bind_vector<std::vector<int>>(m, "VectorInt");

    init_functions(m);
    init_lists_and_vectors(m);

    // init_ex3(m);
    // init_ex5(m);
    init_classes(m);

    init_container(m);
    init_class_advanced(m);
    init_call_python(m);
}