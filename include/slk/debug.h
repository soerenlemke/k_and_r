//
// slk/debug.h
// Created by soerenlemke on 06.01.26.
//

#pragma once

#include <stdio.h>   // fprintf, vfprintf, stderr
#include <stdarg.h>  // va_list, va_start, va_end


#ifndef SLK_ENABLE_LOG
#ifndef NDEBUG
#define SLK_ENABLE_LOG 1
#else
#define SLK_ENABLE_LOG 0
#endif
#endif

#if defined(__clang__) || defined(__GNUC__)
#define SLK_PRINTF_FMT(fmt_index, first_va_index) __attribute__((format(printf, fmt_index, first_va_index)))
#define SLK_MAYBE_UNUSED __attribute__((unused))
#else
#define SLK_PRINTF_FMT(fmt_index, first_va_index)
#define SLK_MAYBE_UNUSED
#endif

static inline SLK_MAYBE_UNUSED void
slk__logf(FILE *out,
          const char *level,
          const char *file,
          int line,
          const char *func,
          const char *fmt, ...) SLK_PRINTF_FMT(6, 7);

static inline SLK_MAYBE_UNUSED void
slk__logf(FILE *out,
          const char *level,
          const char *file,
          int line,
          const char *func,
          const char *fmt, ...) {
    fprintf(out, "[%s] %s:%d (%s): ", level, file, line, func);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(out, fmt, ap);
    va_end(ap);

    fputc('\n', out);
}

/* --- Public API -------------------------------------------------------- */
#define SLK_TODO(msg) do { \
    slk__logf(stderr, "TODO", __FILE__, __LINE__, __func__, "%s", (msg)); \
    abort(); \
} while (0)

#define SLK_PANIC(msg) do { \
    slk__logf(stderr, "PANIC", __FILE__, __LINE__, __func__, "%s", (msg)); \
    abort(); \
} while (0)

#define SLK_PANICF(fmt, ...) do { \
    slk__logf(stderr, "PANIC", __FILE__, __LINE__, __func__, (fmt), __VA_ARGS__); \
    abort(); \
} while (0)

#if SLK_ENABLE_LOG
#define SLK_LOG(msg) \
      slk__logf(stderr, "LOG", __FILE__, __LINE__, __func__, "%s", (msg))

#define SLK_LOGF(fmt, ...) \
      slk__logf(stderr, "LOG", __FILE__, __LINE__, __func__, (fmt), __VA_ARGS__)
#else
#define SLK_LOG(...) ((void)0)
#define SLK_LOGF(...) ((void)0)
#endif

#define SLK_ASSERT(cond) do { \
    if (!(cond)) { \
        slk__logf(stderr, "ASSERT", __FILE__, __LINE__, __func__, "Condition failed: %s", #cond); \
        abort(); \
    } \
} while (0)

#define SLK_UNREACHABLE() do { \
    slk__logf(stderr, "UNREACHABLE", __FILE__, __LINE__, __func__, "%s", "Reached unreachable code"); \
    abort(); \
} while (0)

