#pragma once
enum TurnDirection {
	TurnDirection_None = -2,
	Right = -1,
	Left = +1,
	Straight = +2,
	Back = 0
};
//この数値はBranch内の処理で使うため変更しないこと