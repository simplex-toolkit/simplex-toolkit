/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 * simplex.io.FileExceptions.h
 * simplex.io.StreamReader.cpp
 * simplex.base.String.h
 * simplex.base.String.cpp
 */

#ifndef SIMPLEX_IO_STREAMREADER_H
#define SIMPLEX_IO_STREAMREADER_H

#include <iostream>
#include <memory>
#include "simplex.base.Array.h"
#include "simplex.base.String.h"

namespace simplex
{
	namespace io
	{
		using namespace simplex::base;
		
		class StreamReader
		{
			public:
				StreamReader(const String& stream);
				StreamReader(const ::std::istream& stream);
				bool readLine(String& line);
				Array<String> readAllLines();

				template<typename TypeToRead> TypeToRead readType();
				String read(int numberOfCharacters);
				
				String readCString(); //reads until it hits null
				template<typename PrefixType> String readPrefixedString(PrefixType lengthOfString);

				bool EndOfData;

			protected:
				::std::unique_ptr<::std::istream> streamData;
		};
	}
}

#endif // SIMPLEX_IO_STREAMREADER_H
