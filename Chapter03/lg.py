def _lg(N):
    if N < 1:
        raise ValueError
    i = 0
    while (N > 1):
        N = int(N/2)
        i += 1
    return i


def test():
    assert _lg(1) == 0
    assert _lg(2) == 1
    assert _lg(8) == 3
    assert _lg(10) == 3
    assert _lg(16) == 4
    assert _lg(31) == 4
    assert _lg(32) == 5

def main():
    i = 1
    N = 10
    while (i <= 6):
        print(int(N), int(_lg(N)), int(N*_lg(N)))
        N = int(N*10)
        i += 1


if __name__ == "__main__":
    main()