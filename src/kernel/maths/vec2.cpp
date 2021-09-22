#include "vec2.h"

Vector2::Vector2(){
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

Vector2& Vector2::add(const Vector2& vec){
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}
Vector2& Vector2::sub(const Vector2& vec){
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}
Vector2& Vector2::mul(const Vector2& vec){
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}
Vector2& Vector2::div(const Vector2& vec){
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

Vector2& operator+(Vector2& v1, const Vector2& v2){
    return v1.add(v2);
}
Vector2& operator-(Vector2& v1, const Vector2& v2){
    return v1.sub(v2);
}
Vector2& operator*(Vector2& v1, const Vector2& v2){
    return v1.mul(v2);
}
Vector2& operator/(Vector2& v1, const Vector2& v2){
    return v1.div(v2);
}

Vector2& Vector2::operator+=(const Vector2& vec){
    return this->add(vec);
}
Vector2& Vector2::operator-=(const Vector2& vec){
    return this->sub(vec);
}
Vector2& Vector2::operator*=(const Vector2& vec){
    return this->mul(vec);
}
Vector2& Vector2::operator/=(const Vector2& vec){
    return this->div(vec);
}