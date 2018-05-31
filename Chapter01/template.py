# coding: utf-8
"""
Модуль базового класса для решения задач связности.
"""
import sys
import pytest


class BaseConnectivity(object):
    """
    Базовый класс для создания исходной таблицы связности
    и поиска - объединения связанных компонентов.
    Реализует безопасное перемещение по таблице,
    обрабатывая исключительные ситуации (выход за пределы массива,
                                        некорректные входные данные и т.д.)
    """

    def __init__(self, size=10):
        """
        Конструктор класса.

        :param size: размер таблицы связности
        """
        self.__size = size
        self.__arr = list(range(size))

    @property
    def size(self):
        return self.__size

    @property
    def arr(self):
        return self.__arr

    def find(self, i):
        """
        Абстрактный метод поиска.
        Должен быть определен в дочерней реализации.

        :param i:
        :return:
        """
        raise NotImplementedError

    def union(self, p, q):
        """
        Абстрактный метод объединения элементов.
        Интерпретирует пару p и q как "связать объект p c объектом q"

        :param int p:
        :param int q:
        :return:
        """
        raise NotImplementedError

    def get_input_values(self):
        """
        Получение пары значений p-q из STDIN.
        Если вводимых значений больше 2 или они не могут быть преобразованы к типу int,
        либо значения {p,q} < 0 OR {p,q} > N-1 - возбуждается исключение.

        :return: tuple of (int p, int q)
        """
        p, q = tuple(map(int, input('Get int pair (p, q): \n').split()))
        if not all(-1 < x < self.__size for x in (p, q)):
            raise ValueError
        return p, q

    def main(self):
        while True:
            try:
                p, q = self.get_input_values()
                print(self.union(p, q))
            except ValueError:
                continue
            except (KeyboardInterrupt, EOFError):
                print(self.__arr)
                sys.exit()


def make_connect_table(Cls, *args, **kw):
    """
    Метод создающий и модифицирующий таблицу связности.

    :param Cls: self.Connectivity
    :param args:
    :param kw:
    :return:
    """
    inst = Cls(*args, **kw)
    inst.main()
    return inst.arr


INPUT_PAIRS = (
            (3, 4),
            (4, 9),
            (8, 0),
            (2, 3),
            (5, 6),
            (2, 9),
            (5, 9),
            (7, 3),
            (4, 8),
            (5, 6),
            (0, 2),
            (6, 1)
        )
@pytest.mark.skip(reason="it's not a fixture")
def test_connectivity(Cls, ETALON_RES, input_pairs=INPUT_PAIRS):
    c = Cls()
    for pair in input_pairs:
        c.union(*pair)
    assert c.arr == ETALON_RES
    return c.arr
