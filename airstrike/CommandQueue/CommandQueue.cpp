
#include "CommandQueue.h"

void
ACommandQueue::Push( const ACommand& command ) {
    this->queue.push( command );
}

ACommand
ACommandQueue::Pop() {
    ACommand command = this->queue.front();
    this->queue.pop();
    return command;
}

bool
ACommandQueue::IsEmpty() const {
    return this->queue.empty();
}
