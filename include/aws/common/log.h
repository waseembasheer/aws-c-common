#ifndef AWS_COMMON_LOG_H
#define AWS_COMMON_LOG_H

/*
* Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <stdarg.h>

enum aws_log_level
{
    AWS_LOG_LEVEL_OFF   = 0,
    AWS_LOG_LEVEL_FATAL = 1,
    AWS_LOG_LEVEL_ERROR = 2,
    AWS_LOG_LEVEL_WARN  = 3,
    AWS_LOG_LEVEL_TRACE = 4
};

#define AWS_LOG(level, str)
#define AWS_LOG_F(level, fmt, ...)

struct aws_log_message {
    void* memory;
    struct aws_log_message *next;
};

struct aws_log_context {
    struct aws_log_message *message_list;
    struct aws_log_message *delete_list;
    struct aws_memory_pool message_pool;
    struct aws_log_context *next;
};

#ifdef __cplusplus
extern "C" {
#endif

AWS_COMMON_API void aws_log(enum aws_log_level level, const char *fmt, ...);
AWS_COMMON_API const char *aws_log_level_to_string(enum aws_log_level level);
AWS_COMMON_API void aws_log_process();

AWS_COMMON_API void aws_init_logging(struct aws_allocator *alloc, int memory_pool_element_count);
AWS_COMMON_API void aws_shutdown_logging();

#ifdef __cplusplus
}
#endif

#endif /* AWS_COMMON_LOG_H */
