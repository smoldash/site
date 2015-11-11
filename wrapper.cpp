#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello_ext)
{
	using namespales boost::python;
	def("greet", greet);
}