#ifndef AGL_MAINSCENE_H
#define AGL_MAINSCENE_H

#include <vector>
#include "../Interface/IObject.h"
#include "../Interface/IScene.h"


class MainScene : public IScene{
public:
    void Add(IObject* object) override;
    void Remove(IObject* object) override;
    void Render() override;

    std::vector<IObject*> objects;

    glm::mat4 camPers = glm::mat4(1.0f);
    glm::mat4 camUpd = glm::mat4(1.0f);
};


#endif
