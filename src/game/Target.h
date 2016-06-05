#ifndef TARGET_H
#define TARGET_H
#include "GameObject.h"
class Target : public GameObject {
public:
    Target();
    virtual ~Target();
    void check();
    void uncheck();
    bool isChecked() const;
private:
    bool checked;
};
#endif // TARGET_H
