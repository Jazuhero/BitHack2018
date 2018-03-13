#ifndef ASSERT_H
#define ASSERT_H
#include <iostream>
#include <cstdlib>

#define ASSERT_X(assertion, msg) \
    if (!(assertion)) { \
        std::cout << "Internal error. ASSERT(" << #assertion << "): " << msg; \
        std::abort(); \
    }

#define ASSERT(assertion) ASSERT_X(assertion, "")

#endif //ASSERT_H

