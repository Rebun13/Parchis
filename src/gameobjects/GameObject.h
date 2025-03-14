
using namespace std;

class GameObject {
    public:
        GameObject();
    private:
        vector <shared_ptr<Component>> m_Components;
    public:
        void addComponent(shared_ptr<Component> newComponent);
        void update(float elapsedTime);
        void draw(VertexArray& canvas);
};
