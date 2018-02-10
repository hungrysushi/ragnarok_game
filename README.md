# Game Project

This is a project to write a game from scratch.

The readme will be updated with miscellaenous details as the project progresses.

High level design decisions can also be documented here.

## First time instructions
After cloning the project:

* Run `git submodule update --init`

* Go to third_party/glad and run `python -m glad --generator c --no-loader --out-path ../glad_generated`

* Check OpenGL version `glxinfo | grep "OpenGL version"` (Linux)
    * Edit ` GLFW_CONTEXT_VERSION_MAJOR` and `GLFW_CONTEXT_VERSION_MINOR` in `engine/src/engine.cpp` to represent version on your computer.
    * For example, if OpenGL version = 4.2, `GLFW_CONTEXT_VERSION_MAJOR = 4` and `GLFW_CONTEXT_VERSION_MINOR = 2`

* Go to third_party/openal-soft/build and run `cmake ..`
    * Make sure appropriate backends are detected (DirectSound for Windows, PulseAudio, ALSA, OSS for Linux).
    * Run `make`
    * Run `./openal-info` to check if OpenAL information is correct.

## Building and running
From the root of the project,
~~~~
mkdir build && cd build
cmake ../
make
./game_project
~~~~

## High-level
Obviously, for "video game" part, there needs to be some video output, some audio playback, and some input handling.

Renderer
Audio Manager
Input Handler
Event System
World/Level Representation
Interface
    Menu system

To build a lot of the game logic and mechanics, tools are needed. Defining behavior in the level editor is a problem that needs to be tackled.
Sprite Editor
Level Editor

Each of these components will consist of a high-level logic module combined with a low level interface. Implementation architecture TBD

## Discussion

- Libraries to use
- Structure, Modularity
- Feature list

Let's hash out the design to some degree before starting the redesign. The feature list should help us keep from overengineering, to a degree.

### Libraries

GLFW - windowing and input
GLAD - hardware-specific libraries
OpenAL - audio
GLM - matrix math library. Could write our own, but this provides decent performance.
stbimage - image loader for a variety of images. Should replace with libpng eventually

### Structure

Main -> Logic Event Loop -> World Update -> Engine Update -> Process Output -> Process Input -> Logic Event Loop -> ...

The alternative to this structure is to separate the engine and logic in separate threads. That may help performance, but there will still need to be some point of sync in order to ensure consistent timing of events. For (technically) simple game we're thinking of, I don't see a lot of benefit offered by threads, while our lives are made a whole lot simpler by having logic and engine events in the same loop. Thoughts?

Inputs will be handled through static callback functions.

### Feature List

- Reusable engine
- Level parser
- Level editor
- 3D?
- Camera effects (ex. shake) capability
- Teleportation, gravity, speed, strength etc.
- Physics support to change in game mechanincs on the fly
- Level can change orientation (x to y axis)
- Input to include keyboard initially, controller functionality later

### Storyline Discussion
- Depicting and detailing the Norse apocalypse, Ragnarok
- An elderly nomadic scribe known by the name of Ragnarok whose purpose is to detail the events of Ragnarok by extracting experiences from Norse gods such as Odin, Thor, Baldr, etc.
- The scribe meets each god, and forcefully (sometimes not) extracts their experiences and replays their story while gaining their abilities to be used throughout gameplay, adding on to his story which will eventually be compiled into the Poetic Edda, the main source of Norse mythological studies in modern day
- List of gods to be in-game TBD, the main roster includes Odin, Thor, Loki, Baldr, Tyr, Frej/Freja
- List of enemies includes Surtur, Jormungundr, Fenris, Hel, the frost giants
- Worlds to be considered are the nine realms, including Asgard, Midgard (humans), Jotunheim (frost giants), Muspelheim (Surtur), amongst others
- Ragnarok (as each god) would fight each enemy, then meet their doom. After each fight, Ragnarok would extract the remaining details from that god, and close that "chapter" of his book. Tying into the Poetic Edda, like a fitting closing line, might be a nice ode to the tale. Thinking of an Assassin's Creed-esque end to each main enemies portion of the story, just an idea.
- Possible starting point: Ragnarok is this eternal being, and so is able to detail the events of the beginning of the world, as well as the end. Starting in Ginnungagap, the void that existed before the world's creation, the beginning of the story unfolds, and Ragnarok could meet Odin at first to get more information about how everything unfolded. This won't be Odin's end, he could return later in the story to fill in the last cracks of Ragnarok's tale. This will allow for ambiguity and story progression.
- Different "mythical" items can be scattered around the world, which would give the player some sort of lasting perk (Only example i can think of: Darksiders weapons, game can progress without Death's scythe but it gives the player a new weapon and new abilities that are add-ons)

### Gameplay Discussion
- The main feature of the game is the storyline, trying to entice the player to move forward to unveil more parts of the story. There is a lot of material that can be added on to the main story line, in order to not make the game extremely linear, but still driven towards an end-goal.
- Instead of forcing the player to follow a certain order of gods, they can choose to start with a certain list of gods, like a tiered style, while still interweaving stories (i.e: jump out of Thor's story, then run into Loki), possibly a way to weave in Ragnarok's thoughts into the gameplay while allowing the player to piece together the story on their own. Would have to set "waypoints" in the levels that would allow for a safe transition back to the central level (storyline example: speaking to different NPCs, would have to speak to an NPC that is a sorcerer to teleport them back to another realm)
- The gameplay was initially set to be a 2D side-scoller, with 16-bit pixel artwork and audio, aimed at being a retro style game
- Physics would play a part in the overall gameplay, i.e: icy ground would cause a character to slip around instead of standing still, sand would cause slower movement
- Up for discussion: basic AI component for boss battles, bosses learn patterns of movement and acts accordingly

### Player Attributes
- Add in dialog for various NPCs, dialogue would be relevant to race, gender, age, i.e: speaking to a female human child would result in different dialogue than a male elven elder.
- Interaction with surroundings such as breaking pots/crates to find in-game gold or items (possibly?)
- Different items can weild different attributes, such as armor, health, damage, new spells
- Player abilities: Hero attributes can include a list of spells that can be used from hotkeys, a backpack of items that can be used on the character, stash for items available in multiple places around the world
- Basic level-up scheme would be available, up to a certain maximum. Total health, base armor, base damage, total manapool, new abilities (double jump, etc) might be available, TBD
- Base attributes change between characters? Loki would have a larger manapool than Thor, but less base damage and HP
- Should a characters spells be locked to an individual character, and Ragnarok gain all the spells for himself to be used for when he is in his form? Avoids mixing and matching abilities which don't work on everyone

