#ifndef BUFFY_KILLERHUMANOID_H
#define BUFFY_KILLERHUMANOID_H

#include "../Humanoid.h"

/**
 * This class represents a humanoïd that can "kill" others (uses a KillAction).
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class KillerHumanoid : public Humanoid {

public:

    /**
     * Constructor for a new KillerHumanoid
     *
     * @param pos the pos of our new KillerHumanoid
     */
    explicit KillerHumanoid(const Point& pos);

    /**
     * Find a humanoid from a given type that is in range of our attack.
     *
     * @param f     the field of our simulation
     * @param type  the type of the humanoïd we want to kill
     * @return      the humanoïd of our given type that is the closest and returns true if the humanoid is in range, false otherwise.
     */
    std::pair<std::shared_ptr<Humanoid>, bool> findHumanoidToAffect(const Field& f, Humanoid::Type type) const;

    KillerHumanoid(size_t maxX, size_t maxY);

private:
    //The range of the KillerHumanoid
    size_t _range {1};
};

#endif  // BUFFY_KILLERHUMANOID_H
