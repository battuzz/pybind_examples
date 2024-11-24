import test_package


def test_add():
    test_package.add(1, 2)


def test_add2():
    result = test_package.add2()
    assert result == 10

    result2 = test_package.add2(j=1)
    assert result2 == 8
