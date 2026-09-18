#pragma once

#include "Entities/Ship.h"
#include "Game.h"

class Player : public Ship {
    virtual void Tick(float delta_time) override {
        Game::GetInstance()
    }
};