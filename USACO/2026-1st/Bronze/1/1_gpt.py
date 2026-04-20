import sys


def solve_case(a: int, b: int, c_a: int, c_b: int, f: int) -> int:
    a += (b // c_b) * c_a
    b %= c_b

    d = f - a
    if d <= 0:
        return 0

    if d <= c_a or c_a >= c_b:
        return c_b - b - 1 + d

    q, r = divmod(d, c_a)
    if r == 0:
        q -= 1

    return q * c_b - b + c_b - 1 + d - q * c_a


def main() -> None:
    input = sys.stdin.buffer.readline

    first_line = input().split()
    if not first_line:
        return

    t = int(first_line[0])
    if t <= 0:
        return

    answers = []

    for _ in range(t):
        a, b, c_a, c_b, f = map(int, input().split())
        answers.append(str(solve_case(a, b, c_a, c_b, f)))

    sys.stdout.write("\n".join(answers))


if __name__ == "__main__":
    main()
