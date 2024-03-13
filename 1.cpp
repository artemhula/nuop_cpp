#include <iosteam>

class Cabinet {
public:
    int number;
    int workstations;
    int students;
    bool usable;
    bool electricity;
    bool heating;

    Cabinet(int number1, int workstations1, int students1, bool usable1, bool electricity1, bool heating1) {
        number = number1;
        workstations = workstations1;
        students = students1;
        usable = usable1;
        electricity = electricity1;
        heating = heating1;
    }
};