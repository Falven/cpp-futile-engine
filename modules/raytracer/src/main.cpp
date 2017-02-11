#include <iostream>
#include <vector>

#include "ray.hpp"
#include "point.hpp"
#include "normal.hpp"
#include "object.hpp"
#include "color.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	cout << "rendering..." << endl;

	int image_width = 640;
	int image_height = 480;

	vector<object> objects;

	// Matrix dimensions of image.
	for (int x = 0; x < image_width; ++x)
	{
		for (int y = 0; y < image_height; ++y)
		{
			ray primary_ray;
			compute_primary_ray(x, y, primary_ray);

			point point_hit;
			normal normal_hit;
			float minimum_distance = INFINITY;

			object object;
			for (int k = 0; k < objects.size(); ++k)
			{
				if (intersect(objects[k], primary_ray, point_hit, normal_hit))
				{
					float distance = distance(eye_position, point_hit);
				}
			}

			// return color
		}
	}

	return 0;
}

void compute_primary_ray(const int x, const int y, const ray & ray)
{

}

bool intersect(const object & object, const ray & primary_ray, const point & point_hit, const normal & normal_hit)
{
	return false;
}

float distance()