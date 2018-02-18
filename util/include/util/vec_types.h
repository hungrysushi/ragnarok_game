#pragma once

#include <ostream>

template <typename T>
struct vec2 {
        T x = 0.0;
        T y = 0.0;

        bool operator==(const vec2<T>& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y);
        }
};

template <typename T>
struct vec3 {
        T x = 0.0;
        T y = 0.0;
        T z = 0.0;

        bool operator==(const vec3<T>& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y) &&
                        (this->z == rhs.z);
        }

        /* friend ostream& operator<<(ostream& os, const vec3<T>& rhs); */
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const vec3<T> rhs) {
        os << "x: " << rhs.x << ", "
           << "y: " << rhs.y << ", "
           << "z: " << rhs.z;

        return os;
}


template <typename T>
struct vec4 {
        T x = 0.0;
        T y = 0.0;
        T z = 0.0;
        T w = 0.0;

        bool operator==(const vec4<T>& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y) &&
                        (this->z == rhs.z) &&
                        (this->w == rhs.w);
        }
};
