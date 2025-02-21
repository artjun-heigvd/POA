#include "Action.h"


Action::Action(const std::weak_ptr<Humanoid>& target) : _target(target) {}