#include "camera.h"

Camera::Camera(sf::RenderWindow* wdw) : window{wdw} {
	initCamera();
}

void Camera::UpdateCam(const sf::Vector2f& player_pos) {
	camera.setCenter(player_pos);
}

void Camera::initCamera() {
	camera.setSize(window->getSize().x, window->getSize().y);
	camera.setCenter(window->getSize().x/2.f, window->getSize().y/2.f);
}
