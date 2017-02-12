struct vector3d
{
	float x, y, z;

	inline vector3d() {}
	inline vector3d(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Vector addition operation. </summary>
	///
	/// <remarks>	Falven, 2/12/2017. </remarks>
	///
	/// <param name="other">	The other vector. </param>
	///
	/// <returns>	The result of adding the two vectors. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	inline vector3d operator+(const vector3d & other) const
	{
		return vector3d(x + other.x, y + other.y, z + other.z);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Scalar-vector addition. </summary>
	///
	/// <remarks>	Falven, 2/12/2017. </remarks>
	///
	/// <param name="other">	The scalar. </param>
	///
	/// <returns>	The resulting vector of the operation. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	inline vector3d operator+(const float other) const
	{
		return vector3d(x + other, y + other, z + other);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Scalar-vector multiplication. </summary>
	///
	/// <remarks>	Falven, 2/12/2017. </remarks>
	///
	/// <param name="other">	The scalar. </param>
	///
	/// <returns>	The resulting vector of the operation. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	inline vector3d operator*(const float other) const
	{
		return vector3d(x * other, y * other, z * other);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The dot product of two vectors. </summary>
	///
	/// <remarks>	Falven, 2/12/2017. </remarks>
	///
	/// <param name="other">	The other vector. </param>
	///
	/// <returns>	The result of the dot product of two vectors. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	inline float dot(const vector3d & other) const
	{
		return other.x * x + other.y * y + other.z * z;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Whethere these two vectors are orthogonal. </summary>
	///
	/// <remarks>	Falven, 2/12/2017. </remarks>
	///
	/// <param name="other">	The other vector. </param>
	///
	/// <returns>	True if orthogonal, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	inline bool is_orthogonal(const vector3d & other) const
	{
		return this->dot(other) == 0;
	}
};