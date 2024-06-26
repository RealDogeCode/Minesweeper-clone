#include "Cell.h"
#include "Minesweeper.h"

Cell::Cell(sf::Vector2i p, State initState, AssetManager* assetManager) : assetManager(assetManager), pos(p), currentState(initState), sprite(assetManager->getTexture(stateToString(initState))), flagged(false) {
    changeState(initState);
    sprite.setPosition(pos);
}

void Cell::changeState(Cell::State state) {
    currentState = state;
    if(isOpen){
        sprite.setTexture(assetManager->getTexture(stateToString(currentState)));
    }
}

void Cell::setFlag(bool value){
    if(isOpen) return;
    flagged = value;
    if(flagged){
        sprite.setTexture(assetManager->getTexture(stateToString(Cell::State::FLAG)));
    }
    else
    {
        sprite.setTexture(assetManager->getTexture(stateToString(Cell::State::CLOSED)));
    }
}

void Cell::FlagFail(){
    sprite.setTexture(assetManager->getTexture(stateToString(Cell::State::FLAG_FAIL)));
}

void Cell::FlagWin(){
    sprite.setTexture(assetManager->getTexture(stateToString(Cell::State::FLAG_WIN)));
}

std::string Cell::stateToString(Cell::State state) {
    switch (state) {
        case Cell::CLOSED:
            return "CLOSED";
        case Cell::BOMB_FAIL:
            return "BOMB_FAIL";
        case Cell::FLAG_FAIL:
            return "FLAG_FAIL";
        case Cell::FLAG_WIN:
            return "FLAG_WIN";
        case Cell::EMPTY:
            return "EMPTY";
        case Cell::BOMB:
            return "BOMB";
        case Cell::FLAG:
            return "FLAG";
        case Cell::ONE:
            return "ONE";
        case Cell::TWO:
            return "TWO";
        case Cell::THREE:
            return "THREE";
        case Cell::FOUR:
            return "FOUR";
        case Cell::FIVE:
            return "FIVE";
        case Cell::SIX:
            return "SIX";
        case Cell::SEVEN:
            return "SEVEN";
        case Cell::EIGHT:
            return "EIGHT";
    }
    return "";
}

void Cell::open() {
    flagged = false;
    isOpen = true;
    changeState(currentState);
}

void Cell::close() {
    flagged = false;
    isOpen = false;
    changeState(currentState);
}