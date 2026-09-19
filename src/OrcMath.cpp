#include "OrcMath.h"

std::ostream &operator<< (std::ostream &stream, const Vector2D &vector)
{
	stream << "{ x: " << vector.x << ", y: " << vector.y << " }";
	return stream;
}