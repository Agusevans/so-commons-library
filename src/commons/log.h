/*
 * Copyright (C) 2012 Sistemas Operativos - UTN FRBA. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <sys/types.h>
#include "string.h"


typedef enum {
	LOG_LEVEL_TRACE,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR
}t_log_level;

typedef struct {
	FILE* file;
	bool is_active_console;
	t_log_level detail;
	t_string program_name;
	pid_t pid;
}t_log_object;

typedef t_log_object* t_logger;

t_logger log_create(char* file, t_string program_name, bool is_active_console, t_log_level level);
void log_destroy(t_logger logger);

void log_trace(t_logger logger, const char* message, ...);
void log_debug(t_logger logger, const char* message, ...);
void log_info(t_logger logger, const char* message, ...);
void log_warning(t_logger logger, const char* message, ...);
void log_error(t_logger logger, const char* message, ...);

t_string log_level_as_string(t_log_level level);
t_log_level log_level_from_string(t_string level);

#endif /* LOG_H_ */