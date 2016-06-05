#include "Target.h"

Target::Target() {
    setType(OT_TARGET);
    checked = false;
}

Target::~Target() {
}

void Target::check() {
    checked = true;
}

void Target::uncheck() {
    checked = false;
}

bool Target::isChecked() const {
    return checked;
}
