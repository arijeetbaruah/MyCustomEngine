#pragma once
#include <vector>

#include "MeshGeometry.h"
#include "ShaderBase.h"
#include "Texture.h"
#include "Transform.h"

class RenderObject
{
public:
	RenderObject(Transform* parentTransform, MeshGeometry* mesh, Texture* tex, ShaderBase* shader);
	RenderObject(RenderObject* copyRender);
	RenderObject(MeshGeometry* mesh, Texture* tex, ShaderBase* shader);

};

