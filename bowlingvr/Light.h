#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Shader.h"

class Light
{
public:
	Light(Shader *shader,
		unsigned int lightIndex,
		glm::vec4 position = { 0, 2.0f, 0, 1.0f },
		bool isSpot = false,
		glm::vec4 ambient = { 0.05f, 0.05f, 0.05f, 0.0f },
		glm::vec4 diffuse = { 0.5f, 0.5f, 0.5f, 0.5f },
		glm::vec4 specular = { 1.0f, 1.0f, 1.0f, 1.0f },
		glm::vec4 cone_direction = {0.0, -1.0, 0.0, 1.0},
		float spot_cos_cutoff = 0.1,
		float spot_exponent = 10
	);

	void Render(Shader *shader);

	glm::vec4 position;

private:
	Shader * shader;
	unsigned int lightIndex;
	bool isSpot;
	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;

	float shininess;
	float strength;
	//
	glm::vec4 eye_direction; //view * pos
	float constant_attenuation;
	//
	glm::vec4 cone_direction;
	float spot_cos_cutoff; //how wide the spot is as a cosine
	float spot_exponent; //light falloff in the spot

	glm::mat4 translation;

};