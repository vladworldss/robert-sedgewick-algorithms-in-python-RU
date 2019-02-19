// call_function.c – пример вызова
// функций python из кода C
//
#include <Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3)
    {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    // Инициализировать интерпретатор Python
    Py_Initialize();

    // Построить объект имени
    pName = PyString_FromString(argv[1]);

    // Загрузить объект модуля
    pModule = PyImport_Import(pName);

    // pDict – заимствованная ссылка
    pDict = PyModule_GetDict(pModule);

    // pFunc – тоже заимствованная ссылка
    pFunc = PyDict_GetItemString(pDict, argv[2]);

    if (PyCallable_Check(pFunc))
    {
        PyObject_CallObject(pFunc, NULL);
    } else
    {
        PyErr_Print();
    }

    // Вернуть ресурсы системе
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Завершить интерпретатор Python
    Py_Finalize();

    return 0;
}