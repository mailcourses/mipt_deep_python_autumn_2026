import time

from fib_native import fib_rec_py, fib_iter_py
from fib_utils_new import fib_iter_c_api


def run_fib_native(n_rec, n_iter):
    t1 = time.time()
    res_rec = fib_rec_py(n_rec)
    t2 = time.time()
    t_rec = t2 - t1

    t1 = time.time()
    res_iter = fib_iter_py(n_iter)
    t2 = time.time()

    print(f"[python] t_rec={t_rec}, t_iter={t2 - t1}, {res_rec=}")


def run_fib_c_api(n_rec, n_iter):
    t1 = time.time()
    res_rec = None
    t2 = time.time()
    t_rec = t2 - t1

    t1 = time.time()
    res_iter = fib_iter_c_api(n_iter - 1)
    t2 = time.time()

    print(f"[c-api] t_rec={t_rec}, t_iter={t2 - t1}, {res_rec=}")


def run():
    n_rec, n_iter = 20, 1000000

    run_fib_native(n_rec, n_iter)
    print("-------\n")

    run_fib_c_api(n_rec, n_iter)
    print("-------\n")


if __name__ == "__main__":
   run()
