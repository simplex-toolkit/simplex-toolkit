/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 * simplex.io.FileExceptions.h
 * simplex.io.FileWriter.cpp
 * simplex.base.String.h
 * simplex.base.String.cpp
 */

#ifndef SIMPLEX_IO_FILEWRITER_H
#define SIMPLEX_IO_FILEWRITER_H

#include <fstream>
#include <memory>
#include "simplex.base.String.h"

namespace simplex
{
	namespace io
	{
		using namespace simplex::base;
		
		class FileWriter
		{
			public:
				FileWriter();
				FileWriter(const String& fileName);
				virtual ~FileWriter();
				void setFileName(const String& fileName);
				void writeLine(const String& toWrite);
				void write(const String& toWrite);
				void writeAllLines(Array<String>& toWrite);


			protected:
				::std::unique_ptr<::std::ofstream> writeFile;
				bool writeIsOpen = false;
				void open();
				String fileName_ = "";
		};
	}
}

#endif // SIMPLEX_IO_FILEWRITER_H
