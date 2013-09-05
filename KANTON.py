import sys
def r():
    try:
        s=raw_input()
    except EOFError:
        return
    r()
    print s[::-1]
r()
