struct vector3d
{
	double x, y, z;

	inline vector3d() {}
	inline vector3d(const double x, const double y, const double z) : x(x), y(y), z(z) {}

	inline vector3d operator+(const vector3d & other) const
	{
		return vector3d(x + other.x, y + other.y, z + other.z);
	}

	inline vector3d operator+(const double other) const
	{
		return vector3d(x + other, y + other, z + other);
	}

	inline double dot(const vector3d & other) const
	{
		return other.x * x + other.y * y + other.z * z;
	}
};