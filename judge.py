from colorama import Fore, Style, init
init()

import subprocess
import time
import difflib
import sys

SRC = "solution.cpp"
EXEC = "./solution"

TIMEOUT = 5

GREEN = Fore.GREEN
RED = Fore.RED
YELLOW = Fore.YELLOW
CYAN = Fore.CYAN
RESET = Style.RESET_ALL


def compile_cpp():

    print("Compiling...")

    result = subprocess.run(
        ["g++", "-O2", SRC, "-o", EXEC],
        capture_output=True,
        text=True
    )

    if result.returncode != 0:
        print(RED + "Compilation Failed\n" + RESET)
        print(result.stderr)
        sys.exit(1)

    print(GREEN + "Compilation Success\n" + RESET)


def load_cases(filename):

    with open(filename) as f:
        content = f.read()

    return [c.strip() for c in content.split("###") if c.strip()]


def run_test(input_data):

    try:

        start = time.perf_counter()

        result = subprocess.run(
            EXEC,
            input=input_data,
            text=True,
            capture_output=True,
            timeout=TIMEOUT
        )

        end = time.perf_counter()

        runtime = (end - start) * 1000

        return result.stdout.strip(), runtime, False

    except subprocess.TimeoutExpired:

        return "", 0, True


def normalize(s):
    return " ".join(s.split())


def side_by_side_diff(expected, actual):

    exp_lines = expected.splitlines()
    act_lines = actual.splitlines()

    width = 40

    print(YELLOW + "\nExpected".ljust(width) + " | Actual" + RESET)
    print("-" * (width * 2))

    for e, a in zip(exp_lines + [""] * 100, act_lines + [""] * 100):

        if e == "" and a == "":
            break

        color = GREEN if e == a else RED

        print(
            color
            + e.ljust(width)
            + " | "
            + a
            + RESET
        )


def main():

    compile_cpp()

    inputs = load_cases("input.txt")
    outputs = load_cases("output.txt")

    if len(inputs) != len(outputs):
        print(RED + "Input/output case mismatch!" + RESET)
        return

    passed = 0

    for i, (inp, exp) in enumerate(zip(inputs, outputs), 1):

        actual, runtime, timeout = run_test(inp)

        print(f"Test {i}: ", end="")

        if timeout:
            print(RED + "TIMEOUT" + RESET)
            continue

        # if actual == exp:
        if normalize(actual) == normalize(exp):

            print(GREEN + f"PASS ({runtime:.2f} ms)" + RESET)
            passed += 1

        else:

            print(RED + f"FAIL ({runtime:.2f} ms)" + RESET)

            side_by_side_diff(exp, actual)

            print()

    print(CYAN + f"\nPassed {passed}/{len(inputs)} tests" + RESET)


if __name__ == "__main__":
    main()
