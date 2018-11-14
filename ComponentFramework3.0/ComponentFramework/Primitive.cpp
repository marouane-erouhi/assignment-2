#include "Primitive.h"
#include <iostream>

using namespace GAME;

Primitive::Primitive(GLenum drawMode_, std::vector<Vec3> &vertices_, std::vector<Vec3> &normals_, std::vector<Vec2> &uvs_)
{
	meshes.push_back(new Mesh(drawMode_, vertices_, normals_, uvs_));
	OnCreate();
}

Primitive::Primitive(std::string filePath_) {
	ObjLoader obj(filePath_.c_str());
	
	//Need?
	std::vector<MATH::Vec3> tempVertices; 
	for (int i = 0; i < obj.vertices.size(); i++) {
		tempVertices.push_back(MATH::Vec3(obj.vertices.at(i).x, obj.vertices.at(i).y, obj.vertices.at(i).z) * 1.14f);
	}

	//Find the size of the vertex array within the std::vector
	vertexSize = obj.vertices.size();

	meshes.push_back(new Mesh(GL_LINE_LOOP, tempVertices, obj.normals, obj.uvCoords));
	OnCreate();


}

bool Primitive::OnCreate() {
	shader = new Shader("baseVert.glsl", "baseFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");
	projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
	modelViewMatrixID = glGetUniformLocation(shader->getProgram(), "modelViewMatrix");
	normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
	return true;
}

void Primitive::OnDestroy() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	if (shader) {
		delete shader;
	}
	shader = nullptr;
	for (Mesh* m : meshes) {
		if (m) {
			delete m;
		}
		m = nullptr;
	}

}
//Change this to manipulate the motion of the object
void Primitive::Update(const float deltaTime) {
	//float tempX = 0.0f;
	//tempX += 1.0f;

	modelMatrix = MMath::translate(-0.02f, -0.02f, 0.0f) * MMath::rotate(rotateAngle, 0.0f, 0.0f, 1.0f);
	//modelMatrix = MMath::rotate(rotateAngle, 0.0f, 0.0f, 1.0f);//Keep z = 1.0f

}

void Primitive::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const {

	glUseProgram(shader->getProgram());
	glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(modelViewMatrixID, 1, GL_FALSE, viewMatrix *  modelMatrix);
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	for (Mesh* mesh : meshes) {
		mesh->Render();
	}
	glEnableVertexAttribArray(0); // Disable the VAO
}

//Add rotation directly into the Update()
void Primitive::addRotation(const float &angle_) {
	rotateAngle = angle_;
}

Primitive::~Primitive()
{
	OnDestroy();
}
