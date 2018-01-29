#include <string>

namespace Ragnarok {

    class EntityList {
        private:
        //TODO: determine what parameters to encapsulate and define entity presence and behavior
            std::string levelTag_;
            std::string backgroundTexture_;
            std::string floorTexture_;
            std::string npcSpriteDirectory_;
            std::string obstacleDirectory_;
        public:
        //constructor and deconstructor
        //TODO: determine parameters to be passed into constructor
            EntityList();
            ~EntityList();
            void WriteEntityFile(FILE** entityListFile);
    }
} //namespace Ragnarok