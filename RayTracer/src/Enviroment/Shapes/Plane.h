#include "Shape.h"
#include <string>

namespace rt
{
	class Plane : public Shape
	{
	public:
		Plane(point position, glm::vec3 normal, Material material);
		void Export() override;
		const HitInfo Intersection(const Ray& ray) const override;

	private:
		std::string m_Name = "Plane";
		point m_Point;
		glm::vec3 m_Normal;
		static unsigned int s_Instance;
	};
}