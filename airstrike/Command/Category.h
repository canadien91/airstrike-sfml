
#ifndef __CATEGORY_H__
#define __CATEGORY_H__

namespace Category_ns {
    enum Type_t {
        None            = 0,
        Scene           = 1 << 0,
        PlayerAircraft  = 1 << 1,
        AlliedAircraft  = 1 << 2,
        EnemyAircraft   = 1 << 3,
    };
}

#endif
