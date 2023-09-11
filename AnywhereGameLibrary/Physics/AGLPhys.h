#ifndef AGL_AGLPHYS_H
#define AGL_AGLPHYS_H

#include <glm/gtc/matrix_transform.hpp>
#include <optional>
#include <vector>
#include "../Objects/3D/Cube/Cube.h"

struct vector3 {
    vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float x;
    float y;
    float z;

    vector3 operator+= (const float& val) {
        vector3::x += val;
        vector3::y += val;
        vector3::z += val;
    }

    vector3 operator+= (const vector3& val) {
        vector3::x += val.x;
        vector3::y += val.y;
        vector3::z += val.z;
    }

    vector3 operator/ (const float& val) {
        vector3::x / val;
        vector3::y / val;
        vector3::z / val;
    }

    vector3 operator* (const float& val) {
        vector3::x * val;
        vector3::y * val;
        vector3::z * val;
    }
};

struct Object {
    Cube* c_object;
    vector3 Position;
    vector3 Velocity;
    vector3 Force;
    float Mass;
};

struct CollisionPoints {
    std::vector<glm::vec3> points;
};

struct Collision {
    CollisionPoints points;
    Object* objA;
    Object* objB;
};

class Physics {
private:
    std::vector<Object*> objects;
    float gravity = -9.81f;
public:
    void AddObject(Object* object) {
        objects.push_back(object);
    }

    void RemoveObject(Object* object) {
        if (!object) return;
        auto itr = std::find(objects.begin(), objects.end(), object);
        if (itr == objects.end()) return;
        objects.erase(itr);
    }

    void Step(float dt) {
        for (Object* obj : objects) {
            obj->Force.operator+=(obj->Mass * gravity);

            obj->Velocity.operator+=(obj->Force / obj->Mass * dt);
            obj->Position += obj->Velocity * dt;

            obj->Force = vector3(0, 0, 0);

        }
    }
};

#endif
