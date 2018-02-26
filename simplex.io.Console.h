/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.io.Console.cpp
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 * simplex.base.String.cpp
 */

#ifndef SIMPLEX_IO_CONSOLE_H
#define SIMPLEX_IO_CONSOLE_H

#include <iostream>
#include "simplex.base.String.h"

namespace simplex
{
	namespace io
	{
		using namespace simplex::base;

		class Console
		{
			public:
				void static write(const String& text);
				void static writeLine(const String& text);
				void static writeStderr(const String& text);
				void static writeStderrLine(const String& text);
				String static read();
				String static read(const String& defaultIfBlank);
				String static prompt(const String& output);
				String static prompt(const String& output, const String& defaultIfBlank);
		};
	}
}

#endif // SIMPLEX_IO_CONSOLE_H
