#include "lvl_editor/entityList.h"
#include <string>

namespace Ragnarok {

EntityList::EntityList() {
    this->levelTag_ = "firstLevel";
    this->backgroundTexture_ = "blueSky";
    this->floorTexture_ = "brownDirt";
    this->npcSpriteDirectory_ = "none";
    this->obstacleDirectory_ = "none";
}
EntityList::~EntityList() {}

EntityList::WriteEntityFile(FILE** entityListFile) {} 


} //namespace Ragnarok