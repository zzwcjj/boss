/* 
 * Logger.h
 *
 * Better Oblivion Sorting Software
 *
 * Quick and Dirty Load Order Utility
 * (Making C++ look like the scripting language it isn't.)
 *
 * Copyright (C) 2009-2010  Random/Random007/jpearce & the BOSS development team
 * http://creativecommons.org/licenses/by-nc-nd/3.0/
 *
 * $Revision: 1783 $, $Date: 2010-10-31 23:05:28 +0000 (Sun, 31 Oct 2010) $
 */

#ifndef __SUPPORT_LOGGER__HPP__
#define __SUPPORT_LOGGER__HPP__

#include "Platform.h"
#include <stdarg.h>


#define _LOG_IMPL(verbosity, formatStr, ...) \
	boss::g_logger.log(verbosity, __FILE__, __LINE__, formatStr, ##__VA_ARGS__)

// convenience macros
#define LOG_ERROR(formatStr, ...) _LOG_IMPL(boss::LV_ERROR, formatStr, ##__VA_ARGS__)
#define LOG_WARN(formatStr,  ...) _LOG_IMPL(boss::LV_WARN,  formatStr, ##__VA_ARGS__)
#define LOG_INFO(formatStr,  ...) _LOG_IMPL(boss::LV_INFO,  formatStr, ##__VA_ARGS__)
#define LOG_DEBUG(formatStr, ...) _LOG_IMPL(boss::LV_DEBUG, formatStr, ##__VA_ARGS__)
#define LOG_TRACE(formatStr, ...) _LOG_IMPL(boss::LV_TRACE, formatStr, ##__VA_ARGS__)


namespace boss
{
	enum LogVerbosity
	{
		LV_OFF   = 0,
		LV_ERROR = 1,
		LV_WARN  = 2,
		LV_INFO  = 3,
		LV_DEBUG = 4,
		LV_TRACE = 5
	};

	// A simple logging class.  Not implemented to be thread safe.
	class Logger
	{
	public:
		Logger();

		// sets the verbosity limit
		void setVerbosity (LogVerbosity verbosity);

		// sets whether filename and line number will be output with each message
		void setOriginTracking (bool enabled);

		// for use when calculating the arguments to a LOG macro would be expensive
		inline bool isDebugEnabled () { return _isVerbosityEnabled(LV_DEBUG); }
		inline bool isTraceEnabled () { return _isVerbosityEnabled(LV_TRACE); }

		// if a message is of a sufficient verbosity, outputs the given message
		inline void log (LogVerbosity verbosity, const char * fileName,
						 int lineNo, const char * formatStr, ...) __attribute__((__format__ (__printf__, 5, 6)))
		{
			if (_isVerbosityEnabled(verbosity))
			{
				va_list ap;
				va_start(ap, formatStr);
				_log(verbosity, fileName, lineNo, formatStr, ap);
				va_end(ap);
			}
		}

	private:
		LogVerbosity m_verbosity;
		bool         m_originTracking;

	private:
		inline bool _isVerbosityEnabled (LogVerbosity verbosity)
		{
			return verbosity <= m_verbosity;
		}

		void _log (LogVerbosity verbosity, const char * fileName, 
				   int lineNo, const char * formatStr, va_list ap);
	};

	// declare global logger
	extern Logger g_logger;
}

#endif // __SUPPORT_LOGGER__HPP__
