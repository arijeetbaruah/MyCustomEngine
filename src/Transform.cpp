#include "Transform.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace glm;
using namespace std;

Transform::Transform()
{
	parent = nullptr;
	localScale = vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(const vec3& position, Transform* p) {
	parent = p;
	SetWorldPosition(position);
}

Transform::~Transform()
{
}

void Transform::UpdateMatrices() {
	localMatrix =
		glm::translate(glm::mat4(), localPosition) *
		glm::mat4(localOrientation) *
		glm::scale(glm::mat4(), localScale);

	if (parent) {
		worldMatrix = parent->GetWorldMatrix() * localMatrix;
		worldOrientation = parent->GetWorldOrientation() * localOrientation;
	}
	else {
		worldMatrix = localMatrix;
		worldOrientation = localOrientation;
	}
}

void SetPositionVector(mat4& matrix, vec3 posDiff) {
	matrix[0][3] = posDiff.x;
	matrix[1][3] = posDiff.y;
	matrix[2][3] = posDiff.z;
}

void Transform::SetWorldPosition(const vec3& worldPos) {
	if (parent) {
		mat4 worldMat = parent->GetWorldMatrix();
		
//		vec3 parentPos = vec3(worldMat[0][3], worldMat[1][3], worldMat[2][3]);
		vec3 parentPos = vec3();
		vec3 posDiff = parentPos - worldPos;

		localPosition = posDiff;
		

		SetPositionVector(localMatrix, posDiff);
	}
	else {
		localPosition = worldPos;

		SetPositionVector(worldMatrix, worldPos);
	}
}

void Transform::SetLocalPosition(const vec3& localPos) {
	localPosition = localPos;
}

void Transform::SetWorldScale(const vec3& worldScale) {
	if (parent) {

	}
	else {
		localScale = worldScale;
	}
}

void Transform::SetLocalScale(const vec3& newScale) {
	localScale = newScale;
}
