/*
	Console 3D Maze Game
		© Amyr Ahmady (iAmir) - 2019
	File: game.hpp

	Repository: https://github.com/AmyrAhmady/Console-3D-Maze-Game
*/

#pragma once
#include <iostream>
#include <memory>

class Console;
class Player;

class Game
{
public:
	Game();
	Game(const std::wstring &map, const Size2D &screenSize, const Size2D &radarSize);
	~Game();

	void Play();
	wchar_t GetMapChar(int index);
	Size2D GetScreenSize() { return screenSize; }
	Size2D GetMapSize() { return mapSize; }

private:
	std::wstring mapPainting;
	Size2D mapSize;
	Size2D screenSize;
	std::unique_ptr<Console> output;
	std::unique_ptr<Player> player;

	float GetRayDirection(float xCoord);
	std::pair<int, int> SendRayCast(const Vector2 &direction);
	std::pair<float, bool> GetCollideStatus(int x);
	short GetWallShade(float distance);
	short GetFloorShade(int y);
	void DrawRadar(const Vector2 &playerPos);
};