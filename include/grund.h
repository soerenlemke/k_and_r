//
// grund.h
//
// "grund": foundation / base (Scandinavian)
//
// Small, fundamental utilities for C.
//

#pragma once

#include <stdio.h>
#include <stdarg.h>

/* =========================================================================
 * Configuration
 * ========================================================================= */

#ifndef GRUND_ENABLE_LOG
#ifndef NDEBUG
#define GRUND_ENABLE_LOG 1
#else
#define GRUND_ENABLE_LOG 0
#endif
#endif

/* =========================================================================
 * Attributes
 * ========================================================================= */

#if defined(__clang__) || defined(__GNUC__)
#define GRUND_PRINTF_FMT(fmt_index, first_va_index) \
      __attribute__((format(printf, fmt_index, first_va_index)))
#define GRUND_MAYBE_UNUSED __attribute__((unused))
#else
#define GRUND_PRINTF_FMT(fmt_index, first_va_index)
#define GRUND_MAYBE_UNUSED
#endif

/* =========================================================================
 * Internal helper (header-only, intentionally static)
 * ========================================================================= */

static inline GRUND_MAYBE_UNUSED void
grund__logf(FILE *out,
            const char *level,
            const char *file,
            int line,
            const char *func,
            const char *fmt, ...) GRUND_PRINTF_FMT(6, 7);

static inline GRUND_MAYBE_UNUSED void
grund__logf(FILE *out,
            const char *level,
            const char *file,
            const int line,
            const char *func,
            const char *fmt, ...) {
    fprintf(out, "[%s] %s:%d (%s): ", level, file, line, func);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(out, fmt, ap);
    va_end(ap);

    fputc('\n', out);
}

/* =========================================================================
 * Public API
 * ========================================================================= */

/* mark a TODO */
#define GRUND_TODO(msg) do { \
    grund__logf(stderr, "TODO", __FILE__, __LINE__, __func__, "%s", (msg)); \
    abort(); \
} while (0)

/* Hard failure */
#define GRUND_PANIC(msg) do { \
    grund__logf(stderr, "PANIC", __FILE__, __LINE__, __func__, "%s", (msg)); \
    abort(); \
} while (0)

/* printf-style panic (requires at least one vararg) */
#define GRUND_PANICF(fmt, ...) do { \
    grund__logf(stderr, "PANIC", __FILE__, __LINE__, __func__, (fmt), __VA_ARGS__); \
    abort(); \
} while (0)

#if GRUND_ENABLE_LOG
#define GRUND_LOG(msg) \
      grund__logf(stderr, "LOG", __FILE__, __LINE__, __func__, "%s", (msg))

#define GRUND_LOGF(fmt, ...) \
      grund__logf(stderr, "LOG", __FILE__, __LINE__, __func__, (fmt), __VA_ARGS__)
#else
#define GRUND_LOG(...) ((void)0)
#define GRUND_LOGF(...) ((void)0)
#endif

/* Assertion that is always active */
#define GRUND_ASSERT(cond) do { \
    if (!(cond)) { \
        grund__logf(stderr, "ASSERT", __FILE__, __LINE__, __func__, \
                    "Condition failed: %s", #cond); \
        abort(); \
    } \
} while (0)

/* Explicit unreachable marker */
#define GRUND_UNREACHABLE() do { \
    grund__logf(stderr, "UNREACHABLE", __FILE__, __LINE__, __func__, \
                "%s", "Reached unreachable code"); \
    abort(); \
} while (0)
