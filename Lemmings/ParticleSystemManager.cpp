#include "ParticleSystemManager.h"
#include <ctime>
#include <random>

void ParticleSystemManager::createNewParticleSystem(glm::vec2 position)
{

	ParticleSystem *particleSystem = new ParticleSystem();
	particleSystem->setPosition(position);
	particleSystems.push_back(particleSystem);
}

void ParticleSystemManager::update(int deltaTime) 
{
	for (int i = 0; i < particleSystems.size(); ++i) {
		if (particleSystems[i]->notFinished()) {
			particleSystems[i]->update(deltaTime);
		}
	}
}

void ParticleSystemManager::render()
{
	for (int i = 0; i < particleSystems.size(); ++i) {
		if (particleSystems[i]->notFinished()) {
			particleSystems[i]->render();
		}
	}
}