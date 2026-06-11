#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

void unit_Model_constructor(void);
void unit_Model_destructor(void);

void unit_Model_addSystem(void);
void unit_Model_addFlow(void);

void unit_Model_run(void);
void unit_Model_showModel(void);

void run_unit_tests_Model(void);

#endif