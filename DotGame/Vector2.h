#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator + (Vector2 const &vec2) {
		Vector2 result;
		result.x = x + vec2.x;
		result.y = y + vec2.y;
		return result;
	}

	Vector2 operator - (Vector2 const &vec2) {
		Vector2 result;
		result.x = x - vec2.x;
		result.y = y - vec2.y;
		return result;
	}

	Vector2 operator / (float const &f) {
		Vector2 result;
		result.x = x/f;
		result.y = y/f;
		return result;
	}

public:
	float x = 0.0f;
	float y = 0.0f;
};

#endif // VECTOR2_H