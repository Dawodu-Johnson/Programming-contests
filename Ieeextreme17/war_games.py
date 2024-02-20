from collections import deque

testcase = int(input())

game = {
    "2": 1,
    "3": 2,
    "4": 3,
    "5": 4,
    "6": 5,
    "7": 6,
    "8": 7,
    "9": 8,
    "T": 9,
    "J": 10,
    "Q": 11,
    "K": 12,
    "A": 13
}


def playgame(player1cards, player2cards):
    visited = set()

    while True:

        if len(player1cards) == 0:
            return "player 2"

        if len(player2cards) == 0:
            return "player 1"

        # form both
        playstr1 = "".join(player1cards)
        playstr2 = "".join(player2cards)
        # drawize
        if (playstr1, playstr2) in visited:
            return "draw"
            # something

        if (playstr2, playstr1) in visited:
            return "draw"

        visited.add((playstr1, playstr2))
        # play side

        q1 = player1cards.popleft()
        q2 = player2cards.popleft()

        if game[q1] > game[q2]:
            player1cards.append(q2)


        elif game[q1] < game[q2]:
            player2cards.append(q1)

        else:
            player1cards.append(q1)
            player2cards.append(q2)


for _ in range(testcase):
    player1cards = deque(input().split(" "))
    player2cards = deque(input().split(" "))

    ans = playgame(player1cards, player2cards)

    print(ans)
