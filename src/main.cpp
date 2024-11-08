#include "window/window.h"

int main() {

    std::shared_ptr<Taskly> task = std::make_shared<Taskly>();
    task->Start();

    return 0;
}