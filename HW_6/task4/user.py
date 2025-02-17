"""
Реалізуйте каталог деякої бібліотеки.
Бібліотека може містити кілька книг одного автора.
"""

size: int = 991
bookCatalog: list[list[tuple[str, str]]] = []
bookCounter: int = 0


def init():
    global bookCatalog, bookCounter, size
    bookCatalog = [[] for _ in range(size)]
    bookCounter = 0


def addBook(author, title):
    global bookCatalog, bookCounter, size

    if bookCounter >= size * 0.7:
        rehash()

    hashNumber = _hash(author)
    bookCatalog[hashNumber].append((author, title))
    bookCounter += 1


def find(author, title):
    global bookCatalog, size
    hashNumber = _hash(author)
    for a, t in bookCatalog[hashNumber]:
        if a == author and t == title:
            return True
    return False


def delete(author, title):
    global bookCatalog, bookCounter, size
    hashNumber = _hash(author)
    bucket = bookCatalog[hashNumber]
    for i, (a, t) in enumerate(bucket):
        if a == author and t == title:
            del bucket[i]
            bookCounter -= 1
            return


def findByAuthor(author):
    global bookCatalog, size
    hashNumber = _hash(author)
    return [t for a, t in bookCatalog[hashNumber] if a == author]


def _hash(s: str):
    global size
    h = 0
    for char in s:
        h = h * 43 + ord(char)
    return h % size


def isPrime(n):
    if n <= 1:
        return False
    elif n in (2, 3, 5):
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        for i in range(5, int(n ** 0.5) + 1, 2):
            if n % i == 0:
                return False
        return True


def nextPrime(n):
    if n % 2 == 0:
        n += 1
    while not isPrime(n):
        n += 2
    return n


def rehash():
    global bookCatalog, bookCounter, size
    oldCatalog = bookCatalog
    oldSize = size
    size = nextPrime(2 * size + 1)
    init()
    for bucket in oldCatalog:
        for book in bucket:
            addBook(*book)