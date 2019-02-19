// call_class.c – пример встраивания python
// (вызов классов python из кода C)
//
#include <Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict,
            *pClass, *pInstance, *pValue;
    int i, arg[2];

    if (argc < 4)
    {
        printf(
                "Usage: exe_name python_fileclass_name function_name\n");
        return 1;
    }

    // некоторый код пропущен...

    // построить имя вызываемого класса
    pClass = PyDict_GetItemString(pDict, argv[2]);

    // создать экземпляр класса
    if (PyCallable_Check(pClass))
    {
        pInstance = PyObject_CallObject(pClass, NULL);
    }

    // построить список параметров
    if( argc > 4 )
    {
        for (i = 0; i < argc - 4; i++)
        {
            arg[i] = atoi(argv[i + 4]);
        }
        // вызвать метод класса с двумя параметрами
        pValue = PyObject_CallMethod(pInstance,
                                     argv[3], "(ii)", arg[0], arg[1]);
    } else
    {
        // вызвать метод класса без параметров
        pValue = PyObject_CallMethod(pInstance, argv[3], NULL);
    }
    if (pValue != NULL)
    {
        printf("Return of call : %d\n", PyInt_AsLong(pValue));
        Py_DECREF(pValue);
    }
    else
    {
        PyErr_Print();
    }

    // некоторый код пропущен...
}