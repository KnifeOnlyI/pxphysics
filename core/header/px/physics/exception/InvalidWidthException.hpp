#include "BaseException.hpp"

namespace px::physics
{
class InvalidWidthException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(InvalidWidthException)

    EMPTY_FORMAT_CONSTRUCTOR(InvalidWidthException)

    BASIC_CONSTRUCTOR(InvalidWidthException)

    FORMAT_CONSTRUCTOR(InvalidWidthException)
};
}