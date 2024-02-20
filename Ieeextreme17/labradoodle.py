# 25% score

x, y = map(int, input().split(" "))

pref = {}
suff = {}
dictionary = []


def performcomparism(leftstrip, rightstrip):
    # print(leftstrip, rightstrip)
    if leftstrip not in pref or rightstrip not in suff:
        return [False, None]

    pp = pref[leftstrip]
    qq = suff[rightstrip]

    # print(pp, qq)
    r = max(len(qq), len(pp))
    if r > 1:
        return [True, "ambiguous"]

    return [True, dictionary[pp[0]] + " " + dictionary[qq[0]]]


def prepare1(word, suffix, j):
    if len(word) < 3:
        return

    n = len(word) - 3
    t = word[n:]
    if t in suffix:
        suffix[t].append(j)
    else:
        suffix[t] = [j]

    for i in range(n - 1, -1, -1):
        t = word[i:]

        if t in suffix:
            suffix[t].append(j)
        else:
            suffix[t] = [j]


def prepare(word, prefix, j):
    if len(word) < 3:
        return

    t = word[:3]
    if t in prefix:
        prefix[t].append(j)
    else:
        prefix[t] = [j]

    for i in range(3, len(word)):
        t += word[i]

        if t in prefix:
            prefix[t].append(j)
        else:
            prefix[t] = [j]


for i in range(x):
    word = input()
    dictionary.append(word)
    prepare1(word, suff, i)
    prepare(word, pref, i)

# print(suff)
for _ in range(y):
    word = input()

    if len(word) < 5:

        print("none")

    else:

        # strip of the first 3 and the last 3
        l = 3

        keep = set()

        while l <= len(word) - 2:
            # print("adfafdsafsa")
            r = len(word) - 2

            check = False

            while r >= l:
                leftstrip = word[:l]
                rightstrip = word[r - 1:]

                # print(leftstrip, rightstrip)

                b, ind = performcomparism(leftstrip, rightstrip)
                if b:
                    if ind == "ambiguous":
                        keep.add(1)
                        keep.add(2)
                        check = True
                        break
                    else:
                        keep.add(ind)
                r -= 1

            if check:
                break
            l += 1

        if len(keep) > 1:
            print("ambiguous")
        elif len(keep) == 0:
            print("none")
        else:
            print(list(keep)[0])
