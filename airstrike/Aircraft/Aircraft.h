
#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#include "Entity/Entity.h"

class AnAircraft : public AnEntity {
public:
    enum Type_t {
        Eagle,
        Raptor,
    };

    explicit AnAircraft( Type_t type );

private:
    Type_t type;

};

#endif
