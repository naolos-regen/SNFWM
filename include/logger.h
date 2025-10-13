#ifndef SCFWM_LOGGER_H
#define SCFWM_LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <time.h>


enum {
	LOG_DEBUG,
	LOG_TEST,
	LOG_INFO,
	LOG_ERROR,
	LOG_WARN,
	LOG_FATAL
};


extern void _log (int level, const char* file, int line, const char* format, ...);

#define __LOG(level, ...) _log(level, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) __LOG(LOG_DEBUG, __VA_ARGS__)
#define log_test(...)  __LOG(LOG_TEST,  __VA_ARGS__)
#define log_info(...)  __LOG(LOG_INFO,  __VA_ARGS__)
#define log_error(...) __LOG(LOG_ERROR, __VA_ARGS__)
#define log_warn(...)  __LOG(LOG_WARN,  __VA_ARGS__)
#define log_fatal(...) __LOG(LOG_FATAL, __VA_ARGS__)

#endif
