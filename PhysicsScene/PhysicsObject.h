#pragma once
#include "glm\ext.hpp"

enum ShapeType
{
	JOINT = -1,
	PLANE = 0,
	SPHERE,
};

const int SHAPE_COUNT = 2;

///Summary
///  all Objects that will updated with physics calculation
class PhysicsObject
{
protected:
	PhysicsObject(ShapeType shapeID) : m_shapeID(shapeID) {}

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0; //!< a Update On a fixed TimeStep
	virtual void debug() = 0; //!<  Not Used
	virtual void makeGizmo() = 0; //!<  Draw this Object
	virtual void resetPosition() {}; //!<  Not Used

	ShapeType getShapeID() { return m_shapeID; }//!<  Used To get this object shape ID

protected:
	ShapeType m_shapeID;//!<  Used To determine what object this is
};

