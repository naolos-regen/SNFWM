#include "../../include/logger.h"

void _log(int level, const char *file, int line, const char *format, ...)
{
	char timestamp[64];
	time_t now;
	struct tm* local_time;

	time(&now);
	local_time = localtime(&now);
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local_time);

	fprintf(stderr, "%s :: %s%s%s :: %s:%d - ",
		timestamp,
		level_colors[level],
		level_strings[level],
		COLOR_RESET,
		file,
		line
	);

	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);

	fprintf(stderr, "\n");
}
