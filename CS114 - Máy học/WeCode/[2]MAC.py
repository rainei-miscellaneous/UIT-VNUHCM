import re, sys, math

regexFind = r'([0-9A-F]{2}-){5}[0-9A-F]{2}'

def check(cond):
    print('true') if cond else print('false')

while(True):
    s = sys.stdin.readline().strip()
    if s == '.': break

    check(re.fullmatch(regexFind, s))