n = int(input())

hasbeentold = set()
everyone = set()
remains = []

for _ in range(n):
    decision = input()
    if "->" in decision:
        p1, p2 = decision.split(" -> ")
        hasbeentold.add(p2)
        everyone.add(p1)
        everyone.add(p2)
    else:
        remains.append(decision)

for decision in remains:
    p1, p2 = decision.split(" ?? ")

    if p1 in hasbeentold:
        hasbeentold.add(p2)

    if p2 in hasbeentold:
        hasbeentold.add(p1)

    everyone.add(p1)
    everyone.add(p2)

result = []
for p in everyone:
    if p not in hasbeentold:
        result.append(p)

result.sort()
for p in result:
    print(p)
