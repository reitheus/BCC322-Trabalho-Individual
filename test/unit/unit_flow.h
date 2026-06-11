#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

void unit_Flow_constructor(void);
void unit_Flow_destructor(void);

void unit_Flow_getName(void);
void unit_Flow_setName(void);

void unit_Flow_getSource(void);
void unit_Flow_setSource(void);

void unit_Flow_getTarget(void);
void unit_Flow_setTarget(void);

void unit_Flow_execute(void);

void run_unit_tests_Flow(void);

#endif