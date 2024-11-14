#include "Plane.h"

namespace rt
{
    unsigned int Plane::s_Instance = 0;

    Plane::Plane(point position, glm::vec3 normal, Material material) :
        m_Point(position), m_Normal(normal)
    {
        m_Material = material;
        m_Name += " " + std::to_string(s_Instance);
        ++s_Instance;
    }

    void Plane::Export()
    {
        ImGui::Begin(m_Name.c_str());
        ImGui::DragFloat3("Position", &m_Point.x, 0.01f);
        ImGui::DragFloat3("Normal", &m_Normal.x, 0.01f);
        MaterialExport();
        ImGui::End();
    }

    const HitInfo Plane::Intersection(const Ray& ray) const
    {
        HitInfo hitInfo;
        hitInfo.didHit = false;

        float denom = glm::dot(ray.Direction(), m_Normal);
        if (denom == 0)
            return hitInfo;
        float numerator = glm::dot(m_Point - ray.Origin(), m_Normal);

        float t = numerator / denom;

        if (t < 0)
            return hitInfo;

        hitInfo.didHit = true;
        hitInfo.normal = m_Normal;
        hitInfo.hitPoint = ray.Origin() + t * ray.Direction();
        hitInfo.distance = t;
        hitInfo.material = m_Material;
        hitInfo.hitPoint = hitInfo.hitPoint + hitInfo.normal * 0.00001f;

        return hitInfo;
    }
}
