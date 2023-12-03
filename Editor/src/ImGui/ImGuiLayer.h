
#ifndef IMGUILAYER_H
#define IMGUILAYER_H



class ImGuiLayer {
public:
    virtual ~ImGuiLayer() = default;
    virtual void OnUpdate() = 0;
};



#endif //IMGUILAYER_H
