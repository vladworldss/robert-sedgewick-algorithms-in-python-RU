# coding: utf-8
"""
Ex1.2: Решение задачи связности методом быстрого объединения.

Идея:
    Массив представляет собой отображение дерева.

    1) в ячейке содержится ссылка на родителя.
    ROOT-ячейка - та ячейка, которая содержит ссылку на саму себя.

    2) Если две связываемые ячейки приводят к одному ROOT -
    значит они связаны.

    3) Если они указывают на разные ROOT - значит в P_ROOT ячейку нужно записать
    адрес Q_ROOT
"""
import sys

from template import BaseConnectivity, make_connect_table, test_connectivity

__author__     = "Vladimir Gerasimenko"
__copyright__  = "Copyright (C) 2018, Vladimir Gerasimenko"
__version__    = "0.0.1"
__maintainer__ = "Vladimir Gerasimenko"
__email__      = "vladworldss@yandex.ru"


def pure_quick_union(N=10):
    """
    Исходный листинг программы 1.2 адаптированный под Python.

    :return:
    """
    _id = list(range(0, N))
    while True:
        try:
            p, q = tuple(map(int, input('Get int pair (p, q): \n').split()))

            i = p
            while (i < N) and (_id[i] != i):
                i = _id[i]

            j = q
            while (j < N) and (_id[j] != j):
                j = _id[j]

            if _id[p] == _id[q]:
                continue

            _id[i] = j
            print(p, q)
        except ValueError:
            continue
        except (KeyboardInterrupt, EOFError):
            print("Result: ", _id)
            return _id


class Connectivity(BaseConnectivity):
    """
    Класс быстрого объединения
    Сложность = (худший) O(M*N/2) -> O(M*N)
    """
    def union(self, p, q):
        """
        В случае, если p и q значения еще не связаны (имеют разные корни),
        то метод union устанавливает ссылку на Q_ROOT в ячейку, где
        хранится P_ROOT

        :param p:
        :param q:
        :return: если p и q не были связаны - кортеж (p, q). Иначе - None.
        """
        founded = self.find(p, q)
        if founded is None:
            return

        p_root, q_root = founded
        self.arr[p_root] = q_root
        return p, q

    def find(self, p, q):
        """
        Метод поиска ROOT-значений для переданной пары объектов.

        :param p:
        :param q:
        :return: если p и q имеют разные корни - возвращается
        кортеж индексов этих корней. Иначе - None
        """
        p_root, q_root = self._get_root(self.arr[p]), self._get_root(self.arr[q])
        if p_root != q_root:
            return p_root, q_root

    def _get_root(self, i):
        """
        Метод возвращает корень дерева для переданного объекта.
        Выполняется рекурсивно.

        :param i: объект дерева.
        :return: индекс ROOT
        """
        parent = self.arr[i]
        if parent == i:
            return i
        else:
            return self._get_root(parent)

    def set_root(self, node_idx, root_idx):
        """
        Устанавливает узлу ссылку на корень

        :param int node_idx:
        :param int root_idx:
        :return:
        """
        if node_idx > self.size - 1:
            raise IndexError
        self.arr[node_idx] = root_idx


# --------------------------------
#           TESTS
# --------------------------------
def test():
    ETALON_RES = [1, 1, 9, 4, 9, 6, 9, 9, 0, 0]
    return test_connectivity(Connectivity, ETALON_RES)
# --------------------------------


if __name__ == '__main__':
    args = sys.argv
    if len(args) > 1:
        if "pure" in args[1]:
            print("PURE CONNECTIVITY")
            pure_quick_union()
        elif "test" in args[1]:
            pure_res = pure_quick_union()
            custom_res = test()
            assert pure_res == custom_res
    else:
        print("CUSTOM CONNECTIVITY")
        res = make_connect_table(Connectivity)
        print(res)
