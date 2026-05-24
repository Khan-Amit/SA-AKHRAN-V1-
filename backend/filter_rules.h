// filter_rules.h – Common pattern matching rules for all three tiers

#ifndef FILTER_RULES_H
#define FILTER_RULES_H

#include <string.h>

// is_ripe pattern matching (ternary, nonce range, last hex digit)
static inline int is_ripe(const char *line) {
    if (strlen(line) < 10) return 0;
    // Add your custom pattern logic here
    // Example: check for known spam signatures, flood patterns, etc.
    return 1;
}

// Rate limiting helper
static inline int is_rate_limited(unsigned long count, unsigned long limit) {
    return count > limit;
}

#endif
