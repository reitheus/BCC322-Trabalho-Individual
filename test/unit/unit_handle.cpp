#include "unit_handle.h"

#include <assert.h>
#include "../../include/system_impl.h"

class TestBody : public Body {
public:
    int value;

    TestBody(int v = 0) : value(v) {}
};

class TestHandle : public Handle<TestBody> {
public:
    TestHandle() : Handle<TestBody>() {}

    int getValue() const {
        return pImpl_->value;
    }

    void setValue(int v) {
        pImpl_->value = v;
    }
};

void unit_Handle_constructor() {
    System_Handle s("S1", 100);

    assert(s.getName() == "S1");
    assert(s.getValue() == 100);
}

void unit_Handle_copy_constructor() {
    System_Handle s1("S1", 100);

    System_Handle s2(s1);

    assert(s2.getName() == "S1");
    assert(s2.getValue() == 100);

    s2.setValue(200);

    // ambos apontam para o mesmo Body
    assert(s1.getValue() == 200);
    assert(s2.getValue() == 200);
}

void unit_Handle_assignment() {
    System_Handle s1("A", 10);
    System_Handle s2("B", 20);

    s2 = s1;

    assert(s2.getValue() == 10);

    s1.setValue(50);

    assert(s2.getValue() == 50);
}

void run_unit_tests_HandleBody() {
    unit_Handle_constructor();
    unit_Handle_copy_constructor();
    unit_Handle_assignment();

    printf("HandleBody: All tests passed!\n");
}