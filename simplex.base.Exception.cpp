#include "simplex.base.Exception.h"

namespace simplex
{
	namespace base
	{
		Exception::Exception() {	}
		Exception::Exception(const ::std::string& text) : Text(text) { }

		IndexOutOfBoundsException::IndexOutOfBoundsException() { }
		IndexOutOfBoundsException::IndexOutOfBoundsException(const ::std::string& text) : Exception(text) { }

		NotImplementedException::NotImplementedException() { }
		NotImplementedException::NotImplementedException(const ::std::string& text) : Exception(text) { }
		
		NullException::NullException() { }
		NullException::NullException(const ::std::string& text) : Exception(text) { }
	}
}
