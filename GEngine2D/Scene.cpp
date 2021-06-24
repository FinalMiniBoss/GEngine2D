#include "Scene.h"
#include "GEngine2D.h"

Scene* Scene::_CurrentScene = nullptr;

Scene* Scene::CurrentScene() { return _CurrentScene; }

Scene::Scene() :Drawable(GEngine2D::Renderer()) {}
Scene::~Scene() {

}

void Scene::present() {
	_CurrentScene = (this);
}


void Scene::onDraw() {
    
}

void Scene::onUpdate(float _deltaTime){}
