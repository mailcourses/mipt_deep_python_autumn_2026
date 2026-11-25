#define PY_SSIZE_T_CLEAN
#include <Python.h>


static PyObject* fib_iter_c_api(PyObject *self, PyObject *args)
{
    long n;

    if (!PyArg_ParseTuple(args, "l", &n))
    {
        return NULL;
    }

    if (n < 0)
    {
        PyErr_SetString(PyExc_ValueError, "b must be non-negative");
        return NULL;
    }

    if (n < 2)
    {
        return PyLong_FromLong(1);
    }

    PyObject *a = PyLong_FromLong(0);
    if (!a)
    {
        return NULL;
    }

    PyObject *b = PyLong_FromLong(1);
    if (!b)
    {
        Py_DECREF(a);
        return NULL;
    }

    for (long i = 0; i <= n; ++i)
    {
        PyObject *a_b = PyNumber_Add(a, b);
        if (!a_b)
        {
            Py_DECREF(a);
            Py_DECREF(b);
            return NULL;
        }

        Py_DECREF(a);
        a = b;
        b = a_b;
    }

    Py_DECREF(b);
    return a;
}


static PyMethodDef fib_c_api_methods[] = {
    {"fib_iter_c_api", fib_iter_c_api, METH_VARARGS, "n-th fib number iter"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef fib_c_api_module = {
    PyModuleDef_HEAD_INIT,
    "fib_utils_c_api",
    "c-api fibs functions",
    -1,
    fib_c_api_methods,
};

PyMODINIT_FUNC PyInit_fib_utils_new(void)
{
    return PyModule_Create( &fib_c_api_module );
}
