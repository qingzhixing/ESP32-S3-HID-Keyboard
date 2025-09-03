#pragma once
#ifndef _LERP_H
#define _LERP_H

template <typename T>
T Lerp(T a, T b, float t)
{
	return a + (b - a) * t;
}

#endif //! _LERP_H