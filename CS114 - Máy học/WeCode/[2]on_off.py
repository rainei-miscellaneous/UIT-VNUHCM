import sys
from collections import defaultdict

status = defaultdict(int)
output = []

lines = sys.stdin.read().strip().splitlines()

for line in lines:
    if line == "0":
        break

    cmd, id = line[0], line[2:]
    
    if cmd == '1':
        status[id] = 1
    elif cmd == '2':
        output.append(str(status[id]))
    elif cmd == '3':
        status[id] = 0

if output:
    sys.stdout.write("\n".join(output) + "\n")
