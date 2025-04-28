if __name__ == '__main__':
    n, m = [int(d) for d in input().split()]

    adj_matrix = [[0 for _ in range(n)] for _ in range(n)]

    for _ in range(m):
        i, j = [int(d) for d in input().split()]
        adj_matrix[i - 1][j - 1] = 1
        adj_matrix[j - 1][i - 1] = 1

    is_full = True
    for i in range(n):
        for j in range(n):
            if adj_matrix[i][j] != 1 and i != j:
                is_full = False
                break
        if not is_full:
            break

    if is_full:
        print("YES")
    else:
        print("NO")