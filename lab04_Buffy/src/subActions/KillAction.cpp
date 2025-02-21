#include "KillAction.h"

KillAction::KillAction(const std::weak_ptr<Humanoid>& target) : Action(target) {

}

void KillAction::execute(Field &f){
    std::shared_ptr<Humanoid> t = _target.lock();
    if(t){
        t->dies();
    }
}
