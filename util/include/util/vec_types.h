#pragma once

struct vec2 {
        float x = 0.0;
        float y = 0.0;

        bool operator==(const vec2& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y);
        }
};

struct vec3 {
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;

        bool operator==(const vec3& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y) &&
                        (this->z == rhs.z);
        }
};

struct vec4 {
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
        float w = 0.0;

        bool operator==(const vec4& rhs) const {
                return  (this->x == rhs.x) &&
                        (this->y == rhs.y) &&
                        (this->z == rhs.z) &&
                        (this->w == rhs.w);
        }
};
