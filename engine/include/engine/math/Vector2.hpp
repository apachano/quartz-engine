#pragma once

namespace phx {

	struct Vector2 {
		float x;
		float y;

		Vector2();
		Vector2(const float& x, const float& y);
		Vector2(const float& a);
	};

	template <typename T>
	struct TVector2 {
		T x, y;

		TVector2(const T& x, const T& y) : x(x), y(y) {}
	};
}
