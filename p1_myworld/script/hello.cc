#include <gazebo/gazebo.hh>
#include <iostream>
#include <sdf/Element.hh>

namespace gazebo {

class WorldPluginTutorial : public WorldPlugin {
public:
  WorldPluginTutorial() : WorldPlugin() {
    std::cout << "Welcome to Samuel's World!"
              << "\n";
  }

public:
  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf) {}
};

GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
} // namespace gazebo
