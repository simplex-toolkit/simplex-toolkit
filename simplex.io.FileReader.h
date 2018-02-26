/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 * simplex.io.FileExceptions.h
 * simplex.io.FileReader.cpp
 * simplex.io.StreamReader.h
 * simplex.io.StreamReader.cpp
 * simplex.base.String.h
 * simplex.base.String.cpp
 */

#ifndef SIMPLEX_IO_FILEREADER_H
#define SIMPLEX_IO_FILEREADER_H

#include <fstream>
#include <memory>
#include "simplex.base.Array.h"
#include "simplex.base.String.h"
#include "simplex.io.StreamReader.h"

namespace simplex
{
	namespace io
	{
		using namespace simplex::base;
		
		class FileReader
		{
			public:
				FileReader();
				FileReader(const String& fileName);
				virtual ~FileReader() {}
				void setFileName(const String& fileName);
				bool readLine(String& line);
				Array<String> readAllLines();

				template<typename TypeToRead> TypeToRead readType();
				String read(int numberOfCharacters);
				
				String readCString(); //reads until it hits null
				template<typename PrefixType> String readPrefixedString(PrefixType lengthOfString);

				bool EndOfFile;

			protected:
				::std::unique_ptr<StreamReader> readFile;
				bool readIsOpen = false;
				void open();
				String fileName_ = "";
		};
	}
}

#endif // SIMPLEX_IO_FILEREADER_H
