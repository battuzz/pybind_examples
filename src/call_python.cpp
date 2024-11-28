#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;
using namespace pybind11::literals;

py::object list_dir_from_python(std::string filter, bool recursive)
{
    py::object glob = py::module_::import("glob").attr("glob");
    auto result = glob(filter, "recursive"_a = recursive);
    return result;
}

void init_call_python(py::module &m)
{
    m.def("list_dir_from_python", &list_dir_from_python, "Make a directory from python");
}