while True:
    s = input().split()
    ch = s[0]
    s = s[1:]
    print(*[f"mp[\"{x}\"] =" for x in s], f"'{ch}';")
    if s[0] == ".":
        break
