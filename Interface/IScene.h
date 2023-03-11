#ifndef AGL_ISCENE_H
#define AGL_ISCENE_H
#include <vector>
#include "IObject.h"

class IScene{
public:
    virtual void Add(IObject* object) = 0;
    virtual void Remove(IObject* object) = 0;
    virtual void Render() = 0;
};

#endif
