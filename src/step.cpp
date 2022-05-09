#include "../headers/step.h"

std::string Step::stepToString() {
    std::string tmp = "";
    tmp += this->now_.getLoc() + "->" + this->next_.getLoc() + ":\nguards: ";
    for (size_t i = 0; i < this->guards_.size() - 1; ++i)
        tmp += this->guards_[i].ccToString() + " && ";
    tmp += this->guards_[this->guards_.size()-1].ccToString() + ";\nresets:";
    for (size_t i = 0; i < this->reset_.size(); ++i) {
        tmp += "\n" + this->reset_[i].clockToString() + ":=0;";
    }
    tmp += "\naction: " + this->action_;
    return tmp;
}