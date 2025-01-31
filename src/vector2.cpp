#include "vector2.hpp"

namespace Vec{

    Vector2 Vector2Add(Vector2 vec1, Vector2 vec2){
        return Vector2{
            vec1.x + vec2.x,
            vec1.y + vec2.y
        };
    }

}