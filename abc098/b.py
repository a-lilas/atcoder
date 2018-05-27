N = int(input())
S = input()
maxans = 0
for i in range(1, N):
    Xs = set([c for c in S[:i]])
    Ys = set([c for c in S[i:]])
    maxans = max(len(Xs.intersection(Ys)), maxans)

print(maxans)