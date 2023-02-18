#include <array>
#include <iostream>

struct data {
    int num;
    PCBv1* pcb;
};

class PCBv1 {
    public:
        PCBv1() {
            PCBdata[0].num = -1; //PID
            PCBdata[1].pcb = NULL; //parent
            PCBdata[2].pcb = NULL; //next
        }
    private:
        data PCBdata[16];
};