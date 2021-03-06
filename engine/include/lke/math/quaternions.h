#pragma once 

#include <lke/lke.h>
#include <lke/math/math.h>
#include <lke/math/vectors.h>

namespace lke
{
    class Quaternion;

    struct AngleAxis
    {
        Radians m_Angle;
        Vector3f m_Axis;
    };

    struct EulerAngles
    {
        Radians m_Pitch;
        Radians m_Roll;
        Radians m_Yaw;
    };

    lkedll bool IsNormalized(const Quaternion& quaternion);
    lkedll bool EpsilonEqual(const Quaternion& q1, const Quaternion& q2);

    class lkedll Quaternion
    {
    public:
        friend lkedll bool IsNormalized(const Quaternion& quaternion);
        friend lkedll bool EpsilonEqual(const Quaternion& q1, const Quaternion& q2);

        Quaternion()
            : m_Vector(0, 0, 0), m_Scalar(0)
        { }

        Quaternion(float x, float y, float z, float w)
            : m_Vector(x, y, z), m_Scalar(w)
        { }

        explicit Quaternion(Vector3f vector, float scalar)
            : m_Vector(vector), m_Scalar(scalar)
        { }

        static Quaternion FromLookAt(const Vector3f& lookAt);
        static Quaternion GetIdentity() { return Quaternion(0, 0, 0, 1.f); }
        static Quaternion FromAngleAxis(const AngleAxis& angleAxis);
        
        /**
         *  @brief Grassman product multiplication. 
         *  See Game Engine Architecture, 3rd Edition, page 396
         */
        Quaternion operator*(const Quaternion& other) const;

        /**
         *  @brief Rotates the input 3D Vector by this Quaternion
         */
        Vector3f operator*(const Vector3f& vector) const;

        /**
         *  @brief Returns the Quaternion representing the inverse rotation
         *  of this Quaternion, i.e. its conjugate. The Quaternion __must__
         *  be unitary.
         */
        Quaternion GetInverse() const;

        /**
         *  @brief Decomposes this Quaternion in its Euler Angles representation
         */
        EulerAngles ToEulerAngles() const;

        inline float X() const { return m_Vector[0]; }
        inline float Y() const { return m_Vector[1]; }
        inline float Z() const { return m_Vector[2]; }
        inline float W() const { return m_Scalar; }

    private:
        Vector3f m_Vector;
        float m_Scalar;
    };
}