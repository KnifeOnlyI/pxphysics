#include "BaseException.hpp"

namespace px::physics
{
class InvalidRadiusException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(InvalidRadiusException)

    EMPTY_FORMAT_CONSTRUCTOR(InvalidRadiusException)

    BASIC_CONSTRUCTOR(InvalidRadiusException)

    FORMAT_CONSTRUCTOR(InvalidRadiusException)
};
}