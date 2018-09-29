#pragma once

enum FrameScene {
	Intro,
	Driving,
	Clear,
};
class SceneChangable {
public:
	virtual void changeScene(FrameScene) = 0;
};