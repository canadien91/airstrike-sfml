
#ifndef __COMMAND_QUEUE_H__
#define __COMMAND_QUEUE_H__

#include <queue>

#include <Command/Command.h>

class ACommandQueue {
public:
    void        Push( const ACommand& command );
    ACommand    Pop();
    bool        IsEmpty() const;

private:
    std::queue<ACommand> queue;
};

#endif
