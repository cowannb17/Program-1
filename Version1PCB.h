#include <array>
#include <iostream>

class PCBv1 {
    public:
        int init(int PID, int parent, int link) {
            this->PID = PID;
            this->parent = parent;
            this->link = link;
        }
        int PID;
        int parent;
        int link;
        PCBv1 create();
    private:
        int arr[16] {PID, parent, link};
};

PCBv1 PCBv1::create() {
    PCBv1 newPCB();
    return newPCB();
}