#!/usr/bin/env python3

GRADE_MIN = 1
GRADE_MAX = 16
IN = 1
OUT = 0


def main():
    text = get_text("Text: ")

    l, w, s = count_lws(text)

    cli = round(0.0588 * l / w * 100 - 0.296 * s / w * 100 - 15.8)

    if cli < GRADE_MIN:
        print(f"Before Grade {GRADE_MIN}")

    elif (cli > GRADE_MAX):
        print(f"Grade {GRADE_MAX}+")

    else:
        print(f"Grade {cli}")


# Asks user for text
def get_text(prompt):
    while True:
        s = input(prompt)
        if s != "":
            return s


# Counts letters, words, and sentences in a given text
def count_lws(text):
    l = w = s = 0
    state = OUT

    for c in text:
        if c.isalpha():
            state = IN
            l += 1

        elif c.isspace():
            if state == IN:
                w += 1
                state = OUT

        elif c in ".!?":
            s += 1

    if text[-1] in ".!?":
        w += 1

    return l, w, s


# Call main()
if __name__ == "__main__":
    main()
