/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Exception.cpp
 */

#ifndef SIMPLEX_BASE_EXCEPTION_H
#define SIMPLEX_BASE_EXCEPTION_H

#include <string>

namespace simplex
{
	namespace base
	{
		class Exception
		{
			public:
				Exception();
				Exception(const ::std::string& text);
			
				::std::string Text;
		};

		class IndexOutOfBoundsException : public Exception
		{
			public:
				IndexOutOfBoundsException();
				IndexOutOfBoundsException(const ::std::string& text);
		};

		class NotImplementedException : public Exception
		{
			public:
				NotImplementedException();
				NotImplementedException(const ::std::string& text);
		};

		class NullException : public Exception
		{
			public:
				NullException();
				NullException(const ::std::string& text);
		};
	}
}

#endif // SIMPLEX_BASE_EXCEPTION_H
