class FenwickTree:
    def __init__(self, size):
        """
        Ініціалізація дерева Фенвіка.
        size — кількість елементів у масиві.
        Використовуємо 1-based індексацію, тому внутрішній масив має розмір size+1.
        """
        self.n = size
        self.tree = [0] * (size + 1)  # tree[0] не використовується

    def update(self, i, delta):
        """
        Додає значення delta до елемента a[i] (1-based індексація).
        Кожен крок стрибаємо на i += (i & -i), щоб оновити всі «батьківські» вузли.
        """
        while i <= self.n:
            self.tree[i] += delta  # додаємо delta до поточного вузла
            i += i & -i            # переходимо до наступного покриваючого вузла

    def query(self, i):
        """
        Повертає суму елементів a[1] + ... + a[i].
        Проходимо «угору» по дереву, зменшуючи i на (i & -i).
        """
        s = 0
        while i > 0:
            s += self.tree[i]  # акумулюємо суму
            i -= i & -i        # переходимо до «батьківського» фрагмента
        return s

    def range_query(self, l, r):
        """
        Повертає суму елементів на відрізку [l..r].
        Використовує дві префіксні суми: sum(r) - sum(l-1).
        """
        return self.query(r) - self.query(l - 1)

    @classmethod
    def from_list(cls, data):
        """
        Створює дерево Фенвіка з готового списку data (0-based list).
        Проходимо по кожному значенню й викликаємо update.
        """
        n = len(data)
        ft = cls(n)
        for idx, val in enumerate(data, start=1):
            ft.update(idx, val)
        return ft


# Приклад використання
if __name__ == "__main__":
    arr = [5, 3, 7, 1, 2]
    ft = FenwickTree.from_list(arr)
    print("Сума перших 3 елементів:", ft.query(3))

    ft.update(2, 4)

    print("Сума на відрізку [2..5]:", ft.range_query(2, 5))