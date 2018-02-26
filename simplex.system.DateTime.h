/* License: 3-Clause BSD
 * Required Includes:
 * simplex.system.DateTime.cpp
 */

#ifndef SIMPLEX_SYSTEM_DATETIME_H
#define SIMPLEX_SYSTEM_DATETIME_H

#include <ctime>

namespace simplex
{
	namespace system
	{
		class DateTime
		{
			public:
				static int localSecond();
				static int localMinute();
				static int local24Hour();
				static int local12Hour();
				static int localAmPm();
				static int localDay();
				static int localMonth();
				static int localYY();
				static int localYYYY();
				static bool isDST();

				static int utcSecond();
				static int utcMinute();
				static int utc24Hour();
				static int utc12Hour();
				static int utcAmPm();
				static int utcDay();
				static int utcMonth();
				static int utcYY();
				static int utcYYYY();

				static int currentCentury();

			private:
				DateTime() {}
				static struct tm* getLocal();
				static struct tm* getUtc();
		};
	}
}

#endif //SIMPLEX_SYSTEM_DATETIME_H
