//
// Created by Workstation on 15.07.2018.
//

#include <Python.h>

int main(int argc, char *argv[])
{
    Py_SetProgramName(argv[0]);
    Py_Initialize();
    PyRun_SimpleString("from time import time, ctime\n"
                       "print 'Today is', ctime(time())\n");

    Py_Finalize();
    return 0;
}