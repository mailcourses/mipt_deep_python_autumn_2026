from setuptools import Extension, setup


setup(
    name="fib_utils_new",
    version="3.1.4",
    ext_modules=[Extension("fib_utils_new", ["fibutils.c"])],
)
