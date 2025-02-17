"""
Реалізуйте каталог деякої бібліотеки.
Бібліотека може містити кілька книг одного автора.
"""

EMPTY = None
DELETED = 0
size: int = 991
bookCatalog: list[tuple[str, str]]
bookCounter: int = 0


def init():
    global bookCatalog, bookCounter, size
    bookCatalog = [EMPTY] * size
    bookCounter = 0


def addBook(author, title):
    global bookCatalog, bookCounter, size

    if size * 0.65 <= bookCounter:
        rehash()

    hashNumber = _hash(author)

    while bookCatalog[hashNumber] not in [EMPTY, DELETED]:
        if bookCatalog[hashNumber] == (author, title):
            return None
        hashNumber = (hashNumber + 1) % size

    bookCatalog[hashNumber] = (author, title)
    bookCounter += 1


def find(author, title):
    global bookCatalog, bookCounter, size
    hashNumber = _hash(author)

    while bookCatalog[hashNumber] is not EMPTY:
        if bookCatalog[hashNumber] != DELETED:
            if bookCatalog[hashNumber] == (author, title):
                return True
        hashNumber = (hashNumber + 1) % size

    return False


def delete(author, title):
    global bookCatalog, bookCounter, size
    hashNumber = _hash(author)

    while bookCatalog[hashNumber] is not EMPTY:
        if bookCatalog[hashNumber] == (author, title):
            bookCatalog[hashNumber] = DELETED
            bookCounter -= 1
            return

        hashNumber = (hashNumber + 1) % size


def findByAuthor(author):
    global bookCatalog, bookCounter, size
    authorBooks = []

    hashNumber = _hash(author)

    while bookCatalog[hashNumber] is not EMPTY:
        if bookCatalog[hashNumber] != DELETED and bookCatalog[hashNumber][0] == author:
            authorBooks.append(bookCatalog[hashNumber][1])
        hashNumber = (hashNumber + 1) % size

    return authorBooks


def _hash(s: str):
    global size
    h = 0
    for i in range(len(s)):
        h = h * 43 + ord(s[i])
    return h % size


def isPrime(n):
    if n <= 1:
        return False

    elif n in [2, 3, 5]:
        return True

    elif n % 2 == 0 or n % 3 == 0:
        return False

    else:
        for i in range(5, int(n ** 0.5) + 1, 2):
            if n % i == 0:
                return False
        return True



def rehash():
    global bookCatalog, bookCounter, size
    oldSize = size
    oldCatalog = bookCatalog
    size = 2 * size + 1

    while not isPrime(size):
        size += 2

    init()

    for i in range(oldSize):
        if oldCatalog[i] not in [EMPTY, DELETED]:
            addBook(*oldCatalog[i])
