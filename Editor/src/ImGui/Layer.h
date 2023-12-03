
#ifndef IMGUILAYER_H
#define IMGUILAYER_H



class Layer {
public:
    virtual ~Layer() = default;
    virtual void OnUpdate() = 0;
    virtual void OnImGuiUpdate() = 0;
};



#endif //IMGUILAYER_H
