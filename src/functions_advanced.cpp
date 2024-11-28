// #include <pybind11/pybind11.h>

// namespace py = pybind11;
// using namespace pybind11::literals;

// class IntType
// {
//     int a = 3;
// };

// static IntType static_data();

// IntType *return_reference()
// {
//     return &static_data;
// }

// void init_ex3(py::module &m)
// {
//     // Simple function binding
//     m.def("return_reference", &return_reference, "Returns a reference of IntType");
// }