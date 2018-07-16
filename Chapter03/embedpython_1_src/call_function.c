// call_function.c - A sample of calling python functions from C code
// 
#include <stdio.h>
#include <errno.h>

#include <Python.h>

int main(int argc, char *argv[])
{
	int i;
	PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pValue;

	if (argc < 3) 
	{
		printf("Usage: exe_name python_source function_name\n");
		return 1;
	}

	// Initialize the Python Interpreter
	Py_Initialize();
	PySys_SetArgv(argc, argv);

	// Build the name object
	printf("pName = PyString_FromString(argv[1]);\n");
	pName = PyString_FromString(argv[1]);
	printf("pName: %s\n", argv[1]);

	// Load the module object
	printf("pModule = PyImport_Import(pName);\n");
	pModule = PyImport_Import(pName);
	if (pModule==NULL){
		PyErr_Print();
		return -1;
	}

	// pDict is a borrowed reference 
	printf("pDict = PyModule_GetDict(pModule);\n");
	pDict = PyModule_GetDict(pModule);

	// pFunc is also a borrowed reference
	printf("pFunc = PyDict_GetItemString(pDict, argv[2]);\n");
	pFunc = PyDict_GetItemString(pDict, argv[2]);

	if (PyCallable_Check(pFunc)) 
	{
		// Prepare the argument list for the call
		if( argc > 3 )
		{
    			pArgs = PyTuple_New(argc - 3);
    			for (i = 0; i < argc - 3; i++)
    			{
					pValue = PyInt_FromLong(atoi(argv[i + 3]));
        			if (!pValue)
        			{
						PyErr_Print();
             			return 1;
        			}
        			PyTuple_SetItem(pArgs, i, pValue);	
    			}
			
				pValue = PyObject_CallObject(pFunc, pArgs);

				if (pArgs != NULL)
				{
					Py_DECREF(pArgs);
				}
		} else
		{
				pValue = PyObject_CallObject(pFunc, NULL);
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
	} else 
	{
		PyErr_Print();
	}

	// Clean up
	printf("Py_DECREF(pModule);\n");
	Py_DECREF(pModule);
	printf("Py_DECREF(pName);\n");
	Py_DECREF(pName);

	// Finish the Python Interpreter
	printf("Py_Finalize();\n");
	Py_Finalize();

	return 0;
}