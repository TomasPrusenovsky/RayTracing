#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <glm/glm.hpp>

namespace rt {

    class Random
    {
    public:
        static void Init()
        {
            s_RandomEngine.seed(std::random_device()());
        }

        static uint32_t UInt()
        {
            return s_Distribution(s_RandomEngine);
        }

        static uint32_t UInt(uint32_t min, uint32_t max)
        {
            return min + (s_Distribution(s_RandomEngine) % (max - min + 1));
        }

        static uint32_t PCG_Hash(uint32_t input) {
            uint32_t state = input * 747796405u + 2891336453u;
            uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
            return (word >> 22u) ^ word;
        }

        static float Float()
        {
            return static_cast<float>(s_Distribution(s_RandomEngine)) / static_cast<float>(std::numeric_limits<uint32_t>::max());
        }

        static float Float(uint32_t& seed) {
            seed = PCG_Hash(seed);
            return (float)seed / (float)std::numeric_limits<uint32_t>::max();
        }

        //float between min and max
        static float Float2(float min, float max)
        {
            return (max - min) * Float() + min;
        }

        static glm::vec2 Vec2(float min, float max)
        {
            return { Float2(min, max), Float2(min, max) };
        }

        static glm::vec3 Vec3()
        {
            return {Float(), Float(), Float()};
        }

        static glm::vec3 Vec3(float min, float max)
        {
            return {Float() * (max - min) + min, Float() * (max - min) + min, Float() * (max - min) + min};
        }

        static glm::vec3 InUnitSphere(uint32_t& seed)
        {
            return glm::normalize(glm::vec3(
                Float(seed) * 2.0f - 1.0f,
                Float(seed) * 2.0f - 1.0f,
                Float(seed) * 2.0f - 1.0f
            ));
        }
    private:
        static thread_local std::mt19937 s_RandomEngine;
        static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
    };

} // rt

#endif //RANDOM_H
