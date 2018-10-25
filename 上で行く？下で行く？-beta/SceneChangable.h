#pragma once

enum FrameScene {
	None,
	Intro,
	Driving,
	Clear,
	Over,
};
class SceneChangable {
public:
	virtual void changeScene(FrameScene) = 0;
};