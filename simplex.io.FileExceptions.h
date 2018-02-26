/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 */

#ifndef SIMPLEX_IO_FILEEXCEPTIONS_H
#define SIMPLEX_IO_FILEEXCEPTIONS_H

#include "simplex.base.Exception.h"

namespace simplex
{
	namespace io
	{
		using namespace simplex::base;
		
		class IOException : public Exception
		{
		public:
			IOException() { }
			IOException(const ::std::string& text) : Exception(text) { }
		};
	}
}

#endif // SIMPLEX_IO_FILEEXCEPTIONS_H
